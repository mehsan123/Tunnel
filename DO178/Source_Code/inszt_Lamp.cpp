/*
C++ TESTBED VERSION  : 9.8.6
FILE UNDER TEST  : "C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Lamp.cpp"
DATE OF ANALYSIS : Wed May 26 15:21:03 2021
*/
 
/************************************************************************************************************
Lamp.cpp
v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
#include <iostream>
#define QQQdialect GCC                                                                                                                                                                                                               
#undef QQQ146
#undef QQQ148
#undef QQQbndchk
#define QQQ294
#undef QQQEMBEDDEDICE
 /* Note: for BITMAP execution histories QQQthreaded is not defined */
#undef QQQthreaded 
#undef QQQdo178b
#undef QQQfixbra
#undef QQQswitch3
#undef QQQternary
#undef QQQswitch
#undef QQQmacrof
#undef QQQMULTIPROCESSEXH
#undef QQFLUSH
#undef QQNEWBS
#define qqqMaxBranchDepth      2
#undef QQQstructbitmap
 static int zzfileid =      8;
#undef QQQALGONE
#undef QQQVCLFLG
#undef QQQFORKFL
#undef QQQIADDRF
#undef QQQRTI
#undef QQQPERFA
#undef QQQADRMOD
#undef QQQDCAPFL
#undef QQQTEMPLATEONLY
#undef QQQNOATEXIT
#undef QQQUPLOADATEND
#undef QQQNOSTDIO
#undef QQQASHLINGVITRA
#undef QQQBITMAPMCDC 
#undef QQQTIC2XSERIALIO
#undef QQQTIC2XFLASH
#undef QQQCOMPRESSED_EXH
#undef QQQMAINFL
#undef QQQSINGLEFILE
#undef QQQFILEID
#undef QQQseparate
 static int Lamp_8zzopen                                                                                         = 0;
#ifndef QQQLDRA_PORT                                                                                                                                                                                                                                                
#define FILEPOINT FILE * f,                                                                                                                                                                                                                                         
#if !defined(QQQTEMPLATEONLY) && !defined(FILE) && !defined(QQQNOSTDIO)                                                                                                                                                                                             
#include <stdio.h>                                                                                                                                                                                                                                                  
    /* ----------------------------------------------------------------------* 100 *                                                                                                                                                                                
     * If stdio.h is not available then insert:                                                                                                                                                                                                                     
     *      typedef int * FILE;                                                                                                                                                                                                                                     
     * -----------------------------------------------------------------------------                                                                                                                                                                                
     */                                                                                                                                                                                                                                                             
#endif  /* !(QQQTEMPLATEONLY) && !(FILE) && !(QQQNOSTDIO) */                                                                                                                                                                                                        
#else  /* QQQLDRA_PORT */                                                                                                                                                                                                                                           
#define FILEPOINT                                                                                                                                                                                                                                                   
#include "ldra_port.h"        /* Generic header file for LDRA_PORT */                                                                                                                                                                                               
#ifdef inc_ldra_port_instr                                                                                                                                                                                                                                          
#include "ldra_port_instr.h"  /* Communication definitions and ldra_port common code */                                                                                                                                                                             
#endif  /* inc_ldra_port_instr */                                                                                                                                                                                                                                   
#endif /* QQQLDRA_PORT */                                                                                                                                                                                                                                           
#ifndef QQQnumfil                                                                                                                                                                                                                                                   
#define QQQnumfil 40  /* default setting */                                                                                                                                                                                                                         
#endif  /* QQQnumfil */                                                                                                                                                                                                                                             
#if defined(QQQstructbitmap) && defined(QQQSINGLEFILE)                                                                                                                                                                                                              
      typedef void(*ldra_void_function)();                                                                                                                                                                                                                          
