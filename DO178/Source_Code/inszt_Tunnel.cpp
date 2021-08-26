/*
C++ TESTBED VERSION  : 9.8.6
FILE UNDER TEST  : "C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Tunnel.cpp"
DATE OF ANALYSIS : Wed May 26 15:21:24 2021
*/
/************************************************************************************************************
Tunnel.cpp
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
 static int zzfileid =     14;
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
 static int Tunnel_14zzopen                                                                                      = 0;
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
  static int Tunnel_14zqqzqz(qqnull_params);                                                                                                                                                                                                                        
  static int Tunnel_14zqqzqz1(qqnull_params);                                                                                                                                                                                                                       
  static int Tunnel_14zzqqzz (int qqqi);                                                                                                                                                                                                                            
  static int Tunnel_14zqzqzq (int qqqi);                                                                                                                                                                                                                            
  static int Tunnel_14zzzqtz (int qqqa, int qqqb);                                                                                                                                                                                                                  
  static int Tunnel_14zzzqfz (int qqqa, int qqqb);                                                                                                                                                                                                                  
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
 


class ldra_class_4100030000{ public:  /* 76 */
 ldra_class_4100030000(){ };
 ldra_class_4100030000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Tunnel_14zzqqzz                                                                                     ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Tunnel_14zzqqzz                                                                                     ( from );
                         }  ;};
                    };
class LampAttributes
        :public ldra_class_4100030000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_14;
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
 


class ldra_class_4100040000{ public:  /* 76 */
 ldra_class_4100040000(){ };
 ldra_class_4100040000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Tunnel_14zzqqzz                                                                                     ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Tunnel_14zzqqzz                                                                                     ( from );
                         }  ;};
                    };
class SquareLamp :
        public ldra_class_4100040000, /* 69 */
public LampAttributes
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_14;
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
 


class ldra_class_4100050000{ public:  /* 76 */
 ldra_class_4100050000(){ };
 ldra_class_4100050000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Tunnel_14zzqqzz                                                                                     ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Tunnel_14zzqqzz                                                                                     ( from );
                         }  ;};
                    };
class Lamp
        :public ldra_class_4100050000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_14;
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
 


class ldra_class_4100060000{ public:  /* 76 */
 ldra_class_4100060000(){ };
 ldra_class_4100060000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Tunnel_14zzqqzz                                                                                     ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Tunnel_14zzqqzz                                                                                     ( from );
                         }  ;};
                    };
class Cell
        :public ldra_class_4100060000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_14;
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
 


class ldra_class_4100070000{ public:  /* 76 */
 ldra_class_4100070000(){ };
 ldra_class_4100070000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Tunnel_14zzqqzz                                                                                     ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Tunnel_14zzqqzz                                                                                     ( from );
                         }  ;};
                    };
class Zone
        :public ldra_class_4100070000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_14;
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
 


class ldra_class_4100080000{ public:  /* 76 */
 ldra_class_4100080000(){ };
 ldra_class_4100080000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Tunnel_14zzqqzz                                                                                     ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Tunnel_14zzqqzz                                                                                     ( from );
                         }  ;};
                    };
