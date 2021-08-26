/*
C++ TESTBED VERSION  : 9.8.6
FILE UNDER TEST  : "C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Main.cpp"
DATE OF ANALYSIS : Wed May 26 15:21:14 2021
*/
 
/************************************************************************************************************
Main.cpp
v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
v2.0 Addition of ini file handling 13/08/15 Bill Cody
*************************************************************************************************************/
#include <iostream>
#include <fstream>
#define QQQdialect GCC                                                                                                                                                                                                               
#undef QQQ146
#undef QQQ148
#undef QQQbndchk
#define QQQ294
#undef QQQEMBEDDEDICE
 /* Note: for BITMAP execution histories QQQthreaded is not defined */
#undef QQQthreaded 
#define QQQdo178b
#undef QQQfixbra
#undef QQQswitch3
#undef QQQternary
#define QQQswitch
#undef QQQmacrof
#undef QQQMULTIPROCESSEXH
#undef QQFLUSH
#undef QQNEWBS
#define qqqMaxBranchDepth      2
#undef QQQstructbitmap
 static int zzfileid =     11;
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
#define QQQMAINFL
#undef QQQSINGLEFILE
#undef QQQFILEID
#undef QQQseparate
 static int Main_11zzopen                                                                                        = 0;
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
  static int Main_11zqqzqz(qqnull_params);                                                                                                                                                                                                                          
  static int Main_11zqqzqz1(qqnull_params);                                                                                                                                                                                                                         
  static int Main_11zzqqzz (int qqqi);                                                                                                                                                                                                                              
  static int Main_11zqzqzq (int qqqi);                                                                                                                                                                                                                              
  static int Main_11zqfqzz (int qqqi);                                                                                                                                                                                                                              
  static int Main_11zzzqtz (int qqqa, int qqqb);                                                                                                                                                                                                                    
  static int Main_11zzzqfz (int qqqa, int qqqb);                                                                                                                                                                                                                    
  static int Main_11zzdo17 (int a, int b);                                                                                                                                                                                                                          
/* ------------------------------ END OF TESTBED PROTOTYPES -------------------------------- */                                                                                                                                                                     
using std :: cout ;
using std :: cin ;
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
 


class ldra_class_1100030000{ public:  /* 76 */
 ldra_class_1100030000(){ };
 ldra_class_1100030000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Main_11zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Main_11zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class LampAttributes
        :public ldra_class_1100030000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_11;
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
 


class ldra_class_1100040000{ public:  /* 76 */
 ldra_class_1100040000(){ };
 ldra_class_1100040000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Main_11zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Main_11zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class SquareLamp :
        public ldra_class_1100040000, /* 69 */
public LampAttributes
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_11;
#endif
  public :
  SquareLamp ( int l , model ThisModel ) ;
} ;
}
/*   CLOSE_FILE Include File */
/* OPEN FILE C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Lamptype.h */
/************************************************************************************************************
LampType.h
v1.0 Original 23/10/07 Bill Cody
*************************************************************************************************************/
namespace TunnelData {
 


class ldra_class_1100050000{ public:  /* 76 */
 ldra_class_1100050000(){ };
 ldra_class_1100050000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Main_11zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Main_11zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class LampType
        :public ldra_class_1100050000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_11;
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
 


class ldra_class_1100060000{ public:  /* 76 */
 ldra_class_1100060000(){ };
 ldra_class_1100060000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Main_11zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Main_11zzqqzz                                                                                       ( from );
                         }  ;};
                    };
 static int                                                                                                 
 ZZ100177 = ( 
 Main_11zzqqzz                                                                                       
 (       1 ) * 1 /* 14 */);

 static int                                                                                                 
 ZZ100182 = ( 
 Main_11zzqqzz                                                                                       
 (       2 ) * 1 /* 14 */);

class SystemData
        :public ldra_class_1100060000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_11;
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
    ldra_class_1100060000(),  /* 71 c1*/
  mTheLampType ( )
  {
   int iMain_11zzqqzz                                                                                       
 = Main_11zzqqzz                                                                                        (       3 ) ; /* 37 */
    Main_11zzqqzz                                                                                        (       4 ) ; /* 30 */  
  }                                        //No copy
 
  void
  operator = ( const SystemData & )
  {
   int iMain_11zzqqzz                                                                                       
 = Main_11zzqqzz                                                                                        (       5 ) ; /* 37 */
    Main_11zzqqzz                                                                                        (       6 ) ; /* 30 */  
  }                                            //No copy
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
 


