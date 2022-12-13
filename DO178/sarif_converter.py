import os
import fnmatch
import sys
import re
from telnetlib import COM_PORT_OPTION



####################################
class_violation_array = []
class_violation_each_array = []
allRulesArray = []
description = []

class Violation():
    def __init__(self, SourceCode, Standard, ruleNumber, description,lineNumber,violation_level,module_count):
        self.ruleNumber=ruleNumber
        self.description= description
        self.lineNumber=lineNumber
        
        self.SourceCode = SourceCode
        self.Standard = Standard
        self.violation_level= violation_level
        self.module_count = module_count
    
    def setRuleNumber(self, ruleNumber):
        print(ruleNumber)
        self.ruleNumber.append(ruleNumber)
   
    def setLineNumber(self, lineNumber):
        self.lineNumber.append(lineNumber)
        
    def setDescNumber(self,description):
        self.description.append(description)
    
    def getSourceName (self):
        return self.SourceCode
     
    def getStandardName(self):
        return self.Standard
        
    def getDescriptionName(self):
        return self.description        
    
    def getviolationLevel(self):
        return self.violation_level    
        
    def getRuleNumber (self):
        return self.ruleNumber
        
    def getlineNumber (self):
        return self.lineNumber
        
    def __str__(self):
        return (self.SourceCode, self.Standard, self.ruleNumber, self.description, self.lineNumber,self.violation_level, self.module_count)
        
    

class ViolationPerOne():
    def __init__(self, SourceCode, Standard, ruleNumber, description,lineNumber, violation_level):
        self.ruleNumber=ruleNumber
        self.description= description
        self.lineNumber=lineNumber
        
        self.SourceCode = SourceCode
        self.Standard = Standard
        self.violation_level = violation_level
    
    def setRuleNumber(self, ruleNumber):
        print(ruleNumber)
        self.ruleNumber=ruleNumber
   
    def setLineNumber(self, lineNumber):
        self.lineNumber=lineNumber
        
    def setDescNumber(self,description):
        self.description = description
    
    def getSourceName (self):
        return self.SourceCode
     
    def getStandardName(self):
        return self.Standard
        
    def getDescriptionName(self):
        return self.description        
        
    def getRuleNumber (self):
        return self.ruleNumber
        
    def getlineNumber (self):
        return self.lineNumber
    
    def getviolationLevel(self):
        return self.violation_level   

    def __str__(self):
        return (self.SourceCode, self.Standard, self.ruleNumber, self.description, self.lineNumber, self.violation_level, self.module_count)
        
    def printSourceViolation (self):
        return('Source= '+str(self.SourceCode) +'\n LDRA Violation: '+ str(self.ruleNumber)+ ' '+str(self.description) + ' at line: '+ str(self.lineNumber)) 





def init():
    global ldraFile, toolsuiteDir, standard
    toolsuiteDir = sys.argv[1]
    ldraFile = sys.argv[2]
    standard = sys.argv[3]
    
    print('LDRA File Directory is: '+ldraFile)
    print('TOOLSUITE ROOT: ROOT: '+toolsuiteDir)

    #from fourth argument locate directory for specified project
          
        
def main():
    if len(sys.argv) < 2:
        
        print('.......................................................................')
        print('Please pass the Source Directory as First Parameter ')
        print('The second parameter is the toolsuite path. contestbed and contbbuild import should be in this folder')
        print('.......................................................................')
        sys.exit(0)
        
    #run through all steps
    init()
    print("Here...")
    tbglhfile= createTbglhAPI(ldraFile)
    staticAnalyzer(tbglhfile)
    #printViolation()
    sortViolations()
    violationPerSource()
    
    print(len(allRulesArray), len(description))
    sarif_report()
    #report = analyzeViolations(tcfName)

    #static_json_creator(tcfName)
    #xmltojson (workarearoot+tcfName[:-3]+'xml',workarearoot+ tcfName[:-3]+'json')
    #junit_creator(tcfName)
    #plottyDisplay(tcfName)        
def lineTrimmer(str):
    arr = str.split('  ')
    b = []
    for a in arr:
        if a !=' ':
            if a !='':
                if '\n' in a:
                    a=a[:a.find('\n')]
                    
                    if 'Count:' in a:
                        c=a[:a.find(': ')+1]
                        d=a[a.find(': ')+2:]
                        b.append(c)
                        b.append(d)
                    else:
                        b.append(a)
                else:
                    b.append(a)
    
    return b