class Tunnel
        :public ldra_class_4100080000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_14;
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
namespace TunnelData {
 
void
  Tunnel::InitialiseTunnel (
  const Sint_32 ZoneNumber ,
  Sint_32 * pZoneData )
  {
   int iTunnel_14zzqqzz                                                                                     
 = Tunnel_14zzqqzz                                                                                      (       1 ) ; /* 37 */
    TunnelZone [ ZoneNumber ].
    InitialiseZone ( pZoneData , ZoneNumber ) ;
    Tunnel_14zzqqzz                                                                                      (       2 ) ; /* 30 */  
  }
 
void
  Tunnel::AdjustLighting (
  const Float_64 PhotometerDemand ,
  Bool PowerFailure )
  {
   int iTunnel_14zzqqzz                                                                                     
 = Tunnel_14zzqqzz                                                                                      (       3 ) ; /* 37 */
    if
      (
      PowerFailure
      )
 {
      {
 Tunnel_14zzqqzz                                                                                      (       4 ) ; /* 23 */
 
        AdjustEmergencyLighting ( ) ;
      }
    Tunnel_14zzqqzz                                                                                      (      5 ) ; /* 3 */
 }
    else
 {                                                                                                    ;
Tunnel_14zzqqzz                                                                                      (      6 ); /* 2 */
      {
 Tunnel_14zzqqzz                                                                                      (       7 ) ; /* 23 */
 
        AdjustPoweredLighting (
        PhotometerDemand ) ;
      }
 }
    Tunnel_14zzqqzz                                                                                      (       8 ) ; /* 30 */  
  } ;
 
void
  Tunnel::AdjustPoweredLighting (
  const Float_64 PhotometerDemand )
        /* Turn 0-20mA from the Photometer into a percentage demand value. Calculate formulae
        for required outputs based on those demands, and assign the required output values to cells */
  {
   int iTunnel_14zzqqzz                                                                                     
 = Tunnel_14zzqqzz                                                                                      (       9 ) ; /* 37 */
    Sint_32
      j = 0 ;
         //Turn 0-20mA into a percentage
    Sint_32
      PhotometerPercentageDemand =
      ( int ) ( 100.0 * ( PhotometerDemand - 4.0 ) /
      16.0 ) ;
    for
      (
      Sint_32 ZoneCount = 0
      ;
  ( /* 28 */
      ZoneCount < NumZones
  )  /* 7 */
      ;
  ( /* 7 */
      ZoneCount ++
  ,Tunnel_14zzqqzz                                                                                      (      10 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Tunnel_14zzqqzz                                                                                      (      11 ) ; /* 32 */
        TunnelZone [ ZoneCount ].
        CalculateOutputFormula ( PhotometerPercentageDemand ) ;
        TunnelZone [ ZoneCount ].
        AssignPoweredCellsOutput () ;
    Tunnel_14zzqqzz                                                                                      (     12 ) ;} /* 6 */
      }
    Tunnel_14zzqqzz                                                                                      (     13 ) ; /* 5 */
    Tunnel_14zzqqzz                                                                                      (      14 ) ; /* 30 */  
  } ;
 
void
  Tunnel::AdjustEmergencyLighting ( void )
        /* Power failure */
  {
   int iTunnel_14zzqqzz                                                                                     
 = Tunnel_14zzqqzz                                                                                      (      15 ) ; /* 37 */
    for
      (
      Sint_32 ZoneCount = 0
      ;
  ( /* 28 */
      ZoneCount < NumZones
  )  /* 7 */
      ;
  ( /* 7 */
      ZoneCount ++
  ,Tunnel_14zzqqzz                                                                                      (      16 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Tunnel_14zzqqzz                                                                                      (      17 ) ; /* 32 */
        TunnelZone [ ZoneCount ].
        AssignEmergencyCellsOutput () ;
    Tunnel_14zzqqzz                                                                                      (     18 ) ;} /* 6 */
      }
    Tunnel_14zzqqzz                                                                                      (     19 ) ; /* 5 */
    Tunnel_14zzqqzz                                                                                      (      20 ) ; /* 30 */  
  } ;
}
#define qqqbranches     20
#define QQQMAXMCDCSIZE      2
 static FILE * Tunnel_14zzhfil                                                                                      ;
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
  static int Tunnel_14zqqzqz(qqnull_params);                                                                                                                                                                                                                        
  static int Tunnel_14zqqzqz1(qqnull_params);                                                                                                                                                                                                                       
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
   * superceded by Tunnel_14zqqzqz1 below.                                                                                                                                                                                                                          
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Tunnel_14zqqzqz(qqnull_params)                                                                                                                                                                                                                         
  {                                                                                                                                                                                                                                                                 
    if ( Tunnel_14zzopen != 1 )                                                                                                                                                                                                                                     
    {                                                                                                                                                                                                                                                               
#undef QQQMUSTOPEN                                                                                                                                                                                                                                                  
      Tunnel_14zzopen = 1;                                                                                                                                                                                                                                          
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  }  /* end of zqqzqz */                                                                                                                                                                                                                                            
  /* ----------- zqqzqz1 --------------------------------------------------* 315 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 317 *                                                                                                                                                                                  
   * This routine also opens the execution history file.  It is called                                                                                                                                                                                              
   * automatically if a probe fires and the execution history is not already                                                                                                                                                                                        
   * opened (Tunnel_14zzopen = 0 ).                                                                                                                                                                                                                                 
   * Because this always works ( it was intended for files with no main program                                                                                                                                                                                     
   * it is now the de facto common way to open the execution history.                                                                                                                                                                                               
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Tunnel_14zqqzqz1(qqnull_params)                                                                                                                                                                                                                        
  {                                                                                                                                                                                                                                                                 
    if ( Tunnel_14zzopen != 1 )                                                                                                                                                                                                                                     
    {                                                                                                                                                                                                                                                               
      if ( Tunnel_14zzopen == 0 )                                                                                                                                                                                                                                   
      {                                                                                                                                                                                                                                                             
      Tunnel_14zzhfil =                                                                                                                                                                                                                                             
           fopen( "Tunnel_14.exh","w");  /* 12 */                                                                                                                                                                                                                   
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
          Tunnel_14zzhfil =                                                                                                                                                                                                                                         
               fopen( "Tunnel_14.exh","a");  /* 13 */                                                                                                                                                                                                               
      }                                                                                                                                                                                                                                                             
      Tunnel_14zzopen = 1;                                                                                                                                                                                                                                          
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
   * is usually inserted by Tunnel_14zqzqzq.                                                                                                                                                                                                                        
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Tunnel_14zzqqzz(int qqqi)                                                                                                                                                                                                                              
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
    {                                                                                                                                                                                                                                                               
    if ( Tunnel_14zzopen != 1 )                                                                                                                                                                                                                                     
    {                                                                                                                                                                                                                                                               
      Tunnel_14zqqzqz1();                                                                                                                                                                                                                                           
    }                                                                                                                                                                                                                                                               
    if ( Tunnel_14zzopen )                                                                                                                                                                                                                                          
    {                                                                                                                                                                                                                                                               
      /* streamed */                                                                                                                                                                                                                                                
      /* unbuffered */                                                                                                                                                                                                                                              
        qqoutput(                                                                                                                                                                                                                                                   
        Tunnel_14zzhfil,                                                                                                                                                                                                                                            
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
  static int Tunnel_14zqzqzq(int qqqi)                                                                                                                                                                                                                              
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
      if ( Tunnel_14zzopen != 1 )                                                                                                                                                                                                                                   
      {                                                                                                                                                                                                                                                             
        Tunnel_14zqqzqz1();                                                                                                                                                                                                                                         
      }                                                                                                                                                                                                                                                             
      /* not compressed */                                                                                                                                                                                                                                          
      /* streamed */                                                                                                                                                                                                                                                
      /* notbuffered */                                                                                                                                                                                                                                             
      qqoutput(Tunnel_14zzhfil,                                                                                                                                                                                                                                     
        qqqqone, qqqi);                                                                                                                                                                                                                                             
      /* upload the history */                                                                                                                                                                                                                                      
        fclose(Tunnel_14zzhfil);                                                                                                                                                                                                                                    
        Tunnel_14zzopen = 2;                                                                                                                                                                                                                                        
      }                                                                                                                                                                                                                                                             
    return(1);                                                                                                                                                                                                                                                      
  } /* end of zqzqzq */                                                                                                                                                                                                                                             
  /*   the following routines should be left alone */                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 355 *                                                                                                                                                                                  
   *            Tunnel_14zzzqtz                                                                                                                                                                                                                                     
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is not 0.                                                                                                                                                                                                                 
   *                                                                                                                                                                                                                                                                
   *   qqqa - value of expression                                                                                                                                                                                                                                   
   *   qqqb - jump table index.                                                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Tunnel_14zzzqtz(int qqqa, int qqqb)                                                                                                                                                                                                                    
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        Tunnel_14zzqqzz(qqqb) ;                                                                                                                                                                                                                                     
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* end of zzzqtz */                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 356 *                                                                                                                                                                                  
   *            Tunnel_14zzzqfz                                                                                                                                                                                                                                     
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is 0.                                                                                                                                                                                                                     
   *                                                                                                                                                                                                                                                                
   *  qqqa - value of expression                                                                                                                                                                                                                                    
   *  qqqb - jump table index.                                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Tunnel_14zzzqfz(int qqqa,int qqqb)                                                                                                                                                                                                                     
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        return(qqqa);                                                                                                                                                                                                                                               
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
        Tunnel_14zzqqzz(qqqb);                                                                                                                                                                                                                                      
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* zzzqfz */                                                                                                                                                                                                                                                    
/* END OF TESTBED INSTRUMENTATION */                                                                                                                                                                                                                                
 