class ldra_class_1100070000{ public:  /* 76 */
 ldra_class_1100070000(){ };
 ldra_class_1100070000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Main_11zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Main_11zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class Lamp
        :public ldra_class_1100070000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_11;
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
/* OPEN FILE C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Cell.h */
/************************************************************************************************************
Cell.h
v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
namespace TunnelData {
 


class ldra_class_1100080000{ public:  /* 76 */
 ldra_class_1100080000(){ };
 ldra_class_1100080000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Main_11zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Main_11zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class Cell
        :public ldra_class_1100080000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_11;
#endif
  public :
        //Constructors
  Cell ( void ) ;
          //Accessors
  Bool InitialiseCell ( const Sint_32 LuminaireSetSize , const LampTypeID * pLampTypeIDs , const Sint_32 UniqueCellID ) ;
         //Others
  void SetPoweredOutputLevel ( const Float_64 LumensDemandPerMetre , const Float_64 CellSpacing ) ;
  void SetEmergencyOutputLevel ( void ) ;
  private :
  LampTypeID mLampTypeID [ LampsPerLuminaire * MaxLuminairesPerCell ] ;
  Sint_32 mLuminaireSetSize ;
  Sint_32 mUniqueCellID ;
  Float_64 mLampTypeMaxLumens [ NumLampTypes ] ;
  Float_64 mLampTypeMinLumens [ NumLampTypes ] ;
  Sint_32 mLampTypeCount [ NumLampTypes ] ;
  Lamp mThisLamp [ LampsPerLuminaire * MaxLuminairesPerCell ] ;
  Float_64 CalculateCellOutput ( Float_64 LumensDemandPerMetre , Float_64 CellSpacing ) ;
  model GetLampModel ( const Sint_32 ThisLamp ) ;
} ;
}
/*   CLOSE_FILE Include File */
/* OPEN FILE C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Zone.h */
/************************************************************************************************************
Zone.h
v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
namespace TunnelData {
 


class ldra_class_1100090000{ public:  /* 76 */
 ldra_class_1100090000(){ };
 ldra_class_1100090000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Main_11zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Main_11zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class Zone
        :public ldra_class_1100090000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_11;
#endif
  public :
        //Constructors
  Zone ( void ) ;
         //Accessors
  void InitialiseZone ( Sint_32 * pZoneData , const Sint_32 UniqueZoneID ) ;
         //Others
  Bool CalculateOutputFormula ( const Sint_32 PercentageDemand ) ;
  Bool AssignPoweredCellsOutput ( void ) ;
  Bool AssignEmergencyCellsOutput ( void ) ;
  private :
  Sint_32 mLength ;
  Sint_32 mLuminaireSetSize ;
  Sint_32 mSetSpacing ;
  LampTypeID mTheLampTypeID [ LampsPerLuminaire ] ;
  Sint_32 mMinimumEntryOutput ;
  Sint_32 mMinimumExitOutput ;
  Sint_32 mMaximumEntryOutput ;
  Sint_32 mMaximumExitOutput ;
  Float_64 mFormulaGradient ;
  Float_64 mFormulaConstant ;
  Cell mThisCell [ MaxCellsPerZone ] ;
} ;
}
/*   CLOSE_FILE Include File */
/* OPEN FILE C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Tunnel.h */
/************************************************************************************************************
Tunnel.h
v1.0 Original 23/10/07 Bill Cody
*************************************************************************************************************/
namespace TunnelData {
 


class ldra_class_1100001000{ public:  /* 76 */
 ldra_class_1100001000(){ };
 ldra_class_1100001000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Main_11zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Main_11zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class Tunnel
        :public ldra_class_1100001000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_11;
#endif
  public :
         //Accessors
  void InitialiseTunnel ( const Sint_32 ZoneNumber , Sint_32 * pZoneData ) ;
  void AdjustLighting ( const Float_64 PhotometerDemand , Bool PowerFailure ) ;
  private :
  Zone TunnelZone [ NumZones ] ;
  void AdjustPoweredLighting ( const Float_64 PhotometerDemand ) ;
  void AdjustEmergencyLighting ( void ) ;
} ;
}
/*   CLOSE_FILE Include File */
/* OPEN FILE C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Datain.h */
/************************************************************************************************************
DataIn.h
v1.0 Original 23/10/07 Bill Cody
*************************************************************************************************************/
namespace TunnelData {
 


class ldra_class_1100011000{ public:  /* 76 */
 ldra_class_1100011000(){ };
 ldra_class_1100011000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Main_11zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Main_11zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class DataIn
        :public ldra_class_1100011000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_11;
#endif
  public :
        //Other methods
  Bool GetData ( Tunnel * pTunnel ) ;
  void ReadContent ( Sint_32 * array , char * Token , Sint_32 count ) ;
  protected :
  Char Buffer [ 1023 ] ;
} ;
}
/*   CLOSE_FILE Include File */
/* For emergency command */
 