def createTbglhAPI(ldraFile):
    if (os.path.exists(ldraFile)):
        print('Analyzing file ',ldraFile,'for GLH API!')
        ldraPath=os.path.split(ldraFile)
    else:
        print('No LDRA File found! content= '+ldraFile)
        sys.exit()
    output_file=str(ldraPath[0])+'\\codeReview_glhapi.txt'    
    print(output_file)
    command= '{}\\tbglhapi result={} model={} flags=4 output={}'.format(toolsuiteDir, ldraFile,standard,output_file)
    os.system(command)
    print('Finished')        
    if(os.path.exists(output_file)):
        print('TBGLH API was analyzed!')
        return(output_file)
    else:
        print('TBGLH API not successful Found!')
        sys.exit()

def staticAnalyzer(tbglhfile):
    print('Static analysis started...')
    file=open(tbglhfile, 'r')
    flag_source=0
    for f in file:
        trimmed_line = lineTrimmer(f)
        if trimmed_line != None:
            if ('------ Standards violated in file:' in trimmed_line):
                    flag_source=1
                    source = ""
                    rule_number=[]
                    violation_description=[]
                    source_line_number = []
                    violation_level = []
                    module_count = ""
            if len(trimmed_line)>1:        
                if ('\\' in trimmed_line[1] or '//' in trimmed_line and flag_source==1):
                    if ('.ini' not in trimmed_line[1]):
                        source = trimmed_line[1]

            if ('LDRA Rule Number:' in trimmed_line and flag_source==1):
                rule_number.append( trimmed_line[1])

            if ('Rule Description:' in trimmed_line and flag_source==1):
                violation_description .append(trimmed_line[1])

            if ('Source Line Number:' in trimmed_line and flag_source==1):
                if int(trimmed_line[1])==0:
                    print(trimmed_line[1])
                    print('********')
                    source_line_number .append('1')
                else:
                    source_line_number.append(trimmed_line[1])

            if ('Penalty Category Level:'in trimmed_line and flag_source==1):
                if trimmed_line[1] == 'Mandatory': 
                    violation_level.append('error') 
                if trimmed_line[1] == 'Conditional':
                    violation_level.append('warning')
                if trimmed_line[1] == 'Optional':
                    violation_level.append('note')
                if trimmed_line[1] == 'Informational':
                    violation_level.append('none')
                if trimmed_line[1] == 'Checking':
                    violation_level.append('note')
                print(trimmed_line[1])
                
            if ('Exclusions' in trimmed_line):
                    flag_source =0

            if('------ Module Violation Count:' in trimmed_line and flag_source==1):
                module_count = trimmed_line[1]
                class_violation_array.append(Violation(source, standard, rule_number, violation_description, source_line_number, violation_level,module_count ))

def creport_parser(creportFile, standard):
    creport = open(creportFile,'r')
    flag1 = 0
    flag2 = 0
    allRulesArray = []
    ruleType = []
    description = []
    for eachline in creport:
            temp = eachline.split(' ')
            for i in temp:
                if i == ' ' or i == '':
                    temp.remove(i)
            content = temp
            if "'S' phase standards" in eachline:
                flag1 =1 
                
            if flag1 ==1:
                

                if eachline.find(standard) !=-1:
                    flag2 = 1  
                    
                    if content[0] !='':     
                        allRulesArray.append(content[0]+' '+content[1])
                        ruleType.append(content[2])
                    else:
                       allRulesArray.append(content[1]+' '+content[2])  
                       ruleType.append(content[3])           
                if ('#' in eachline and flag2 ==1):
                    flag2=0
                    desc = ''
                    for i in range (1, len(content)-1):
                        #removing " from the string
                        if '"' in content[i]:
                            content[i]= content[i].replace('"', ' ')

                        desc= desc + content[i]+ ' '
                        
                    description.append(desc)
    for each in ruleType:
        if each == 'M': 
            ruleType[ruleType.index(each)] = 'error'
        if each == 'C':
            ruleType[ruleType.index(each)] = 'warning'
        if each == 'O':
            ruleType[ruleType.index(each)] = 'note'
        if each == 'I':
            ruleType[ruleType.index(each)] = 'none'
        


    return(allRulesArray, description, ruleType)

def printViolation():
    for each in class_violation_array:
        print(each.printSourceViolation())