#if defined(QQQMAINFL)                                                                                                                                                                                                                                              
        /* Set qqqshell_upload to 1 if you want to call the qqqtotalupload separately. Although                                                                                                                                                                     
           through the target you would have to set this to 0 before calling the qqqupload.                                                                                                                                                                         
           Move this into ldra_port mechanism. */                                                                                                                                                                                                                   
       int qqqshell_upload = 0;                                                                                                                                                                                                                                     
       int QQQfcn_ptr_num = 0;                                                                                                                                                                                                                                      
       static int qqqisinitialised = 0;                                                                                                                                                                                                                             
       ldra_void_function qqqaccumupload[QQQnumfil];                                                                                                                                                                                                                
       ldra_void_function qqqaccumreset[QQQnumfil];                                                                                                                                                                                                                 
       void qqqtotalupload(void);                                                                                                                                                                                                                                   
       void qqqtotalreset(void);                                                                                                                                                                                                                                    
       void qqpopulate_array_fcn_ptrQQ(int x, ldra_void_function y, ldra_void_function z)                                                                                                                                                                           
       {                                                                                                                                                                                                                                                            
         qqqaccumupload[x]=y;                                                                                                                                                                                                                                       
         qqqaccumreset[x]=z;                                                                                                                                                                                                                                        
         QQQfcn_ptr_num++;                                                                                                                                                                                                                                          
       }                                                                                                                                                                                                                                                            
#else  /* (QQQMAINFL) */                                                                                                                                                                                                                                            
        extern int QQQfcn_ptr_num;                                                                                                                                                                                                                                  
        extern ldra_void_function qqqaccumupload[QQQnumfil];                                                                                                                                                                                                        
        extern void qqpopulate_array_fcn_ptrQQ(int x, ldra_void_function y, ldra_void_function z);                                                                                                                                                                  
        static int qqqstructzzopen = 0;                                                                                                                                                                                                                             
#endif  /* defined(QQQMAINFL) */                                                                                                                                                                                                                                    
#endif  /* defined(QQQstructbitmap) && defined(QQQSINGLEFILE) */                                                                                                                                                                                                    
#ifdef QQQ_KEEPCOMMENTS                                                                                                                                                                                                                                             
  /* -----------------------------------------------------------------------* 101 *                                                                                                                                                                                 
  *            Special settings for systems lacking standard functions.                                                                                                                                                                                             
  * To include code for fprintf define ldra_fprintf                                                                                                                                                                                                                 
  * To include code for sscanf  define ldra_sscanf                                                                                                                                                                                                                  
  * -----------------------------------------------------------------------------                                                                                                                                                                                   
  */                                                                                                                                                                                                                                                                
#endif  /* QQQ_KEEPCOMMENTS */                                                                                                                                                                                                                                      
#if !defined(QQQSUPPRESS_UNDEF)                                                                                                                                                                                                                                     
#undef ldra_fprintf                                                                                                                                                                                                                                                 
#undef ldra_sscanf                                                                                                                                                                                                                                                  
#endif  /* !defined(QQQSUPPRESS_UNDEF) */                                                                                                                                                                                                                           
  /*  #define ldra_fprintf */                                                                                                                                                                                                                                       
  /*  #define ldra_sscanf */                                                                                                                                                                                                                                        
#undef QQQHITMAP_STORAGE                                                                                                                                                                                                                                            
#undef qqnull_params                                                                                                                                                                                                                                                
#define qqnull_params void                                                                                                                                                                                                                                          
#define QQQ_PROTOTYPE_DEF                                                                                                                                                                                                                                           
  /* Conventional Instrumentation */                                                                                                                                                                                                                                
#undef QQ_ANSI_PROTOTYPE                                                                                                                                                                                                                                            
#define QQ_ANSI_PROTOTYPE 1                                                                                                                                                                                                                                         
    static int qqxxswitch = 0;                                                                                                                                                                                                                                      
    static int qqyyswitch = 0;                                                                                                                                                                                                                                      
  static void qqoutput(FILEPOINT char * s,int i);                                                                                                                                                                                                                   
  static void qqoutput0(FILEPOINT char * s);                                                                                                                                                                                                                        
    static int qqswitchxx(qqnull_params);                                                                                                                                                                                                                           
    static int qqswitchyy(qqnull_params);                                                                                                                                                                                                                           
    static int uuswitchqq(qqnull_params);                                                                                                                                                                                                                           
  static int Lamp_8zqqzqz(qqnull_params);                                                                                                                                                                                                                           
  static int Lamp_8zqqzqz1(qqnull_params);                                                                                                                                                                                                                          
  static int Lamp_8zzqqzz (int qqqi);                                                                                                                                                                                                                               
  static int Lamp_8zqzqzq (int qqqi);                                                                                                                                                                                                                               
  static int Lamp_8zzzqtz (int qqqa, int qqqb);                                                                                                                                                                                                                     
  static int Lamp_8zzzqfz (int qqqa, int qqqb);                                                                                                                                                                                                                     