void
  CheckForInitialisation() ;
 
Sint_32
  main()
// Initialise from ini file, and then enter "Photometer input loop".
  {
  int mainzz = Main_11zqqzqz1                                                                                       (); /* 46 */
    using namespace TunnelData ;
    DataIn
      ThisDataIn ;
    Tunnel
      TheTunnel ;
    Sint_32
      Choice ;
    Bool
      Quit = false ;
    Bool
      PowerFailure = false ;
    Float_64
      Photometer = 4.0 ;
    Sint_32
      DaysSinceCleaning = 0 ;
 
    const Sint_32
      MaxChoice = 3 ;
 
    const Float_64
      MinPhotometer = 4.0 ;
 
    const Float_64
      MaxPhotometer = 20.0 ;
 Main_11zzqqzz                                                                                        (       7 ) ; /* 23 */
 
    CheckForInitialisation ( ) ;
    //Initialise from ini file
    if
      (
      !
      ThisDataIn.GetData ( & TheTunnel )
      )
 {
      {
        cout << "Flawed or missing ini file. (0) quit \n" ;
        cin >> Choice ;
        cout << "\n" ;
      }
    Main_11zzqqzz                                                                                        (      8 ) ; /* 3 */
 }
    else
 {                                                                                                    ;
Main_11zzqqzz                                                                                        (      9 ); /* 2 */
      {
        while
          (
 (  /* 21 */ 
          ! Quit
  )  /* 7 */
          )
          {
 { /* 32 */
            cout << "\nPhotometer Input: " << Photometer << "mA    Days since cleaning: " << DaysSinceCleaning << "    Power: " ;
            if
              (
              PowerFailure
              )
 {
              {
                cout << "Failed" ;
              }
    Main_11zzqqzz                                                                                        (     10 ) ; /* 3 */
 }
            else
 {                                                                                                    ;
Main_11zzqqzz                                                                                        (     11 ); /* 2 */
              {
                cout << "Live" ;
              }
 }
            cout << " \n \n(0) quit (1) Photometer Input (4-20) \n(2) Set days since cleaning (3) Toggle Power Failure Status: \n" ;
            cin >> Choice ;
            cout << "\n" ;
            if
 (  /* 50 */
              (
              
  (bool)Main_11zzdo17                                                                                        (     /*  81 */ 
              
  Main_11zzzqfz                                                                                        (     /*  52 */ 
              0 <= Choice
   ? Main_11zzdo17                                                                                       ( 1,     14) : 
Main_11zzdo17                                                                                       ( 0,     14) ,      12  )  /*  54 */
              &&
              
  Main_11zzdo17                                                                                        (     /*  72 */ 
              MaxChoice >= Choice
  ? 1 : 0  ,      16  )  /*  73 */
  ? 1 : 0  ,      18  )  /*  82 */
              )
  ) /* 1 */
 {
              {
                switch (
  ( ( int )(  /* 29 */
                  Choice
 ))* Main_11zzqqzz                                                                                        (      19 ) /* 19 */
                  )
                  {
                  case 0 :
 Main_11zzqqzz                                                                                        (      20 ) ; /* 41 */
                    Quit = true ;
 Main_11zzqqzz                                                                                        (      21 ) ; 
goto l100452 ; /* 16 */
                  case 1 :
 Main_11zzqqzz                                                                                        (      22 ) ; /* 41 */
             // Get user input in absence of hardware
                    {
                      do
                        {
                          cout << "Enter photometer input in range 4-20mA: " ;
                          cin >> Photometer ;
                        }
                      while
 (  /* 50 */
                        (
                        
  (bool)Main_11zzdo17                                                                                        (     /*  81 */ 
                        
  Main_11zzzqtz                                                                                        (     /*  51 */ 
                        Photometer < MinPhotometer
   ? Main_11zzdo17                                                                                       ( 1,     25) : 
Main_11zzdo17                                                                                       ( 0,     25) ,      23  )  /*  54 */
                        ||
                        
  Main_11zzdo17                                                                                        (     /*  72 */ 
                        Photometer > MaxPhotometer
  ? 1 : 0  ,      27  )  /*  73 */
  ? 1 : 0  ,      29  )  /*  82 */
           ) &&                                                                                                  
Main_11zzqqzz                                                                                        (      30 ) /* 24 */
                        ) ;
                      TheTunnel.AdjustLighting ( Photometer , PowerFailure ) ;
 Main_11zzqqzz                                                                                        (      31 ) ; 
goto l100452 ; /* 16 */
                    }
                  case 2 :
 Main_11zzqqzz                                                                                        (      32 ) ; /* 41 */
             // Get user input for days elapsed.
                    {
                      do
                        {
                          cout << "Enter days since cleaning in the range 0-" <<
                          SystemData::Instance () ->
                                                     GetDaysBetweenCleaning ( ) << " : " ;
                          cin >> DaysSinceCleaning ;
                        }
                      while
 (  /* 50 */
                        (
                        
  (bool)Main_11zzdo17                                                                                        (     /*  81 */ 
                        
  Main_11zzzqtz                                                                                        (     /*  51 */ 
                        
 (   /*  55 */
                        DaysSinceCleaning > (
                        SystemData::Instance () ->
                                                   GetDaysBetweenCleaning ( )
                        )
                        
 )  /*  56 */
   ? Main_11zzdo17                                                                                       ( 1,     35) : 
Main_11zzdo17                                                                                       ( 0,     35) ,      33  )  /*  54 */
                        ||
                        
 (   /*  55 */
                        
  Main_11zzdo17                                                                                        (     /*  72 */ 
                        DaysSinceCleaning < 0
  ? 1 : 0  ,      37  )  /*  73 */
                        
 )  /*  56 */
  ? 1 : 0  ,      39  )  /*  82 */
           ) &&                                                                                                  
Main_11zzqqzz                                                                                        (      40 ) /* 24 */
                        ) ;
                      SystemData::Instance () ->
                                                 SetDaysSinceCleaning (
                      DaysSinceCleaning ) ;
                      TheTunnel.AdjustLighting ( Photometer , PowerFailure ) ;
 Main_11zzqqzz                                                                                        (      41 ) ; 
goto l100452 ; /* 16 */
                    }
                  case 3 :
 Main_11zzqqzz                                                                                        (      42 ) ; /* 41 */
             // Get user input for power failure.
                    {
                      PowerFailure = ! PowerFailure ;
                      TheTunnel.AdjustLighting ( Photometer , PowerFailure ) ;
 Main_11zzqqzz                                                                                        (      43 ) ; 
goto l100452 ; /* 16 */
                    }
                  }
l100452 : 
 ; /* 18 */
 Main_11zzqqzz                                                                                        (      44 ) ; /* 49 */
              }
 }                                                                                                   
else                                                                                                
  Main_11zzqqzz                                                                                        (     45 ) ; /* 4 */
    Main_11zzqqzz                                                                                        (     46 ) ;} /* 6 */
          }
    Main_11zzqqzz                                                                                        (     47 ) ; /* 5 */
      }
 }
    Main_11zqzqzq                                                                                        (      48 ) ; /* 48 */
    return
    0 ;
  }
 