def violationPerSource():
    source = []
    violationID= []
    violationDescription= []
    violationLineNumber= []
    

    for each in class_violation_array:
        eachSource = each.getSourceName()
        eachViolations = each.getRuleNumber()
        eachSescription = each.getDescriptionName()
        eachLineNumber = each.getlineNumber()
        eachstandard = each.getStandardName()
        eachviolation_level = each.getviolationLevel()
        for i in range (0,len(eachViolations)):
            class_violation_each_array.append(ViolationPerOne(eachSource, eachstandard, eachViolations[i], eachSescription[i], eachLineNumber[i], eachviolation_level[i]))

    print('Printing each vilation in the code .....')
    for i in class_violation_each_array:

        print(i.printSourceViolation())
        print (len(class_violation_each_array))
    print('.........................................')


def sortViolations():
    violation_number = []
    violation_description = []
    count_violation_number = []
    temp_rule=[]
    temp_count=[]
    dict={}
    for each in class_violation_array:
         violation_number_per_source = each.getRuleNumber()
         violation_desc_per_source = each.getDescriptionName()
         for x in violation_number_per_source:
            violation_number.append(x)
            violation_description.append(violation_desc_per_source[violation_number_per_source.index(x)])
    for i in violation_number:
        if i not in temp_rule:
            temp_rule.append(i)
            temp_count.append(violation_number.count(i))
    for each in temp_rule:
        dict[each]=temp_count[temp_rule.index(each)]
    print(temp_rule)
    print(temp_count)
    print(dict)
    dict = sorted(dict.items(), key=lambda kv: kv[1],reverse = True)
    print(dict)
    return (dict)        

def sarif_report():
    [allRulesArray, description, ruleType]=creport_parser(toolsuiteDir+'\\C\\creport.dat', standard)
    uri = []
    for each in class_violation_array:

        rule_number = each.getRuleNumber()
        source = each.getSourceName()
        source.replace(':\\' , '://')
        source.replace('\\','//')
        source = "file:///"+source
        uri .append( source)
        helpUri = toolsuiteDir.replace(':\\','://')
        helpUri = toolsuiteDir.replace('\\','//')
        
        if ".cpp" in source:
            file_type="CPP "
        else:
            file_type ="C"
        helpUri = "file:///"+helpUri+"Standards_info//Html//"+file_type+"//Standards.htm"
    s= open(ldraFile[:-4]+'.sarif', 'w')
    s.write('{\n')
    s.write('  "version":"2.1.0",\n')
    s.write(' "$schema": "http://json.schemastore.org/sarif-2.1.0-rtm.4",\n')
    s.write('  "runs": [\n')
    s.write('    {\n')
    s.write('      "tool": {\n')
    s.write('        "driver": {\n')
    s.write('          "name": "LDRA",\n')
    s.write('          "version": "10",\n')
    s.write('          "informationUri": "https://www.ldra.com",\n')
    s.write('          "rules": [\n')
    s.write('            ]\n')
    s.write('          }\n')
    s.write('        },\n')
    s.write('      "artifacts": [\n')
      
    for i in range (0 , len(uri)):
        s.write('          {\n') 
        s.write('            "location": {\n')
        uri[i]=uri[i].replace('\\' , '/')
        s.write('              "uri": "' + uri[i] +'"\n')
        
        s.write('                        },\n')
        s.write('              "sourceLanguage":"'+ uri[i][uri[i].find('.c')+1:]+'"\n')
        if (i == (len(uri)-1)):
            s.write('          }\n')
        else:
            s.write('          },\n')
            
    s.write('        ],\n')
    s.write('        "results": [\n')
    count =0
    for each in class_violation_each_array:
        count = count +1
        s.write('        {\n')
        s.write('          "level": "' +each.getviolationLevel()+'",\n')
        s.write('          "message": {\n')
        s.write('            "text": "' +each.getDescriptionName()+'"\n')
        s.write('          },\n')
        s.write('          "locations": [\n')
        s.write('            {\n')
        s.write('              "physicalLocation": {\n')
        s.write('                "artifactLocation": {\n')
        sourceName= each.getSourceName()
        sourceName = sourceName.replace('\\','/')
        s.write('                  "uri": "file://'+sourceName+'",\n')
        s.write('                  "index":0\n')
        s.write('                },\n')
        s.write('                "region": {\n')
        s.write('                  "startLine": '+each.getlineNumber()+',\n')
        s.write('                  "startColumn": 1\n')
        s.write('                }\n')
        s.write('              }\n')
        s.write('            }\n')
        s.write('          ],\n')
        s.write('          "ruleId": "'+each.getRuleNumber()+'",\n')
        s.write('          "ruleIndex": 0\n')

        if (count == len(class_violation_each_array)):
            s.write('        }\n')
        else :
            s.write('        },\n')
    s.write('      ]\n')
    s.write('    }\n')
    s.write('  ]\n')
    s.write('}\n')
if __name__ == "__main__":
    main()
