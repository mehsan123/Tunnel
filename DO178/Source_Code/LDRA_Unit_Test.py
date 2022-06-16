import argparse
import os
import logging
import subprocess

exit_codes = {
   0:"Success",
   64:"Invalid command line",
   65:"Input data was incorrect",
   66:"Input file does not exist or is not readable",
   70:"Internal software limitation detected",
   73:"Output file or directory not found",
   80:"Main static analysis incomplete",
   81:"Instrumentation incomplete",
   82:"Dynamic coverage analysis incomplete",
   83:"Other analysis incomplete",
   84:"Build failure due to execution of command",
   85:"Failed to execute instrumented program",
   86:"Build command returned a non-zero value",
   87:"Error in sysppvar generation phase.",
   90:"Regression Failure",
   91:"Build Failure",
   92:"Unable to execute harness program",
   103:"Licensing error"
}

def regress_tcf(tcf,testbed,workarea):
    logger.info("Regress {}".format(tcf))

    contbrun = os.path.join(testbed,"contbrun")
    cmd = [contbrun,tcf,'-tcf_mode=retain',"-unit_publish_to={}".format(workarea),"-regress","-quit"]
    #workfiledir doesnt work for some reason
    #cmd = [contbrun,tcf,'-tcf_mode=retain',"-tb_workfiledir={}".format(workarea),"-regress","-quit"]
    #contestbed = os.path.join(testbed,"contestbed")
    #cmd = [contestbed,"{}".format(tcf),"/tb_workfiledir={}".format(workarea),"-1120345q","/tbruntcf={}".format(tcf), '/tbruntcfargs="-tcf_mode=retain -regress -quit"']
    run_command(cmd)

def run_command(cmd,out=None,err=None):
    
    logger.info("Running Command: {}".format(" ".join(cmd)))

    process = subprocess.Popen(cmd,stdout=out,stderr=err)
    process.wait()
    
    success = False
    if process.returncode in exit_codes:
        if exit_codes[process.returncode] == "Success":
            success = True
            logger.info("Return {} : {}".format(process.returncode,exit_codes[process.returncode]))
        else:
            logger.error("Return {} : {}".format(process.returncode,exit_codes[process.returncode]))
    else:
        success = True
        logger.warning("Return {} : Unknown Return Code".format(process.returncode))

    return success

#verify TESTBED argument is valid
def ldra_dir(path):
    #verify the directory exists
    if not os.path.isdir(path):
        logger.error("Directory does not exits: {}".format(path))
        raise ValueError
    
    #verify the directory is a valid LDRA install
    files = ["contestbed","contbbuildimport","contbrun"]
    for file in files:
        check_file = os.path.join(path,file)
        if not os.path.exists(check_file):
            #try with a .exe extension (windows)
            if not os.path.exists("{}.{}".format(check_file,"exe")):
                logger.error("LDRA Executables not found in {}:{}".format(path,file))
                raise ValueError
    return path

#verify WORKAREA exists
def result_dir(path):
    if not os.path.exists(path):
        #create result dir if it doesnt exist
        os.makedirs(path)
    return path

def tcf_arg(arguments):
    tcf_list = []
    for file in arguments:
        if os.path.exists(file):
            tcf_list.append(file)
        else:
            logger.warning("TCF provided by --tcf does not exist: {}".format(file))
    return tcf_list

def tcf_file(file):
    tcf_list = []
    if os.path.exists(file):
        with open(file) as fp:
            for tcf in fp:
                tcf = os.path.expanduser(tcf.strip())
                if os.path.exists(tcf):
                    tcf_list.append(tcf)
                else:
                    logger.warning("TCF provided by --file does not exist: {}".format(tcf))
    else:
        logger.warning("File provided by --file does not exists: {}".format(file))

    return tcf_list
    
def tcf_dir(directory,recursive):
    tcf_list = []
    if os.path.isdir(directory):
        for root,dirs,files in os.walk(directory):
            for file in files:
                if file.endswith(("tcf","TCF")):
                    tcf_list.append(os.path.join(root,file))
            if not recursive: break
    else:
        logger.warning("Directory provided by --dir does not exist: {}".format(directory))
    
    return tcf_list

def get_tcfs(args):
    tcf_list = []

    #from tcf option
    if args.tcf:
        tcf_list.extend(tcf_arg(args.tcf))
    if args.file:
        tcf_list.extend(tcf_file(args.file))
    if args.dir:
        tcf_list.extend(tcf_dir(args.dir,args.recursive))
    
    #return, removing any duplicates
    return list(set(tcf_list))

def main():
    #setup script arguments
    parser = argparse.ArgumentParser(description="LDRA Unit Test Automation")
    parser.add_argument('TESTBED',type=ldra_dir,help="Location of Testbed")
    parser.add_argument('WORKAREA',type=result_dir,help="Location to store LDRA results")
    parser.add_argument('--tcf',help="One or more TCF files to process",nargs='+') #list of one or more tcfs
    parser.add_argument('--file',help="File containing list of TCF files to process") #file of tcfs
    parser.add_argument('--dir',help="Directory containing TCF files to process") #directory of tcfs
    parser.add_argument('-r','--recursive',help="Recurse through directory, used with --dir option",action='store_true')
    
    #parser.add_argument('-p','--profile',help="Define which profile to run - ex. red box.  Default runs what is defined in the TCF", default=None)

    args = parser.parse_args()
    tcf_list = get_tcfs(args)
    print(tcf_list)

    for tcf in tcf_list:
        regress_tcf(tcf,args.TESTBED,args.WORKAREA)

if __name__ == '__main__':
    version = 1.0
    
    #configure logging
    logger = logging.getLogger("LDRA Unit Test")
    logger.setLevel(logging.INFO)
    logging.basicConfig(format="[%(levelname)s]%(message)s")
   
    logger.info("LDRA Unit Test Utility v{}".format(version))

    main()