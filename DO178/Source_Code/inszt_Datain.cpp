/*
C++ TESTBED VERSION  : 9.8.6
FILE UNDER TEST  : "C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Datain.cpp"
DATE OF ANALYSIS : Wed May 26 15:20:59 2021
*/
 
/************************************************************************************************************
DataIn.cpp
v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
#include <stdlib.h>
#include <fstream>
#include <string.h>
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
 static int zzfileid =      7;
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
 static int Datain_7zzopen                                                                                       = 0;
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
  static int Datain_7zqqzqz(qqnull_params);                                                                                                                                                                                                                         
  static int Datain_7zqqzqz1(qqnull_params);                                                                                                                                                                                                                        
  static int Datain_7zzqqzz (int qqqi);                                                                                                                                                                                                                             
  static int Datain_7zqzqzq (int qqqi);                                                                                                                                                                                                                             
  static int Datain_7zqfqzz (int qqqi);                                                                                                                                                                                                                             
  static int Datain_7zzzqtz (int qqqa, int qqqb);                                                                                                                                                                                                                   
  static int Datain_7zzzqfz (int qqqa, int qqqb);                                                                                                                                                                                                                   
  static int Datain_7zzdo17 (int a, int b);                                                                                                                                                                                                                         
/* ------------------------------ END OF TESTBED PROTOTYPES -------------------------------- */                                                                                                                                                                     
using std :: ifstream ;
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
 


class ldra_class_7000030000{ public:  /* 76 */
 ldra_class_7000030000(){ };
 ldra_class_7000030000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Datain_7zzqqzz                                                                                      ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Datain_7zzqqzz                                                                                      ( from );
                         }  ;};
                    };
class LampAttributes
        :public ldra_class_7000030000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_7;
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
 


class ldra_class_7000040000{ public:  /* 76 */
 ldra_class_7000040000(){ };
 ldra_class_7000040000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Datain_7zzqqzz                                                                                      ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Datain_7zzqqzz                                                                                      ( from );
                         }  ;};
                    };
class SquareLamp :
        public ldra_class_7000040000, /* 69 */
public LampAttributes
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_7;
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
 


class ldra_class_7000050000{ public:  /* 76 */
 ldra_class_7000050000(){ };
 ldra_class_7000050000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Datain_7zzqqzz                                                                                      ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Datain_7zzqqzz                                                                                      ( from );
                         }  ;};
                    };
class LampType
        :public ldra_class_7000050000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_7;
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
 


class ldra_class_7000060000{ public:  /* 76 */
 ldra_class_7000060000(){ };
 ldra_class_7000060000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Datain_7zzqqzz                                                                                      ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Datain_7zzqqzz                                                                                      ( from );
                         }  ;};
                    };
class SystemData
        :public ldra_class_7000060000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_7;
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
    ldra_class_7000060000(),  /* 71 c1*/
  mTheLampType ( )
  {
   int iDatain_7zzqqzz                                                                                      
 = Datain_7zzqqzz                                                                                       (       1 ) ; /* 37 */
    Datain_7zzqqzz                                                                                       (       2 ) ; /* 30 */  
  }                                        //No copy
 
  void
  operator = ( const SystemData & )
  {
   int iDatain_7zzqqzz                                                                                      
 = Datain_7zzqqzz                                                                                       (       3 ) ; /* 37 */
    Datain_7zzqqzz                                                                                       (       4 ) ; /* 30 */  
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
 


class ldra_class_7000070000{ public:  /* 76 */
 ldra_class_7000070000(){ };
 ldra_class_7000070000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Datain_7zzqqzz                                                                                      ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Datain_7zzqqzz                                                                                      ( from );
                         }  ;};
                    };
class Lamp
        :public ldra_class_7000070000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_7;
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
 


class ldra_class_7000080000{ public:  /* 76 */
 ldra_class_7000080000(){ };
 ldra_class_7000080000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Datain_7zzqqzz                                                                                      ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Datain_7zzqqzz                                                                                      ( from );
                         }  ;};
                    };
class Cell
        :public ldra_class_7000080000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_7;
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
 


class ldra_class_7000090000{ public:  /* 76 */
 ldra_class_7000090000(){ };
 ldra_class_7000090000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Datain_7zzqqzz                                                                                      ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Datain_7zzqqzz                                                                                      ( from );
                         }  ;};
                    };