void
  CheckForInitialisation()
  {
   int iMain_11zzqqzz                                                                                       
 = Main_11zzqqzz                                                                                        (      49 ) ; /* 37 */
        // Check for existing ini file
    std::ifstream
      in ( "Tunnel.ini" ) ;
    if
      (
      !
      in.good ()
      )
 {
      {
         // Write out a default ini file
 
        std::ofstream
          out ( "Tunnel.ini" ) ;
        if
          (
          out.good ()
          )
 {
          {
            out << "1: Tunnel wide parameters " << std::endl ;
            out << "2: 50, 75, 182, 50, 120, 60, 5500, 400, 200" << std::endl ;
            out << "1:" << std::endl ;
            out << "1: TUNNEL ZONES" << std::endl ;
            out << "1: Zone 1" << std::endl ;
            out << "3: 300, 3, 20, 0, 0, 1, 1, 5000, 10000, 4000, 6000" << std::endl ;
            out << "1:" << std::endl ;
            out << "1: Zone 2" << std::endl ;
            out << "3: 500, 2, 20, 0, 0, 1, 1, 4000, 6000, 2000, 2000" << std::endl ;
            out << "1:" << std::endl ;
            out << "1: Zone 3" << std::endl ;
            out << "3: 600, 1, 30, 0, 0, 1, 1, 2000, 2000, 2000, 2000" << std::endl ;
            out << "1:" << std::endl ;
            out << "1: Zone 4" << std::endl ;
            out << "3: 400, 2, 20, 0, 0, 1, 1, 2000, 2000, 3000, 5000" << std::endl ;
            out << "1:" << std::endl ;
            out << "1: Zone 5" << std::endl ;
            out << "3: 200, 3, 20, 0, 0, 1, 1, 3000, 5000, 5000, 10000" << std::endl ;
          }
 }                                                                                                   
else                                                                                                
  Main_11zzqqzz                                                                                        (     50 ) ; /* 4 */
        out.close () ;
      }
 }                                                                                                   
else                                                                                                
  Main_11zzqqzz                                                                                        (     51 ) ; /* 4 */
    in.close () ;
    Main_11zzqqzz                                                                                        (      52 ) ; /* 30 */  
  }
