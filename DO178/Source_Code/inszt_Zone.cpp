/*
C++ TESTBED VERSION  : 9.8.6
FILE UNDER TEST  : "C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Zone.cpp"
DATE OF ANALYSIS : Wed May 26 15:21:28 2021
*/
/************************************************************************************************************
Zone.cpp
v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
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
 static int zzfileid =     15;
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
 static int Zone_15zzopen                                                                                        = 0;
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
  static int Zone_15zqqzqz(qqnull_params);                                                                                                                                                                                                                          
  static int Zone_15zqqzqz1(qqnull_params);                                                                                                                                                                                                                         
  static int Zone_15zzqqzz (int qqqi);                                                                                                                                                                                                                              
  static int Zone_15zqzqzq (int qqqi);                                                                                                                                                                                                                              
  static int Zone_15zzzqtz (int qqqa, int qqqb);                                                                                                                                                                                                                    
  static int Zone_15zzzqfz (int qqqa, int qqqb);                                                                                                                                                                                                                    
/* ------------------------------ END OF TESTBED PROTOTYPES -------------------------------- */                                                                                                                                                                     
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
 


class ldra_class_5100030000{ public:  /* 76 */
 ldra_class_5100030000(){ };
 ldra_class_5100030000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Zone_15zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Zone_15zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class LampAttributes
        :public ldra_class_5100030000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_15;
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
 


class ldra_class_5100040000{ public:  /* 76 */
 ldra_class_5100040000(){ };
 ldra_class_5100040000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Zone_15zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Zone_15zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class SquareLamp :
        public ldra_class_5100040000, /* 69 */
public LampAttributes
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_15;
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
 


class ldra_class_5100050000{ public:  /* 76 */
 ldra_class_5100050000(){ };
 ldra_class_5100050000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Zone_15zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Zone_15zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class Lamp
        :public ldra_class_5100050000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_15;
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
 


class ldra_class_5100060000{ public:  /* 76 */
 ldra_class_5100060000(){ };
 ldra_class_5100060000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Zone_15zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Zone_15zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class LampType
        :public ldra_class_5100060000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_15;
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
 


class ldra_class_5100070000{ public:  /* 76 */
 ldra_class_5100070000(){ };
 ldra_class_5100070000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Zone_15zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Zone_15zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class SystemData
        :public ldra_class_5100070000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_15;
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
    ldra_class_5100070000(),  /* 71 c1*/
  mTheLampType ( )
  {
   int iZone_15zzqqzz                                                                                       
 = Zone_15zzqqzz                                                                                        (       1 ) ; /* 37 */
    Zone_15zzqqzz                                                                                        (       2 ) ; /* 30 */  
  }                                        //No copy
 
  void
  operator = ( const SystemData & )
  {
   int iZone_15zzqqzz                                                                                       
 = Zone_15zzqqzz                                                                                        (       3 ) ; /* 37 */
    Zone_15zzqqzz                                                                                        (       4 ) ; /* 30 */  
  }                                            //No copy
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
 


class ldra_class_5100080000{ public:  /* 76 */
 ldra_class_5100080000(){ };
 ldra_class_5100080000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Zone_15zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Zone_15zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class Cell
        :public ldra_class_5100080000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_15;
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
 


class ldra_class_5100090000{ public:  /* 76 */
 ldra_class_5100090000(){ };
 ldra_class_5100090000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Zone_15zzqqzz                                                                                       ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Zone_15zzqqzz                                                                                       ( from );
                         }  ;};
                    };
class Zone
        :public ldra_class_5100090000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_15;
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
namespace TunnelData {
 