/* ------------------------------ END OF TESTBED PROTOTYPES -------------------------------- */                                                                                                                                                                     
using std :: cout ;
/* OPEN FILE C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Config.h */
/************************************************************************************************************
Config.h
v1.0 Original 23/10/07 Bill Cody
*************************************************************************************************************/
//types
 
typedef
signed int
  Sint_32 ;
 
typedef
double
  Float_64 ;
 
typedef
bool
  Bool ;
 
typedef
char
  Char ;
//Latter day #defines
 
static const Sint_32
  NumZones = 5 ;
 
static const Sint_32
  NumZoneParams = 11 ;
 
static const Sint_32
  NumSystemParams = 9 ;
 
static const Sint_32
  NumLampTypes = 2 ;
 
static const Sint_32
  LampsPerLuminaire = 4 ;
 
static const Sint_32
  MaxCellsPerZone = 100 ;
 
static const Sint_32
  MaxLuminairesPerCell = 3 ;
 
static const Sint_32
  IDOffset = 100 ;
 
static const double
  MinLampOutput = 0.2 ;
 
static const double
  Small = 0.000001 ;
 
enum LampTypeID
{
  Brightest ,
  Dimmest
} ;
/*   CLOSE_FILE Include File */
/* OPEN FILE C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Lampmodel.h */
/************************************************************************************************************
LampModel.h
v1.0 Original - Provides for different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
namespace TunnelData {
 
typedef
  enum
  {
    LightSolo ,
    Announcer ,
    Guide ,
    Duo
  } model ;
 


class ldra_class_8000030000{ public:  /* 76 */
 ldra_class_8000030000(){ };
 ldra_class_8000030000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Lamp_8zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Lamp_8zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class LampAttributes
        :public ldra_class_8000030000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_8;
#endif
  public :
  LampAttributes ( int h , int w , model m ) ;
  int Height () ;
  int Width () ;
  int Drain () ;
  private :
  int Area () ;
  int height ;
  int width ;
  model ThisModel ;
} ;
 


class ldra_class_8000040000{ public:  /* 76 */
 ldra_class_8000040000(){ };
 ldra_class_8000040000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Lamp_8zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Lamp_8zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class SquareLamp :
        public ldra_class_8000040000, /* 69 */
public LampAttributes
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_8;
#endif
  public :
  SquareLamp ( int l , model ThisModel ) ;
} ;
}
/*   CLOSE_FILE Include File */
/* OPEN FILE C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Lamp.h */
/************************************************************************************************************
Lamp.h
v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
namespace TunnelData {
 


class ldra_class_8000050000{ public:  /* 76 */
 ldra_class_8000050000(){ };
 ldra_class_8000050000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Lamp_8zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Lamp_8zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class Lamp
        :public ldra_class_8000050000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_8;
#endif
  public :
        //Constructors
  Lamp ( void ) ;
         //Accessors
  void InitialiseLamp ( const LampTypeID ThisLampTypeID , const Sint_32 UniqueLampID , const model LampModelID ) ;
  Float_64 GetMaximumLumens ( void ) const ;
  Float_64 GetMinimumLumens ( void ) const ;
         //Others
  void SetLumensOutput ( Float_64 LumensRequired ) ;
  private :
  void SendPowerToLamp ( Sint_32 PowerSetting ) const ;
  LampTypeID mThisLampTypeID ;
  Sint_32 mUniqueLampID ;
  model mLampModel ;
} ;
}
/*   CLOSE_FILE Include File */
/* OPEN FILE C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Lamptype.h */
/************************************************************************************************************
LampType.h
v1.0 Original 23/10/07 Bill Cody
*************************************************************************************************************/
namespace TunnelData {
 


class ldra_class_8000060000{ public:  /* 76 */
 ldra_class_8000060000(){ };
 ldra_class_8000060000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Lamp_8zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Lamp_8zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class LampType
        :public ldra_class_8000060000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_8;
#endif
  public :
        //Constructors
  LampType ( void ) ;
         //Accessors
  void InitialiseLampType ( const Float_64 HighestPercentOutput , const Float_64 LowestPercentOutput , const Sint_32 MaximumPower ) ;
  Float_64 GetMaximumLumens ( void ) const ;
  Float_64 GetMinimumLumens ( void ) const ;
         //Others
  Sint_32 GetPowerRequired ( Float_64 LumensRequired ) const ;
  private :
  Sint_32 mMaximumPower ;
  Float_64 mMaximumLumens ;
  Sint_32 mMinimumPower ;
  Float_64 mMinimumLumens ;
} ;
}
/*   CLOSE_FILE Include File */
/* OPEN FILE C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Systemdata.h */
/************************************************************************************************************
SystemData.h
v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
namespace TunnelData {
 


class ldra_class_8000070000{ public:  /* 76 */
 ldra_class_8000070000(){ };
 ldra_class_8000070000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Lamp_8zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Lamp_8zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class SystemData
        :public ldra_class_8000070000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_8;