#define qqqbranches     52
#define QQQMAXMCDCSIZE    122
 static FILE * Main_11zzhfil                                                                                        ;
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
  static int Main_11zqqzqz(qqnull_params);                                                                                                                                                                                                                          
  static int Main_11zqqzqz1(qqnull_params);                                                                                                                                                                                                                         
  static int Main_11zqfqzz (int qqqi);                                                                                                                                                                                                                              
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
   * superceded by Main_11zqqzqz1 below.                                                                                                                                                                                                                            
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Main_11zqqzqz(qqnull_params)                                                                                                                                                                                                                           
  {                                                                                                                                                                                                                                                                 
    if ( Main_11zzopen != 1 )                                                                                                                                                                                                                                       
    {                                                                                                                                                                                                                                                               
#undef QQQMUSTOPEN                                                                                                                                                                                                                                                  
      Main_11zzopen = 1;                                                                                                                                                                                                                                            
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  }  /* end of zqqzqz */                                                                                                                                                                                                                                            
  /* ----------- zqqzqz1 --------------------------------------------------* 315 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 317 *                                                                                                                                                                                  
   * This routine also opens the execution history file.  It is called                                                                                                                                                                                              
   * automatically if a probe fires and the execution history is not already                                                                                                                                                                                        
   * opened (Main_11zzopen = 0 ).                                                                                                                                                                                                                                   
   * Because this always works ( it was intended for files with no main program                                                                                                                                                                                     
   * it is now the de facto common way to open the execution history.                                                                                                                                                                                               
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Main_11zqqzqz1(qqnull_params)                                                                                                                                                                                                                          
  {                                                                                                                                                                                                                                                                 
    if ( Main_11zzopen != 1 )                                                                                                                                                                                                                                       
    {                                                                                                                                                                                                                                                               
      if ( Main_11zzopen == 0 )                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
      Main_11zzhfil =                                                                                                                                                                                                                                               
           fopen( "Main_11.exh","w");  /* 12 */                                                                                                                                                                                                                     
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
          Main_11zzhfil =                                                                                                                                                                                                                                           
               fopen( "Main_11.exh","a");  /* 13 */                                                                                                                                                                                                                 
      }                                                                                                                                                                                                                                                             
      Main_11zzopen = 1;                                                                                                                                                                                                                                            
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
   * is usually inserted by Main_11zqzqzq.                                                                                                                                                                                                                          
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Main_11zzqqzz(int qqqi)                                                                                                                                                                                                                                
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
    {                                                                                                                                                                                                                                                               
    if ( Main_11zzopen != 1 )                                                                                                                                                                                                                                       
    {                                                                                                                                                                                                                                                               
      Main_11zqqzqz1();                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    if ( Main_11zzopen )                                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
      /* streamed */                                                                                                                                                                                                                                                
      /* unbuffered */                                                                                                                                                                                                                                              
        qqoutput(                                                                                                                                                                                                                                                   
        Main_11zzhfil,                                                                                                                                                                                                                                              
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
  static int Main_11zqzqzq(int qqqi)                                                                                                                                                                                                                                
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
      if ( Main_11zzopen != 1 )                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        Main_11zqqzqz1();                                                                                                                                                                                                                                           
      }                                                                                                                                                                                                                                                             
      /* not compressed */                                                                                                                                                                                                                                          
      /* streamed */                                                                                                                                                                                                                                                
      /* notbuffered */                                                                                                                                                                                                                                             
      qqoutput(Main_11zzhfil,                                                                                                                                                                                                                                       
        qqqqone, qqqi);                                                                                                                                                                                                                                             
      /* upload the history */                                                                                                                                                                                                                                      
        fclose(Main_11zzhfil);                                                                                                                                                                                                                                      
        Main_11zzopen = 2;                                                                                                                                                                                                                                          
      }                                                                                                                                                                                                                                                             
    return(1);                                                                                                                                                                                                                                                      
  } /* end of zqzqzq */                                                                                                                                                                                                                                             
  /*   the following routines should be left alone */                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 354 *                                                                                                                                                                                  
   *            Main_11zqfqzz                                                                                                                                                                                                                                       
   *        This routine is used for switches.                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Main_11zqfqzz(int qqqi)                                                                                                                                                                                                                                
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
      int qqql;                                                                                                                                                                                                                                                     
      qqql = qqqi - 1;                                                                                                                                                                                                                                              
      Main_11zzqqzz(qqql);                                                                                                                                                                                                                                          
      Main_11zzqqzz(qqqi);                                                                                                                                                                                                                                          
    }                                                                                                                                                                                                                                                               
    return (1);                                                                                                                                                                                                                                                     
  } /* end of zqfqzz */                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 355 *                                                                                                                                                                                  
   *            Main_11zzzqtz                                                                                                                                                                                                                                       
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is not 0.                                                                                                                                                                                                                 
   *                                                                                                                                                                                                                                                                
   *   qqqa - value of expression                                                                                                                                                                                                                                   
   *   qqqb - jump table index.                                                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Main_11zzzqtz(int qqqa, int qqqb)                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        Main_11zzqqzz(qqqb) ;                                                                                                                                                                                                                                       
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* end of zzzqtz */                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 356 *                                                                                                                                                                                  
   *            Main_11zzzqfz                                                                                                                                                                                                                                       
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is 0.                                                                                                                                                                                                                     
   *                                                                                                                                                                                                                                                                
   *  qqqa - value of expression                                                                                                                                                                                                                                    
   *  qqqb - jump table index.                                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Main_11zzzqfz(int qqqa,int qqqb)                                                                                                                                                                                                                       
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        return(qqqa);                                                                                                                                                                                                                                               
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
        Main_11zzqqzz(qqqb);                                                                                                                                                                                                                                        
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* zzzqfz */                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 357 *                                                                                                                                                                                  
   *            Main_11zzdo17                                                                                                                                                                                                                                       
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Main_11zzdo17(                                                                                                                                                                                                                                         
    int a, int b)                                                                                                                                                                                                                                                   
  {                                                                                                                                                                                                                                                                 
    if ( a )                                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
      Main_11zzqqzz(b-1);                                                                                                                                                                                                                                           
    }                                                                                                                                                                                                                                                               
    else                                                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
      Main_11zzqqzz(b);                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return a;                                                                                                                                                                                                                                                       
  } /*  end of zzdo17 */                                                                                                                                                                                                                                            
/* END OF TESTBED INSTRUMENTATION */                                                                                                                                                                                                                                
 