  Zone::Zone ( void )
        /* Constructor*/
  :
    ldra_class_5100090000(),  /* 71 c1*/
  mThisCell ( )
  {
   int iZone_15zzqqzz                                                                                       
 = Zone_15zzqqzz                                                                                        (       5 ) ; /* 37 */
    mLength = 0 ;
    mLuminaireSetSize = 0 ;
    mSetSpacing = 0 ;
    for
      (
      Sint_32 i = 0
      ;
  ( /* 28 */
      i < LampsPerLuminaire
  )  /* 7 */
      ;
  ( /* 7 */
      i ++
  ,Zone_15zzqqzz                                                                                        (       6 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Zone_15zzqqzz                                                                                        (       7 ) ; /* 32 */
        mTheLampTypeID [ i ] = Brightest ;
    Zone_15zzqqzz                                                                                        (      8 ) ;} /* 6 */
      }
    Zone_15zzqqzz                                                                                        (      9 ) ; /* 5 */
    mMinimumEntryOutput = 0 ;
    mMaximumEntryOutput = 0 ;
    mMinimumExitOutput = 0 ;
    mMaximumExitOutput = 0 ;
    mFormulaGradient = 0.0 ;
    mFormulaConstant = 0.0 ;
    Zone_15zzqqzz                                                                                        (      10 ) ; /* 30 */  
  } ;
 
void
  Zone::InitialiseZone (
  Sint_32 * pZoneData ,
  const Sint_32 UniqueZoneID )
        /* Initialises both the zone parameters, and the luminaire count in cells */
  {
   int iZone_15zzqqzz                                                                                       
 = Zone_15zzqqzz                                                                                        (      11 ) ; /* 37 */
    Sint_32
      j = 0 ;
    mLength = pZoneData [ j ++ ] ;
    mLuminaireSetSize = pZoneData [ j ++ ] ;
    mSetSpacing = pZoneData [ j ++ ] ;
    for
      (
      Sint_32 i = 0
      ;
  ( /* 28 */
      i < LampsPerLuminaire
  )  /* 7 */
      ;
  ( /* 7 */
      i ++
  ,Zone_15zzqqzz                                                                                        (      12 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Zone_15zzqqzz                                                                                        (      13 ) ; /* 32 */
        mTheLampTypeID [ i ] = ( LampTypeID ) pZoneData [ j ++ ] ;
    Zone_15zzqqzz                                                                                        (     14 ) ;} /* 6 */
      }
    Zone_15zzqqzz                                                                                        (     15 ) ; /* 5 */
    mMinimumEntryOutput = pZoneData [ j ++ ] ;
    mMaximumEntryOutput = pZoneData [ j ++ ] ;
    mMinimumExitOutput = pZoneData [ j ++ ] ;
    mMaximumExitOutput = pZoneData [ j ++ ] ;
         //Initialise Luminaire count in cells
 
    Sint_32
      TotalCells = mLength /
                   mSetSpacing ;
    for
      (
      Sint_32 CellCount = 0
      ;
  ( /* 28 */
      CellCount < TotalCells
  )  /* 7 */
      ;
  ( /* 7 */
      CellCount ++
  ,Zone_15zzqqzz                                                                                        (      16 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Zone_15zzqqzz                                                                                        (      17 ) ; /* 32 */
        mThisCell [ CellCount ].
        InitialiseCell ( mLuminaireSetSize , mTheLampTypeID , IDOffset * UniqueZoneID + CellCount ) ;
    Zone_15zzqqzz                                                                                        (     18 ) ;} /* 6 */
      }
    Zone_15zzqqzz                                                                                        (     19 ) ; /* 5 */
    Zone_15zzqqzz                                                                                        (      20 ) ; /* 30 */  
  } ;
 
Bool
  Zone::CalculateOutputFormula (
  const Sint_32 PercentageDemand )
        /* Calculates formula for required output in lumens/metre in the format y=mx+c, where
        y=output, x=distance from beginning of zone, m=gradient, c=constant (offset)
        with appropriate adjustment for soiling etc */
  {
   int iZone_15zzqqzz                                                                                       
 = Zone_15zzqqzz                                                                                        (      21 ) ; /* 37 */
    Bool
      Okay = true ;
    Float_64
      ActualEntryOutput = 0.0 ;
    Float_64
      ActualExitOutput = 0.0 ;
    Float_64
      SoilingFactor = 0.0 ;
         //Calculate required output at zone boundaries
    ActualEntryOutput = ( mMinimumEntryOutput + (
    ( mMaximumEntryOutput - mMinimumEntryOutput ) * PercentageDemand /
    100.0 )
                        ) * ( SystemData::Instance () ->
                                                         GetSoilingFactor ( ) ) ;
    ActualExitOutput = ( mMinimumExitOutput + (
    ( mMaximumExitOutput - mMinimumExitOutput ) * PercentageDemand /
    100.0 )
                       ) * ( SystemData::Instance () ->
                                                        GetSoilingFactor ( ) ) ;
         //Derive formula parameters "m" and "c" viz. y=mx+c
    if
      (
      mLength > Small
      )
 {
      {
        mFormulaGradient = ( ActualExitOutput - ActualEntryOutput ) /
        mLength ;
        mFormulaConstant = ActualEntryOutput ;
      }
    Zone_15zzqqzz                                                                                        (     22 ) ; /* 3 */
 }
    else
 {                                                                                                    ;
Zone_15zzqqzz                                                                                        (     23 ); /* 2 */
      {
        Okay = false ;
      }
 }
    Zone_15zzqqzz                                                                                        (      24  ) ; /* 48 */ 
    return
    Okay ;
  } ;
 
Bool
  Zone::AssignPoweredCellsOutput ( void )
        /* For each cell, calculate distance from zone start to derive lumens output required from line formula */
  {
   int iZone_15zzqqzz                                                                                       
 = Zone_15zzqqzz                                                                                        (      25 ) ; /* 37 */
    Sint_32
      TotalCells ;
    Bool
      Okay = true ;
    if
      (
      mSetSpacing > 0
      )
 {
      {
        TotalCells = mLength /
        mSetSpacing ;
        for
          (
          Sint_32 CellCount = 0
          ;
  ( /* 28 */
          CellCount < TotalCells
  )  /* 7 */
          ;
  ( /* 7 */
          CellCount ++
  ,Zone_15zzqqzz                                                                                        (      26 )) /* 27e */
          )
          {
 { /* 32 */
 int                  QZZZ =   
Zone_15zzqqzz                                                                                        (      27 ) ; /* 32 */
            Float_64
              LumensOutput = CellCount * mSetSpacing * mFormulaGradient + mFormulaConstant ;
            mThisCell [ CellCount ].
            SetPoweredOutputLevel ( LumensOutput , mSetSpacing ) ;
    Zone_15zzqqzz                                                                                        (     28 ) ;} /* 6 */
          }
    Zone_15zzqqzz                                                                                        (     29 ) ; /* 5 */
      }
    Zone_15zzqqzz                                                                                        (     30 ) ; /* 3 */
 }
    else
 {                                                                                                    ;
Zone_15zzqqzz                                                                                        (     31 ); /* 2 */
      {
        Okay = false ;
      }
 }
    Zone_15zzqqzz                                                                                        (      32  ) ; /* 48 */ 
    return
    Okay ;
  } ;
 
Bool
  Zone::AssignEmergencyCellsOutput ( void )
        /* Power failure */
  {
   int iZone_15zzqqzz                                                                                       
 = Zone_15zzqqzz                                                                                        (      33 ) ; /* 37 */
    Sint_32
      TotalCells ;
    Bool
      Okay = true ;
    if
      (
      mSetSpacing > 0
      )
 {
      {
        TotalCells = mLength /
        mSetSpacing ;
        for
          (
          Sint_32 CellCount = 0
          ;
  ( /* 28 */
          CellCount < TotalCells
  )  /* 7 */
          ;
  ( /* 7 */
          CellCount ++
  ,Zone_15zzqqzz                                                                                        (      34 )) /* 27e */
          )
          {
 { /* 32 */
 int                  QZZZ =   
Zone_15zzqqzz                                                                                        (      35 ) ; /* 32 */
            mThisCell [ CellCount ].
            SetEmergencyOutputLevel () ;
    Zone_15zzqqzz                                                                                        (     36 ) ;} /* 6 */
          }
    Zone_15zzqqzz                                                                                        (     37 ) ; /* 5 */
      }
    Zone_15zzqqzz                                                                                        (     38 ) ; /* 3 */
 }
    else
 {                                                                                                    ;
Zone_15zzqqzz                                                                                        (     39 ); /* 2 */
      {
        Okay = false ;
      }
 }
    Zone_15zzqqzz                                                                                        (      40  ) ; /* 48 */ 
    return
    Okay ;
  } ;
}
#define qqqbranches     40
#define QQQMAXMCDCSIZE      2
 static FILE * Zone_15zzhfil                                                                                        ;
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
  static int Zone_15zqqzqz(qqnull_params);                                                                                                                                                                                                                          
  static int Zone_15zqqzqz1(qqnull_params);                                                                                                                                                                                                                         
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
   * superceded by Zone_15zqqzqz1 below.                                                                                                                                                                                                                            
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Zone_15zqqzqz(qqnull_params)                                                                                                                                                                                                                           
  {                                                                                                                                                                                                                                                                 
    if ( Zone_15zzopen != 1 )                                                                                                                                                                                                                                       
    {                                                                                                                                                                                                                                                               
#undef QQQMUSTOPEN                                                                                                                                                                                                                                                  
      Zone_15zzopen = 1;                                                                                                                                                                                                                                            
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  }  /* end of zqqzqz */                                                                                                                                                                                                                                            
  /* ----------- zqqzqz1 --------------------------------------------------* 315 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 317 *                                                                                                                                                                                  
   * This routine also opens the execution history file.  It is called                                                                                                                                                                                              
   * automatically if a probe fires and the execution history is not already                                                                                                                                                                                        
   * opened (Zone_15zzopen = 0 ).                                                                                                                                                                                                                                   
   * Because this always works ( it was intended for files with no main program                                                                                                                                                                                     
   * it is now the de facto common way to open the execution history.                                                                                                                                                                                               
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Zone_15zqqzqz1(qqnull_params)                                                                                                                                                                                                                          
  {                                                                                                                                                                                                                                                                 
    if ( Zone_15zzopen != 1 )                                                                                                                                                                                                                                       
    {                                                                                                                                                                                                                                                               
      if ( Zone_15zzopen == 0 )                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
      Zone_15zzhfil =                                                                                                                                                                                                                                               
           fopen( "Zone_15.exh","w");  /* 12 */                                                                                                                                                                                                                     
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
          Zone_15zzhfil =                                                                                                                                                                                                                                           
               fopen( "Zone_15.exh","a");  /* 13 */                                                                                                                                                                                                                 
      }                                                                                                                                                                                                                                                             
      Zone_15zzopen = 1;                                                                                                                                                                                                                                            
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
   * is usually inserted by Zone_15zqzqzq.                                                                                                                                                                                                                          
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Zone_15zzqqzz(int qqqi)                                                                                                                                                                                                                                
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
    {                                                                                                                                                                                                                                                               
    if ( Zone_15zzopen != 1 )                                                                                                                                                                                                                                       
    {                                                                                                                                                                                                                                                               
      Zone_15zqqzqz1();                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    if ( Zone_15zzopen )                                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
      /* streamed */                                                                                                                                                                                                                                                
      /* unbuffered */                                                                                                                                                                                                                                              
        qqoutput(                                                                                                                                                                                                                                                   
        Zone_15zzhfil,                                                                                                                                                                                                                                              
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
  static int Zone_15zqzqzq(int qqqi)                                                                                                                                                                                                                                
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
      if ( Zone_15zzopen != 1 )                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        Zone_15zqqzqz1();                                                                                                                                                                                                                                           
      }                                                                                                                                                                                                                                                             
      /* not compressed */                                                                                                                                                                                                                                          
      /* streamed */                                                                                                                                                                                                                                                
      /* notbuffered */                                                                                                                                                                                                                                             
      qqoutput(Zone_15zzhfil,                                                                                                                                                                                                                                       
        qqqqone, qqqi);                                                                                                                                                                                                                                             
      /* upload the history */                                                                                                                                                                                                                                      
        fclose(Zone_15zzhfil);                                                                                                                                                                                                                                      
        Zone_15zzopen = 2;                                                                                                                                                                                                                                          
      }                                                                                                                                                                                                                                                             
    return(1);                                                                                                                                                                                                                                                      
  } /* end of zqzqzq */                                                                                                                                                                                                                                             
  /*   the following routines should be left alone */                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 355 *                                                                                                                                                                                  
   *            Zone_15zzzqtz                                                                                                                                                                                                                                       
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is not 0.                                                                                                                                                                                                                 
   *                                                                                                                                                                                                                                                                
   *   qqqa - value of expression                                                                                                                                                                                                                                   
   *   qqqb - jump table index.                                                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Zone_15zzzqtz(int qqqa, int qqqb)                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        Zone_15zzqqzz(qqqb) ;                                                                                                                                                                                                                                       
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* end of zzzqtz */                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 356 *                                                                                                                                                                                  
   *            Zone_15zzzqfz                                                                                                                                                                                                                                       
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is 0.                                                                                                                                                                                                                     
   *                                                                                                                                                                                                                                                                
   *  qqqa - value of expression                                                                                                                                                                                                                                    
   *  qqqb - jump table index.                                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Zone_15zzzqfz(int qqqa,int qqqb)                                                                                                                                                                                                                       
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        return(qqqa);                                                                                                                                                                                                                                               
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
        Zone_15zzqqzz(qqqb);                                                                                                                                                                                                                                        
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* zzzqfz */                                                                                                                                                                                                                                                    
/* END OF TESTBED INSTRUMENTATION */                                                                                                                                                                                                                                
 