#endif
  public :
  Sint_32 mDaysBetweenCleaning ;
  Sint_32 mSoiledEfficiency ;
  Sint_32 mHighestPercentOutput ;
  Sint_32 mLowestPercentOutput ;
  Sint_32 mDaysSinceCleaning ;
  Sint_32 mExitSignSpacing ;
  Sint_32 mSirenSpacing ;
  Float_64 mEmergencyLampLumens ;
  Sint_32 mLampTypeWatts [ NumLampTypes ] ;
  LampType mTheLampType [ NumLampTypes ] ;
         //Singleton accessor
  static SystemData * Instance () ;
         //Accessors
  void InitialiseParams ( Sint_32 * pSystemDataArray ) ;
  Float_64 GetSoilingFactor ( void ) const ;
  Sint_32 GetLampPowerRequired ( LampTypeID ThisLampTypeID , Float_64 LumensRequired ) const ;
  Float_64 GetLampMaximumLumens ( LampTypeID ThisLampTypeID ) const ;
  Float_64 GetLampMinimumLumens ( LampTypeID ThisLampTypeID ) const ;
  Float_64 GetEmergencyLampLumens ( void ) const ;
  Sint_32 GetDaysBetweenCleaning ( void ) const ;
  Sint_32 GetExitSignSpacing ( void ) const ;
  Sint_32 GetSirenSpacing ( void ) const ;
  void SetDaysSinceCleaning ( Sint_32 Days ) ;
  private :
  SystemData () ;
 
  SystemData ( const SystemData & ) :
    ldra_class_8000070000(),  /* 71 c1*/
  mTheLampType ( )
  {
   int iLamp_8zzqqzz                                                                                        
 = Lamp_8zzqqzz                                                                                         (       1 ) ; /* 37 */
    Lamp_8zzqqzz                                                                                         (       2 ) ; /* 30 */  
  }                                        //No copy
 
  void
  operator = ( const SystemData & )
  {
   int iLamp_8zzqqzz                                                                                        
 = Lamp_8zzqqzz                                                                                         (       3 ) ; /* 37 */
    Lamp_8zzqqzz                                                                                         (       4 ) ; /* 30 */  
  }                                            //No copy
} ;
}
/*   CLOSE_FILE Include File */
namespace TunnelData {
 