class Zone
        :public ldra_class_7000090000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_7;
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
 


class ldra_class_7000001000{ public:  /* 76 */
 ldra_class_7000001000(){ };
 ldra_class_7000001000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Datain_7zzqqzz                                                                                      ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Datain_7zzqqzz                                                                                      ( from );
                         }  ;};
                    };
class Tunnel
        :public ldra_class_7000001000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_7;
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
 


class ldra_class_7000011000{ public:  /* 76 */
 ldra_class_7000011000(){ };
 ldra_class_7000011000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Datain_7zzqqzz                                                                                      ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Datain_7zzqqzz                                                                                      ( from );
                         }  ;};
                    };
class DataIn
        :public ldra_class_7000011000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_7;
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
namespace TunnelData {
 
Bool
  DataIn::GetData (
  Tunnel * pTunnel )
        /* Reads all data from the "Tunnel.ini" initialisation file, and allocates appropriately.*/
  {
typedef Bool  zzqtype;
   int iDatain_7zzqqzz                                                                                      
 = Datain_7zzqqzz                                                                                       (       5 ) ; /* 37 */
    ifstream
      loadcsv ( "./Tunnel.ini" ) ;
    Char
      Sep [] = ":," ;
    Char *
      ValidLine ;
    Bool
      Okay = true ;
    Sint_32
      ZoneCount = 0 ;
    Sint_32
      ParamLineCount = 0 ;
    do
      {
          //Check whether all is well with the ini file
        Okay =
        loadcsv.good () ;
        if
          (
          Okay
          )
 {
          {
            loadcsv.getline ( Buffer , sizeof ( Buffer ) ) ;
            ValidLine =
            strtok ( Buffer , Sep ) ;
          }
 }                                                                                                   
else                                                                                                
  Datain_7zzqqzz                                                                                       (      6 ) ; /* 4 */
        if
 (  /* 50 */
          (
          
  (bool)Datain_7zzdo17                                                                                       (     /*  81 */ 
          
  Datain_7zzzqfz                                                                                       (     /*  52 */ 
          Okay
   ? Datain_7zzdo17                                                                                      ( 1,      9) : 
Datain_7zzdo17                                                                                      ( 0,      9) ,       7  )  /*  54 */
          &&
          
  Datain_7zzdo17                                                                                       (     /*  72 */ 
          ValidLine
  ? 1 : 0  ,      11  )  /*  73 */
  ? 1 : 0  ,      13  )  /*  82 */
          )                      // Is this a valid entry?
  ) /* 1 */
 {
          {
            Sint_32
              LineType =
                         atoi ( ValidLine ) ;
            switch (
  ( ( int )(  /* 29 */
              LineType
 ))* Datain_7zzqqzz                                                                                       (      14 ) /* 19 */
              )
              {
              case 1 :
 Datain_7zzqqzz                                                                                       (      15 ) ; /* 41 */
                    //Comment - do nothing
                {
 Datain_7zzqqzz                                                                                       (      16 ) ; 
goto l100449 ; /* 16 */
                }
              case 2 :
 Datain_7zzqqzz                                                                                       (      17 ) ; /* 41 */
                    //System parameters
                {
                  Char *
                    Token ;
                  Sint_32
                    Count = 0 ;
                  Sint_32
                    SystemDataArray [ NumSystemParams ] ;
                  ParamLineCount ++ ;
                  Token = ( Char * )
                  malloc ( sizeof ( Char )
                          ) ;
                  Token =
                  strtok ( NULL , Sep ) ;
                  //ReadContent(SystemDataArray, Token, Count);
                  //Data line so read contents
                  while
                    (
 (  /* 21 */ 
                    
  (bool)Datain_7zzdo17                                                                                       (     /*  81 */ 
                    
  Datain_7zzzqfz                                                                                       (     /*  52 */ 
                    Token
   ? Datain_7zzdo17                                                                                      ( 1,     20) : 
Datain_7zzdo17                                                                                      ( 0,     20) ,      18  )  /*  54 */
                    &&
                    
  Datain_7zzdo17                                                                                       (     /*  72 */ 
                    Count < NumSystemParams
  ? 1 : 0  ,      22  )  /*  73 */
  ? 1 : 0  ,      24  )  /*  82 */
  )  /* 7 */
                    )
                    {
 { /* 32 */
              //Zone data
                      SystemDataArray [ Count ] =
                      atoi ( Token ) ;
              // Next token while there are tokens in "string"
                      Count ++ ;
                      Token =
                      strtok ( NULL , "," ) ;
    Datain_7zzqqzz                                                                                       (     25 ) ;} /* 6 */
                    }
    Datain_7zzqqzz                                                                                       (     26 ) ; /* 5 */
                  free ( Token ) ;
                  SystemData::Instance () ->
                                             InitialiseParams (
                  SystemDataArray ) ;
                  free ( Token ) ;
 Datain_7zzqqzz                                                                                       (      27 ) ; 
goto l100449 ; /* 16 */
                }
              case 3 :
 Datain_7zzqqzz                                                                                       (      28 ) ; /* 41 */
                    //Zone
                {
                  Char *
                    Token ;
                  Sint_32
                    Count = 0 ;
                  Sint_32
                    ZoneData [ NumZoneParams ] ;
                  Token =
                  strtok ( NULL , Sep ) ;//Get first data entry
                  //ReadContent(ZoneData, Token, Count);
                  while
                    (
 (  /* 21 */ 
                    
  (bool)Datain_7zzdo17                                                                                       (     /*  81 */ 
                    
  Datain_7zzzqfz                                                                                       (     /*  52 */ 
                    Token
   ? Datain_7zzdo17                                                                                      ( 1,     31) : 
Datain_7zzdo17                                                                                      ( 0,     31) ,      29  )  /*  54 */
                    &&
                    
  Datain_7zzdo17                                                                                       (     /*  72 */ 
                    Count < NumZoneParams
  ? 1 : 0  ,      33  )  /*  73 */
  ? 1 : 0  ,      35  )  /*  82 */
  )  /* 7 */
                    )
                    {
 { /* 32 */
              //Zone data
                      ZoneData [ Count ] =
                      atoi ( Token ) ;
              // Next token while there are tokens in "string"
                      Count ++ ;
                      Token =
                      strtok ( NULL , "," ) ;
    Datain_7zzqqzz                                                                                       (     36 ) ;} /* 6 */
                    }
    Datain_7zzqqzz                                                                                       (     37 ) ; /* 5 */
                  pTunnel ->
                             InitialiseTunnel (
                  ZoneCount , ZoneData ) ;
                  ZoneCount ++ ;
 Datain_7zzqqzz                                                                                       (      38 ) ; 
goto l100449 ; /* 16 */
                }
              default :
 Datain_7zzqqzz                                                                                       (      39 ) ; /* 41 */
                     //Unrecognised line - abort
                {
                  Okay = false ;
                }
              }
l100449 : 
 ; /* 18 */
          }
 }                                                                                                   
else                                                                                                
  Datain_7zzqqzz                                                                                       (     40 ) ; /* 4 */
      }
    while
 (  /* 50 */
      (
      
  (bool)Datain_7zzdo17                                                                                       (     /*  81 */ 
      
  Datain_7zzzqfz                                                                                       (     /*  52 */ 
      Okay
   ? Datain_7zzdo17                                                                                      ( 1,     43) : 
Datain_7zzdo17                                                                                      ( 0,     43) ,      41  )  /*  54 */
      &&
      
  Datain_7zzdo17                                                                                       (     /*  72 */ 
      ValidLine
  ? 1 : 0  ,      45  )  /*  73 */
  ? 1 : 0  ,      47  )  /*  82 */
           ) &&                                                                                                  
Datain_7zzqqzz                                                                                       (      48 ) /* 24 */
      ) ;
    loadcsv.close () ;
 Datain_7zzqqzz                                                                                       (      49 ) ; /* 20 */
    goto End ;
    ZoneCount ++ ;
End :
 qqswitchyy();
   zzqtype  Datain_7izzzqq =
    (
  (bool)Datain_7zzdo17                                                                                       (     /*  81 */ 
     
  Datain_7zzzqfz                                                                                       (     /*  52 */ 
 
    Okay
   ? Datain_7zzdo17                                                                                      ( 1,     52) : 
Datain_7zzdo17                                                                                      ( 0,     52) ,      50  )  /*  54 */
    &&
    
  Datain_7zzzqfz                                                                                       (     /*  52 */ 
    (
    NumZones == ZoneCount
    )
   ? Datain_7zzdo17                                                                                      ( 1,     55) : 
Datain_7zzdo17                                                                                      ( 0,     55) ,      53  )  /*  54 */
    &&
    
  Datain_7zzdo17                                                                                       (     /*  72 */ 
    ( 1 == ParamLineCount
    )
  ? 1 : 0  ,      57  )  /*  73 */
  ? 1 : 0  ,      59  )  /*  82 */
    ) ;
 
 qqswitchyy();
    Datain_7zzqqzz                                                                                       (      60 ) ; /* 30 */  
    ;
return ( Datain_7izzzqq );
  }
 
void
  DataIn::ReadContent (
  Sint_32 * array ,
  char * Token ,
  Sint_32 Count )
  {
   int iDatain_7zzqqzz                                                                                      
 = Datain_7zzqqzz                                                                                       (      61 ) ; /* 37 */
    while
      (
 (  /* 21 */ 
      
  (bool)Datain_7zzdo17                                                                                       (     /*  81 */ 
      
  Datain_7zzzqfz                                                                                       (     /*  52 */ 
      Token
   ? Datain_7zzdo17                                                                                      ( 1,     64) : 
Datain_7zzdo17                                                                                      ( 0,     64) ,      62  )  /*  54 */
      &&
      
  Datain_7zzdo17                                                                                       (     /*  72 */ 
      Count < NumZoneParams
  ? 1 : 0  ,      66  )  /*  73 */
  ? 1 : 0  ,      68  )  /*  82 */
  )  /* 7 */
      )
      {
 { /* 32 */
          //Zone data
        array [ Count ] =
        atoi ( Token ) ;
          // Next token while there are tokens in "string"
        Count ++ ;
        Token =
        strtok ( NULL , "," ) ;
    Datain_7zzqqzz                                                                                       (     69 ) ;} /* 6 */
      }
    Datain_7zzqqzz                                                                                       (     70 ) ; /* 5 */
    Datain_7zzqqzz                                                                                       (      71 ) ; /* 30 */  
  }
}
#define qqqbranches     71
#define QQQMAXMCDCSIZE    258
 static FILE * Datain_7zzhfil                                                                                       ;
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
  static int Datain_7zqqzqz(qqnull_params);                                                                                                                                                                                                                         
  static int Datain_7zqqzqz1(qqnull_params);                                                                                                                                                                                                                        
  static int Datain_7zqfqzz (int qqqi);                                                                                                                                                                                                                             
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
   * superceded by Datain_7zqqzqz1 below.                                                                                                                                                                                                                           
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Datain_7zqqzqz(qqnull_params)                                                                                                                                                                                                                          
  {                                                                                                                                                                                                                                                                 
    if ( Datain_7zzopen != 1 )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
#undef QQQMUSTOPEN                                                                                                                                                                                                                                                  
      Datain_7zzopen = 1;                                                                                                                                                                                                                                           
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  }  /* end of zqqzqz */                                                                                                                                                                                                                                            
  /* ----------- zqqzqz1 --------------------------------------------------* 315 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 317 *                                                                                                                                                                                  
   * This routine also opens the execution history file.  It is called                                                                                                                                                                                              
   * automatically if a probe fires and the execution history is not already                                                                                                                                                                                        
   * opened (Datain_7zzopen = 0 ).                                                                                                                                                                                                                                  
   * Because this always works ( it was intended for files with no main program                                                                                                                                                                                     
   * it is now the de facto common way to open the execution history.                                                                                                                                                                                               
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Datain_7zqqzqz1(qqnull_params)                                                                                                                                                                                                                         
  {                                                                                                                                                                                                                                                                 
    if ( Datain_7zzopen != 1 )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
      if ( Datain_7zzopen == 0 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
      Datain_7zzhfil =                                                                                                                                                                                                                                              
           fopen( "Datain_7.exh","w");  /* 12 */                                                                                                                                                                                                                    
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
          Datain_7zzhfil =                                                                                                                                                                                                                                          
               fopen( "Datain_7.exh","a");  /* 13 */                                                                                                                                                                                                                
      }                                                                                                                                                                                                                                                             
      Datain_7zzopen = 1;                                                                                                                                                                                                                                           
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
   * is usually inserted by Datain_7zqzqzq.                                                                                                                                                                                                                         
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Datain_7zzqqzz(int qqqi)                                                                                                                                                                                                                               
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
    {                                                                                                                                                                                                                                                               
    if ( Datain_7zzopen != 1 )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
      Datain_7zqqzqz1();                                                                                                                                                                                                                                            
    }                                                                                                                                                                                                                                                               
    if ( Datain_7zzopen )                                                                                                                                                                                                                                           
    {                                                                                                                                                                                                                                                               
      /* streamed */                                                                                                                                                                                                                                                
      /* unbuffered */                                                                                                                                                                                                                                              
        qqoutput(                                                                                                                                                                                                                                                   
        Datain_7zzhfil,                                                                                                                                                                                                                                             
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
  static int Datain_7zqzqzq(int qqqi)                                                                                                                                                                                                                               
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
      if ( Datain_7zzopen != 1 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
        Datain_7zqqzqz1();                                                                                                                                                                                                                                          
      }                                                                                                                                                                                                                                                             
      /* not compressed */                                                                                                                                                                                                                                          
      /* streamed */                                                                                                                                                                                                                                                
      /* notbuffered */                                                                                                                                                                                                                                             
      qqoutput(Datain_7zzhfil,                                                                                                                                                                                                                                      
        qqqqone, qqqi);                                                                                                                                                                                                                                             
      /* upload the history */                                                                                                                                                                                                                                      
        fclose(Datain_7zzhfil);                                                                                                                                                                                                                                     
        Datain_7zzopen = 2;                                                                                                                                                                                                                                         
      }                                                                                                                                                                                                                                                             
    return(1);                                                                                                                                                                                                                                                      
  } /* end of zqzqzq */                                                                                                                                                                                                                                             
  /*   the following routines should be left alone */                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 354 *                                                                                                                                                                                  
   *            Datain_7zqfqzz                                                                                                                                                                                                                                      
   *        This routine is used for switches.                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Datain_7zqfqzz(int qqqi)                                                                                                                                                                                                                               
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
      int qqql;                                                                                                                                                                                                                                                     
      qqql = qqqi - 1;                                                                                                                                                                                                                                              
      Datain_7zzqqzz(qqql);                                                                                                                                                                                                                                         
      Datain_7zzqqzz(qqqi);                                                                                                                                                                                                                                         
    }                                                                                                                                                                                                                                                               
    return (1);                                                                                                                                                                                                                                                     
  } /* end of zqfqzz */                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 355 *                                                                                                                                                                                  
   *            Datain_7zzzqtz                                                                                                                                                                                                                                      
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is not 0.                                                                                                                                                                                                                 
   *                                                                                                                                                                                                                                                                
   *   qqqa - value of expression                                                                                                                                                                                                                                   
   *   qqqb - jump table index.                                                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Datain_7zzzqtz(int qqqa, int qqqb)                                                                                                                                                                                                                     
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        Datain_7zzqqzz(qqqb) ;                                                                                                                                                                                                                                      
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* end of zzzqtz */                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 356 *                                                                                                                                                                                  
   *            Datain_7zzzqfz                                                                                                                                                                                                                                      
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is 0.                                                                                                                                                                                                                     
   *                                                                                                                                                                                                                                                                
   *  qqqa - value of expression                                                                                                                                                                                                                                    
   *  qqqb - jump table index.                                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Datain_7zzzqfz(int qqqa,int qqqb)                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        return(qqqa);                                                                                                                                                                                                                                               
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
        Datain_7zzqqzz(qqqb);                                                                                                                                                                                                                                       
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* zzzqfz */                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 357 *                                                                                                                                                                                  
   *            Datain_7zzdo17                                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Datain_7zzdo17(                                                                                                                                                                                                                                        
    int a, int b)                                                                                                                                                                                                                                                   
  {                                                                                                                                                                                                                                                                 
    if ( a )                                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
      Datain_7zzqqzz(b-1);                                                                                                                                                                                                                                          
    }                                                                                                                                                                                                                                                               
    else                                                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
      Datain_7zzqqzz(b);                                                                                                                                                                                                                                            
    }                                                                                                                                                                                                                                                               
    return a;                                                                                                                                                                                                                                                       
  } /*  end of zzdo17 */                                                                                                                                                                                                                                            
/* END OF TESTBED INSTRUMENTATION */                                                                                                                                                                                                                                
 