  Lamp::Lamp ( void )
  :   ldra_class_8000050000()   /* 71 b1*/
  {
   int iLamp_8zzqqzz                                                                                        
 = Lamp_8zzqqzz                                                                                         (       5 ) ; /* 37 */
    mUniqueLampID = 0 ;
    mThisLampTypeID = Brightest ;
    Lamp_8zzqqzz                                                                                         (       6 ) ; /* 30 */  
  } ;
 
void
  Lamp::InitialiseLamp (
  const LampTypeID ThisLampTypeID ,
  const Sint_32 UniqueLampID ,
  const model LampModelID )
        /* Initialise member variables */
  {
   int iLamp_8zzqqzz                                                                                        
 = Lamp_8zzqqzz                                                                                         (       7 ) ; /* 37 */
    mThisLampTypeID = ThisLampTypeID ;
    mUniqueLampID = UniqueLampID ;
    mLampModel = LampModelID ;
    Lamp_8zzqqzz                                                                                         (       8 ) ; /* 30 */  
  } ;
 
void
  Lamp::SetLumensOutput (
  Float_64 LumensRequired )
        /* Assigns the lumens required to the appropriate lamp, and converts to power output */
  {
   int iLamp_8zzqqzz                                                                                        
 = Lamp_8zzqqzz                                                                                         (       9 ) ; /* 37 */
    if
      (
      LumensRequired > 0
      )
 {
      {
          //0 power output not shown to make text manageable
        cout << " Lumens: " << LumensRequired ;
      }
 }                                                                                                   
else                                                                                                
  Lamp_8zzqqzz                                                                                         (     10 ) ; /* 4 */
 Lamp_8zzqqzz                                                                                         (      11 ) ; /* 23 */
 
    SendPowerToLamp (
    SystemData::Instance () ->
                               GetLampPowerRequired (
    mThisLampTypeID , LumensRequired ) ) ;
    Lamp_8zzqqzz                                                                                         (      12 ) ; /* 30 */  
  } ;
 
Float_64
  Lamp::GetMaximumLumens ( void ) const
        /* Retrieve maximum lumens from system parameters */
  {
typedef Float_64  zzqtype;
   int iLamp_8zzqqzz                                                                                        
 = Lamp_8zzqqzz                                                                                         (      13 ) ; /* 37 */
 qqswitchyy();
   zzqtype  Lamp_8izzzqq =
    ( SystemData::Instance () ->
                                 GetLampMaximumLumens (
    mThisLampTypeID )
    ) ;
 
 qqswitchyy();
    Lamp_8zzqqzz                                                                                         (      14 ) ; /* 30 */  
    ;
return ( Lamp_8izzzqq );
  } ;
 
Float_64
  Lamp::GetMinimumLumens ( void ) const
        /* Retrieve minimum lumens from system parameters */
  {
typedef Float_64  zzqtype;
   int iLamp_8zzqqzz                                                                                        
 = Lamp_8zzqqzz                                                                                         (      15 ) ; /* 37 */
 qqswitchyy();
   zzqtype  Lamp_8izzzqq =
    ( SystemData::Instance () ->
                                 GetLampMinimumLumens (
    mThisLampTypeID )
    ) ;
 
 qqswitchyy();
    Lamp_8zzqqzz                                                                                         (      16 ) ; /* 30 */  
    ;
return ( Lamp_8izzzqq );
  } ;
 
void
  Lamp::SendPowerToLamp (
  const Sint_32 PowerSetting ) const
        /* Interface to hardware */
  {
   int iLamp_8zzqqzz                                                                                        
 = Lamp_8zzqqzz                                                                                         (      17 ) ; /* 37 */
         //Replace this code with the output to the hardware. .
    if
      (
      PowerSetting > 0
      )
 {
      {
          //0 power output not shown to make text manageable
        cout << " Power Setting: " << PowerSetting << " for lamp ID: " << mUniqueLampID << "\n" ;
      }
 }                                                                                                   
else                                                                                                
  Lamp_8zzqqzz                                                                                         (     18 ) ; /* 4 */
    Lamp_8zzqqzz                                                                                         (      19 ) ; /* 30 */  
  } ;
}
#define qqqbranches     19
#define QQQMAXMCDCSIZE      2
 static FILE * Lamp_8zzhfil                                                                                         ;
  /* put in undefs to protect our parameter names from macros */                                                                                                                                                                                                    
#undef f                                                                                                                                                                                                                                                            
#undef i                                                                                                                                                                                                                                                            
#undef j                                                                                                                                                                                                                                                            
#undef k                                                                                                                                                                                                                                                            
#undef s                                                                                                                                                                                                                                                            
#undef l                                                                                                                                                                                                                                                            
#undef ii                                                                                                                                                                                                                                                           
#undef some                                                                                                                                                                                                                                                         
#undef none                                                                                                                                                                                                                                                         
#undef from                                                                                                                                                                                                                                                         
#undef a                                                                                                                                                                                                                                                            
#undef b                                                                                                                                                                                                                                                            
#undef iz                                                                                                                                                                                                                                                           
#undef jz                                                                                                                                                                                                                                                           
#undef qqnull_params                                                                                                                                                                                                                                                
#define qqnull_params void                                                                                                                                                                                                                                          
  /* Conventional Instrumentation */                                                                                                                                                                                                                                
    /* not single file and not fileid */                                                                                                                                                                                                                            
    static char qqqqone[]   = "%6d\n";           /* single point */                                                                                                                                                                                                 
  /* uncompressed data structures */                                                                                                                                                                                                                                
  static int Lamp_8zqqzqz(qqnull_params);                                                                                                                                                                                                                           
  static int Lamp_8zqqzqz1(qqnull_params);                                                                                                                                                                                                                          
    /* ----------------------------------------------------------------------* 200 *                                                                                                                                                                                
     *            Procedures                                                                                                                                                                                                                                        
     * -----------------------------------------------------------------------------                                                                                                                                                                                
     */                                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 202 *                                                                                                                                                                                  
   *            qqswitchgetxx                                                                                                                                                                                                                                       
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
    static int qqswitchgetxx(qqnull_params)                                                                                                                                                                                                                         
    {                                                                                                                                                                                                                                                               
      int ret = 0;                                                                                                                                                                                                                                                  
    ret = qqxxswitch;                                                                                                                                                                                                                                               
    return ret;                                                                                                                                                                                                                                                     
    }                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 203 *                                                                                                                                                                                  
   *            qqswitchgetyy                                                                                                                                                                                                                                       
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
    static int qqswitchgetyy(qqnull_params)                                                                                                                                                                                                                         
    {                                                                                                                                                                                                                                                               
      int ret = 0;                                                                                                                                                                                                                                                  
    ret = qqyyswitch;                                                                                                                                                                                                                                               
    return ret;                                                                                                                                                                                                                                                     
    }                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 204 *                                                                                                                                                                                  
     *            qqswitchxx                                                                                                                                                                                                                                        
     * -----------------------------------------------------------------------------                                                                                                                                                                                
     */                                                                                                                                                                                                                                                             
    static int qqswitchxx(qqnull_params)                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
    if ( qqxxswitch == 0 )                                                                                                                                                                                                                                          
    {                                                                                                                                                                                                                                                               
      qqxxswitch = 1;                                                                                                                                                                                                                                               
    }                                                                                                                                                                                                                                                               
    else                                                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
      qqxxswitch = 0;                                                                                                                                                                                                                                               
    }                                                                                                                                                                                                                                                               
      return 1;                                                                                                                                                                                                                                                     
    } /* end of qqswitchxx */                                                                                                                                                                                                                                       
  /* ----------------------------------------------------------------------* 205 *                                                                                                                                                                                  
     *            qqswitchyy                                                                                                                                                                                                                                        
     * -----------------------------------------------------------------------------                                                                                                                                                                                
     */                                                                                                                                                                                                                                                             
    static int qqswitchyy(qqnull_params)                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
    if ( qqyyswitch == 0 )                                                                                                                                                                                                                                          
    {                                                                                                                                                                                                                                                               
      qqyyswitch = 1;                                                                                                                                                                                                                                               
    }                                                                                                                                                                                                                                                               
    else                                                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
      qqyyswitch = 0;                                                                                                                                                                                                                                               
    }                                                                                                                                                                                                                                                               
      return 1;                                                                                                                                                                                                                                                     
    } /* end of qqswitchyy */                                                                                                                                                                                                                                       
  /* ----------------------------------------------------------------------* 206 *                                                                                                                                                                                  
     *            uuswitchqq                                                                                                                                                                                                                                        
     * -----------------------------------------------------------------------------                                                                                                                                                                                
     */                                                                                                                                                                                                                                                             
    static int uuswitchqq(qqnull_params)                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
    if ( qqyyswitch == 1 && qqxxswitch == 0 )                                                                                                                                                                                                                       
    {                                                                                                                                                                                                                                                               
      qqxxswitch = 1;                                                                                                                                                                                                                                               
    }                                                                                                                                                                                                                                                               
    else if ( qqyyswitch == 1 && qqxxswitch == 1 )                                                                                                                                                                                                                  
    {                                                                                                                                                                                                                                                               
      qqxxswitch = 0;                                                                                                                                                                                                                                               
    }                                                                                                                                                                                                                                                               
      return 1;                                                                                                                                                                                                                                                     
    } /* end of uuswitchqq */                                                                                                                                                                                                                                       
  /* ----------------------------------------------------------------------* 210 *                                                                                                                                                                                  
   *    C System utilities in use:                                                                                                                                                                                                                                  
   *        fprintf                                                                                                                                                                                                                                                 
   *        fclose                                                                                                                                                                                                                                                  
   *        sscanf                                                                                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 213 *                                                                                                                                                                                  
   *            qqoutput* suite                                                                                                                                                                                                                                     
   *      Main output routines. These may require modification.                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 214 *                                                                                                                                                                                  
   *            qqoutput                                                                                                                                                                                                                                            
   *    This is the principle output routine.                                                                                                                                                                                                                       
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
    static void qqoutput(FILEPOINT char * s,int i)                                                                                                                                                                                                                  
  /* f - file pointer, s - format string, i - integer for probe value */                                                                                                                                                                                            
  {                                                                                                                                                                                                                                                                 
    /* printing to a file */                                                                                                                                                                                                                                        
    /* fprintf exists, not threaded */                                                                                                                                                                                                                              
      /* fprintf exists,not threaded, (not SINGLEFILE and not FILEID ) */                                                                                                                                                                                           
      /* fprintf exists,not threaded, (not SINGLEFILE and not FILEID ) and not forkfl  */                                                                                                                                                                           
      fprintf(f,s,i);                                                                                                                                                                                                                                               
  } /* end of qqoutput */                                                                                                                                                                                                                                           
    /* ----------------------------------------------------------------------* 215 *                                                                                                                                                                                
     *            qqoutput0                                                                                                                                                                                                                                         
     * -----------------------------------------------------------------------------                                                                                                                                                                                
     */                                                                                                                                                                                                                                                             
    static void qqoutput0(FILEPOINT char * s)                                                                                                                                                                                                                       
    {                                                                                                                                                                                                                                                               
      fprintf(f,s);                                                                                                                                                                                                                                                 
    } /* end of qqoutput0 */                                                                                                                                                                                                                                        
  /* ----------------------------------------------------------------------* 219 *                                                                                                                                                                                  
   *            end of qqoutput* suite                                                                                                                                                                                                                              
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
#undef QQQTEMP1                                                                                                                                                                                                                                                     
#define QQQTEMP1                                                                                                                                                                                                                                                    
  /* ----------- zqqzqz ---------------------------------------------------* 310 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 312 *                                                                                                                                                                                  
   * This routine opens the execution history file. It is instrumented at the                                                                                                                                                                                       
   * start of the main program if one exists in the file. In general this is                                                                                                                                                                                        
   * superceded by Lamp_8zqqzqz1 below.                                                                                                                                                                                                                             
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Lamp_8zqqzqz(qqnull_params)                                                                                                                                                                                                                            
  {                                                                                                                                                                                                                                                                 
    if ( Lamp_8zzopen != 1 )                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
#undef QQQMUSTOPEN                                                                                                                                                                                                                                                  
      Lamp_8zzopen = 1;                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  }  /* end of zqqzqz */                                                                                                                                                                                                                                            
  /* ----------- zqqzqz1 --------------------------------------------------* 315 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 317 *                                                                                                                                                                                  
   * This routine also opens the execution history file.  It is called                                                                                                                                                                                              
   * automatically if a probe fires and the execution history is not already                                                                                                                                                                                        
   * opened (Lamp_8zzopen = 0 ).                                                                                                                                                                                                                                    
   * Because this always works ( it was intended for files with no main program                                                                                                                                                                                     
   * it is now the de facto common way to open the execution history.                                                                                                                                                                                               
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Lamp_8zqqzqz1(qqnull_params)                                                                                                                                                                                                                           
  {                                                                                                                                                                                                                                                                 
    if ( Lamp_8zzopen != 1 )                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
      if ( Lamp_8zzopen == 0 )                                                                                                                                                                                                                                      
      {                                                                                                                                                                                                                                                             
      Lamp_8zzhfil =                                                                                                                                                                                                                                                
           fopen( "Lamp_8.exh","w");  /* 12 */                                                                                                                                                                                                                      
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
          Lamp_8zzhfil =                                                                                                                                                                                                                                            
               fopen( "Lamp_8.exh","a");  /* 13 */                                                                                                                                                                                                                  
      }                                                                                                                                                                                                                                                             
      Lamp_8zzopen = 1;                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  }  /* end of zqqzqz1 */                                                                                                                                                                                                                                           
  /* ----------- zzqqzz ---------------------------------------------------* 321 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 323 *                                                                                                                                                                                  
   *            This is the routine which usually puts an integer into                                                                                                                                                                                              
   * the execution history file and returns unity.                                                                                                                                                                                                                  
   * This routine is the primary routine for gathering                                                                                                                                                                                                              
   * the execution history. Note that the last entry                                                                                                                                                                                                                
   * is usually inserted by Lamp_8zqzqzq.                                                                                                                                                                                                                           
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Lamp_8zzqqzz(int qqqi)                                                                                                                                                                                                                                 
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
    {                                                                                                                                                                                                                                                               
    if ( Lamp_8zzopen != 1 )                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
      Lamp_8zqqzqz1();                                                                                                                                                                                                                                              
    }                                                                                                                                                                                                                                                               
    if ( Lamp_8zzopen )                                                                                                                                                                                                                                             
    {                                                                                                                                                                                                                                                               
      /* streamed */                                                                                                                                                                                                                                                
      /* unbuffered */                                                                                                                                                                                                                                              
        qqoutput(                                                                                                                                                                                                                                                   
        Lamp_8zzhfil,                                                                                                                                                                                                                                               
          qqqqone, qqqi);                                                                                                                                                                                                                                           
    }                                                                                                                                                                                                                                                               
  }                                                                                                                                                                                                                                                                 
    return(1);                                                                                                                                                                                                                                                      
  } /* end of zzqqzz */                                                                                                                                                                                                                                             
  /* ----------- zqzqzq ---------------------------------------------------* 342 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 344 *                                                                                                                                                                                  
   * This routine should be called before the program                                                                                                                                                                                                               
   * terminates. It closes the execution history                                                                                                                                                                                                                    
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Lamp_8zqzqzq(int qqqi)                                                                                                                                                                                                                                 
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
      if ( Lamp_8zzopen != 1 )                                                                                                                                                                                                                                      
      {                                                                                                                                                                                                                                                             
        Lamp_8zqqzqz1();                                                                                                                                                                                                                                            
      }                                                                                                                                                                                                                                                             
      /* not compressed */                                                                                                                                                                                                                                          
      /* streamed */                                                                                                                                                                                                                                                
      /* notbuffered */                                                                                                                                                                                                                                             
      qqoutput(Lamp_8zzhfil,                                                                                                                                                                                                                                        
        qqqqone, qqqi);                                                                                                                                                                                                                                             
      /* upload the history */                                                                                                                                                                                                                                      
        fclose(Lamp_8zzhfil);                                                                                                                                                                                                                                       
        Lamp_8zzopen = 2;                                                                                                                                                                                                                                           
      }                                                                                                                                                                                                                                                             
    return(1);                                                                                                                                                                                                                                                      
  } /* end of zqzqzq */                                                                                                                                                                                                                                             
  /*   the following routines should be left alone */                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 355 *                                                                                                                                                                                  
   *            Lamp_8zzzqtz                                                                                                                                                                                                                                        
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is not 0.                                                                                                                                                                                                                 
   *                                                                                                                                                                                                                                                                
   *   qqqa - value of expression                                                                                                                                                                                                                                   
   *   qqqb - jump table index.                                                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Lamp_8zzzqtz(int qqqa, int qqqb)                                                                                                                                                                                                                       
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        Lamp_8zzqqzz(qqqb) ;                                                                                                                                                                                                                                        
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* end of zzzqtz */                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 356 *                                                                                                                                                                                  
   *            Lamp_8zzzqfz                                                                                                                                                                                                                                        
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is 0.                                                                                                                                                                                                                     
   *                                                                                                                                                                                                                                                                
   *  qqqa - value of expression                                                                                                                                                                                                                                    
   *  qqqb - jump table index.                                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Lamp_8zzzqfz(int qqqa,int qqqb)                                                                                                                                                                                                                        
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        return(qqqa);                                                                                                                                                                                                                                               
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
        Lamp_8zzqqzz(qqqb);                                                                                                                                                                                                                                         
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* zzzqfz */                                                                                                                                                                                                                                                    
/* END OF TESTBED INSTRUMENTATION */                                                                                                                                                                                                                                
 
