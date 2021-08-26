/*
C++ TESTBED VERSION  : 9.8.6
FILE UNDER TEST  : "C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Cell.cpp"
DATE OF ANALYSIS : Wed May 26 15:20:54 2021
*/
/************************************************************************************************************
Cell.cpp
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
#define QQQdo178b
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
 static int zzfileid =      6;
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
 static int Cell_6zzopen                                                                                         = 0;
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
  static int Cell_6zqqzqz(qqnull_params);                                                                                                                                                                                                                           
  static int Cell_6zqqzqz1(qqnull_params);                                                                                                                                                                                                                          
  static int Cell_6zzqqzz (int qqqi);                                                                                                                                                                                                                               
  static int Cell_6zqzqzq (int qqqi);                                                                                                                                                                                                                               
  static int Cell_6zzzqtz (int qqqa, int qqqb);                                                                                                                                                                                                                     
  static int Cell_6zzzqfz (int qqqa, int qqqb);                                                                                                                                                                                                                     
  static int Cell_6zzdo17 (int a, int b);                                                                                                                                                                                                                           
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
#include <iostream>
using std :: cout ;
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
 


class ldra_class_6000030000{ public:  /* 76 */
 ldra_class_6000030000(){ };
 ldra_class_6000030000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Cell_6zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Cell_6zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class LampAttributes
        :public ldra_class_6000030000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_6;
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
 


class ldra_class_6000040000{ public:  /* 76 */
 ldra_class_6000040000(){ };
 ldra_class_6000040000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Cell_6zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Cell_6zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class SquareLamp :
        public ldra_class_6000040000, /* 69 */
public LampAttributes
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_6;
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
 


class ldra_class_6000050000{ public:  /* 76 */
 ldra_class_6000050000(){ };
 ldra_class_6000050000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Cell_6zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Cell_6zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class Lamp
        :public ldra_class_6000050000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_6;
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
 


class ldra_class_6000060000{ public:  /* 76 */
 ldra_class_6000060000(){ };
 ldra_class_6000060000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Cell_6zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Cell_6zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class LampType
        :public ldra_class_6000060000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_6;
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
 


class ldra_class_6000070000{ public:  /* 76 */
 ldra_class_6000070000(){ };
 ldra_class_6000070000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Cell_6zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Cell_6zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class SystemData
        :public ldra_class_6000070000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_6;
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
    ldra_class_6000070000(),  /* 71 c1*/
  mTheLampType ( )
  {
   int iCell_6zzqqzz                                                                                        
 = Cell_6zzqqzz                                                                                         (       1 ) ; /* 37 */
    Cell_6zzqqzz                                                                                         (       2 ) ; /* 30 */  
  }                                        //No copy
 
  void
  operator = ( const SystemData & )
  {
   int iCell_6zzqqzz                                                                                        
 = Cell_6zzqqzz                                                                                         (       3 ) ; /* 37 */
    Cell_6zzqqzz                                                                                         (       4 ) ; /* 30 */  
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
 


class ldra_class_6000080000{ public:  /* 76 */
 ldra_class_6000080000(){ };
 ldra_class_6000080000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Cell_6zzqqzz                                                                                        ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Cell_6zzqqzz                                                                                        ( from );
                         }  ;};
                    };
class Cell
        :public ldra_class_6000080000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_6;
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
namespace TunnelData {
 
  Cell::Cell ( void )
        /* Constructor */
  :
    ldra_class_6000080000(),  /* 71 c1*/
  mThisLamp ( )
  {
   int iCell_6zzqqzz                                                                                        
 = Cell_6zzqqzz                                                                                         (       5 ) ; /* 37 */
    mUniqueCellID = 0 ;
    mLuminaireSetSize = 0 ;
    for
      (
      Sint_32 i = 0
      ;
  ( /* 28 */
      i < NumLampTypes
  )  /* 7 */
      ;
  ( /* 7 */
      i ++
  ,Cell_6zzqqzz                                                                                         (       6 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Cell_6zzqqzz                                                                                         (       7 ) ; /* 32 */
        mLampTypeMaxLumens [ i ] = 0.0 ;
        mLampTypeMinLumens [ i ] = 0.0 ;
        mLampTypeCount [ i ] = 0 ;
    Cell_6zzqqzz                                                                                         (      8 ) ;} /* 6 */
      }
    Cell_6zzqqzz                                                                                         (      9 ) ; /* 5 */
    Cell_6zzqqzz                                                                                         (      10 ) ; /* 30 */  
  } ;
 
Bool
  Cell::InitialiseCell (
  const Sint_32 LuminaireSetSize ,
  const LampTypeID * pLampTypeIDs ,
  const Sint_32 UniqueCellID )
        /* Initialises for both the cell parameters, and the lamps within that cell. */
  {
   int iCell_6zzqqzz                                                                                        
 = Cell_6zzqqzz                                                                                         (      11 ) ; /* 37 */
    Bool
      Okay = true ;
    Sint_32
      TypeCount ;
    Sint_32
      LampCount ;
    Sint_32
      LuminaireCount ;
    mLuminaireSetSize = LuminaireSetSize ;
         //Guard against reinitializing
    for
      (
      TypeCount = 0
      ;
  ( /* 28 */
      TypeCount < NumLampTypes
  )  /* 7 */
      ;
  ( /* 7 */
      TypeCount ++
  ,Cell_6zzqqzz                                                                                         (      12 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Cell_6zzqqzz                                                                                         (      13 ) ; /* 32 */
        mLampTypeCount [ TypeCount ] = 0 ;
    Cell_6zzqqzz                                                                                         (     14 ) ;} /* 6 */
      }
    Cell_6zzqqzz                                                                                         (     15 ) ; /* 5 */
         //pLampTypeIDs holds the types for a single Luminaire.
         //Initialise here for each individual lamp.
 
    Sint_32
      ThisLamp = 0 ;
    for
      (
      LuminaireCount = 0
      ;
  ( /* 28 */
      LuminaireCount < mLuminaireSetSize
  )  /* 7 */
      ;
  ( /* 7 */
      LuminaireCount ++
  ,Cell_6zzqqzz                                                                                         (      16 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Cell_6zzqqzz                                                                                         (      17 ) ; /* 32 */
        for
          (
          LampCount = 0
          ;
  ( /* 28 */
          LampCount < LampsPerLuminaire
  )  /* 7 */
          ;
  ( /* 7 */
          LampCount ++
  ,Cell_6zzqqzz                                                                                         (      18 )) /* 27e */
          )
          {
 { /* 32 */
 int                  QZZZ =   
Cell_6zzqqzz                                                                                         (      19 ) ; /* 32 */
           //Initialise the type IDs
            mLampTypeID [ ThisLamp ] = pLampTypeIDs [ LampCount ] ;
 Cell_6zzqqzz                                                                                         (      20 ) ; /* 23 */
            mThisLamp [ ThisLamp ].
            InitialiseLamp ( mLampTypeID [ ThisLamp ] , IDOffset * UniqueCellID + ThisLamp ,
                GetLampModel (
                ThisLamp )
            ) ;
            ThisLamp ++ ;
    Cell_6zzqqzz                                                                                         (     21 ) ;} /* 6 */
          }
    Cell_6zzqqzz                                                                                         (     22 ) ; /* 5 */
    Cell_6zzqqzz                                                                                         (     23 ) ;} /* 6 */
      }
    Cell_6zzqqzz                                                                                         (     24 ) ; /* 5 */
         //Get the Lumens output for the lamp types, and count how many of each there are per luminaire
    for
      (
      LampCount = 0
      ;
  ( /* 28 */
      LampCount < LampsPerLuminaire
  )  /* 7 */
      ;
  ( /* 7 */
      LampCount ++
  ,Cell_6zzqqzz                                                                                         (      25 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Cell_6zzqqzz                                                                                         (      26 ) ; /* 32 */
        LampTypeID
          ThisType = mLampTypeID [ LampCount ] ;
        if
          (
          0 == mLampTypeCount [ ThisType ]
          )
 {
          {
            mLampTypeMaxLumens [ ThisType ] = mThisLamp [ LampCount ].
            GetMaximumLumens () ;
            mLampTypeMinLumens [ ThisType ] = mThisLamp [ LampCount ].
            GetMinimumLumens () ;
          }
 }                                                                                                   
else                                                                                                
  Cell_6zzqqzz                                                                                         (     27 ) ; /* 4 */
        mLampTypeCount [ ThisType ] ++ ;
    Cell_6zzqqzz                                                                                         (     28 ) ;} /* 6 */
      }
    Cell_6zzqqzz                                                                                         (     29 ) ; /* 5 */
         //Account for the number of luminaires in this cell
    for
      (
      TypeCount = 0
      ;
  ( /* 28 */
      TypeCount < NumLampTypes
  )  /* 7 */
      ;
  ( /* 7 */
      TypeCount ++
  ,Cell_6zzqqzz                                                                                         (      30 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Cell_6zzqqzz                                                                                         (      31 ) ; /* 32 */
        mLampTypeCount [ TypeCount ] = mLampTypeCount [ TypeCount ] * mLuminaireSetSize ;
    Cell_6zzqqzz                                                                                         (     32 ) ;} /* 6 */
      }
    Cell_6zzqqzz                                                                                         (     33 ) ; /* 5 */
    mUniqueCellID = UniqueCellID ;
    Cell_6zzqqzz                                                                                         (      34  ) ; /* 48 */ 
    return
    Okay ;
  } ;
 
void
  Cell::SetEmergencyOutputLevel ( void )
        /* Use only one of the smallest lamps per luminaire, set to its defined emergency demand level,
        to minimize power demands on emergency supplies */
  {
   int iCell_6zzqqzz                                                                                        
 = Cell_6zzqqzz                                                                                         (      35 ) ; /* 37 */
    Bool
      OutputSet = false ;
         //Lamp types are always in decreasing order of output power
    for
      (
      Sint_32 LampCount = 0
      ;
  ( /* 28 */
      LampCount < LampsPerLuminaire * mLuminaireSetSize
  )  /* 7 */
      ;
  ( /* 7 */
      LampCount ++
  ,Cell_6zzqqzz                                                                                         (      36 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Cell_6zzqqzz                                                                                         (      37 ) ; /* 32 */
        LampTypeID
          ThisType = mLampTypeID [ LampCount ] ;
        if
 (  /* 50 */
          (
          
  (bool)Cell_6zzdo17                                                                                         (     /*  81 */ 
          
  Cell_6zzzqfz                                                                                         (     /*  52 */ 
          (
          ThisType == Dimmest
          )
   ? Cell_6zzdo17                                                                                        ( 1,     40) : 
Cell_6zzdo17                                                                                        ( 0,     40) ,      38  )  /*  54 */
          &&
          
  Cell_6zzdo17                                                                                         (     /*  72 */ 
          ! OutputSet
  ? 1 : 0  ,      42  )  /*  73 */
  ? 1 : 0  ,      44  )  /*  82 */
          )
  ) /* 1 */
 {
          {
            mThisLamp [ LampCount ].
            SetLumensOutput (
            SystemData::Instance () ->
                                       GetEmergencyLampLumens ( ) ) ;
            OutputSet = true ;
          }
    Cell_6zzqqzz                                                                                         (     45 ) ; /* 3 */
 }
        else
 {                                                                                                    ;
Cell_6zzqqzz                                                                                         (     46 ); /* 2 */
          {
            mThisLamp [ LampCount ].
            SetLumensOutput ( 0 ) ;
          }
 }
    Cell_6zzqqzz                                                                                         (     47 ) ;} /* 6 */
      }
    Cell_6zzqqzz                                                                                         (     48 ) ; /* 5 */
    Cell_6zzqqzz                                                                                         (      49 ) ; /* 30 */  
  } ;
 
void
  Cell::SetPoweredOutputLevel (
  const Float_64 LumensDemandPerMetre ,
  const Float_64 CellSpacing )
        /* Assess which lamps should be used, leaning on the larger lamps by preference. Where a setting is such that
        all used lamps will not be at maximum output, then those of a similar type will all use a lower setting.
        Once those settings are ascertained, they are assigned to the lamps in Lumens for conversion to power. */
  {
   int iCell_6zzqqzz                                                                                        
 = Cell_6zzqqzz                                                                                         (      50 ) ; /* 37 */
    Float_64
      UnassignedCellOutput ;
    Sint_32
      LampsUsed [ NumLampTypes ] ;
    Float_64
      LumensDemand [ NumLampTypes ] ;
    Sint_32
      TypeCount ;
    Sint_32
      LampCount ;
         //Output required from this cell in Lumens depends on spacing
 Cell_6zzqqzz                                                                                         (      51 ) ; /* 23 */
    UnassignedCellOutput =
      CalculateCellOutput (
      LumensDemandPerMetre , CellSpacing ) ;
         //Assumes highest power first, and assign all full power first.
    for
      (
      TypeCount = 0
      ;
  ( /* 28 */
      TypeCount < NumLampTypes
  )  /* 7 */
      ;
  ( /* 7 */
      TypeCount ++
  ,Cell_6zzqqzz                                                                                         (      52 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Cell_6zzqqzz                                                                                         (      53 ) ; /* 32 */
        LampsUsed [ TypeCount ] = ( int ) ( UnassignedCellOutput /
        mLampTypeMaxLumens [ TypeCount ] ) ;
        if
          (
          LampsUsed [ TypeCount ] > mLampTypeCount [ TypeCount ]
          )
 {
          {
           //Too much demand for this type to handle alone. Use as many as possible.
            LampsUsed [ TypeCount ] = mLampTypeCount [ TypeCount ] ;
          }
 }                                                                                                   
else                                                                                                
  Cell_6zzqqzz                                                                                         (     54 ) ; /* 4 */
        LumensDemand [ TypeCount ] = mLampTypeMaxLumens [ TypeCount ] ;
        UnassignedCellOutput = UnassignedCellOutput - ( LampsUsed [ TypeCount ] * mLampTypeMaxLumens [ TypeCount ] ) ;
    Cell_6zzqqzz                                                                                         (     55 ) ;} /* 6 */
      }
    Cell_6zzqqzz                                                                                         (     56 ) ; /* 5 */
         //Assess what we have left. Find smallest lamp available.
    if
      (
      UnassignedCellOutput > Small
      )
 {
      {
        for
          (
          TypeCount = NumLampTypes - 1
          ;
  ( /* 28 */
          TypeCount >= 0
  )  /* 7 */
          ;
  ( /* 7 */
          TypeCount --
  ,Cell_6zzqqzz                                                                                         (      57 )) /* 27e */
          )
          {
 { /* 32 */
 int                  QZZZ =   
Cell_6zzqqzz                                                                                         (      58 ) ; /* 32 */
            if
              (
              LampsUsed [ TypeCount ] < mLampTypeCount [ TypeCount ]
              )
 {
              {
                if
 (  /* 50 */
                  (
                  
  (bool)Cell_6zzdo17                                                                                         (     /*  81 */ 
                  
  Cell_6zzzqtz                                                                                         (     /*  51 */ 
                  (
                  UnassignedCellOutput > mLampTypeMinLumens [ TypeCount ]
                  )
   ? Cell_6zzdo17                                                                                        ( 1,     61) : 
Cell_6zzdo17                                                                                        ( 0,     61) ,      59  )  /*  54 */
                  ||
                  
  Cell_6zzdo17                                                                                         (     /*  72 */ 
                  ( LampsUsed [ TypeCount ] >= 1
                  )
  ? 1 : 0  ,      63  )  /*  73 */
  ? 1 : 0  ,      65  )  /*  82 */
                  )
  ) /* 1 */
 {
                  {
             //Spread the reduced output over all lamps of this size in use
                    LampsUsed [ TypeCount ] ++ ;
                    LumensDemand [ TypeCount ] = (
                    ( LumensDemand [ TypeCount ] * ( LampsUsed [ TypeCount ] - 1 )
                                                  ) + UnassignedCellOutput ) /
                                                  LampsUsed [ TypeCount ] ;
 Cell_6zzqqzz                                                                                         (      66 ) ; 
goto l100497 ; /* 16 */
                  }
 }                                                                                                   
else                                                                                                
  Cell_6zzqqzz                                                                                         (     67 ) ; /* 4 */
              }
 }                                                                                                   
else                                                                                                
  Cell_6zzqqzz                                                                                         (     68 ) ; /* 4 */
    Cell_6zzqqzz                                                                                         (     69 ) ;} /* 6 */
          }
    Cell_6zzqqzz                                                                                         (     70 ) ; /* 5 */
l100497 : 
 ; /* 18 */
      }
 }                                                                                                   
else                                                                                                
  Cell_6zzqqzz                                                                                         (     71 ) ; /* 4 */
         //Set required output for all
    for
      (
      LampCount = 0
      ;
  ( /* 28 */
      LampCount < LampsPerLuminaire * mLuminaireSetSize
  )  /* 7 */
      ;
  ( /* 7 */
      LampCount ++
  ,Cell_6zzqqzz                                                                                         (      72 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Cell_6zzqqzz                                                                                         (      73 ) ; /* 32 */
        LampTypeID
          ThisType = mLampTypeID [ LampCount ] ;
        if
          (
          LampsUsed [ ThisType ] > 0
          )
 {
          {
           /* LDRA_INSPECTED 5D */
            mThisLamp [ LampCount ].
            SetLumensOutput ( LumensDemand [ ThisType ] ) ;
            LampsUsed [ ThisType ] -- ;
          }
    Cell_6zzqqzz                                                                                         (     74 ) ; /* 3 */
 }
        else
 {                                                                                                    ;
Cell_6zzqqzz                                                                                         (     75 ); /* 2 */
          {
            mThisLamp [ LampCount ].
            SetLumensOutput ( 0 ) ;
          }
 }
    Cell_6zzqqzz                                                                                         (     76 ) ;} /* 6 */
      }
    Cell_6zzqqzz                                                                                         (     77 ) ; /* 5 */
    cout << "Total Cell Demand: " << LumensDemandPerMetre * CellSpacing << " at " << LumensDemandPerMetre << " per metre" << "\n" ;
    Cell_6zzqqzz                                                                                         (      78 ) ; /* 30 */  
  } ;
 
Float_64
  Cell::CalculateCellOutput (
  Float_64 LumensDemandPerMetre ,
  Float_64 CellSpacing )
  {
   int iCell_6zzqqzz                                                                                        
 = Cell_6zzqqzz                                                                                         (      79 ) ; /* 37 */
    LumensDemandPerMetre *= CellSpacing ;
    Cell_6zzqqzz                                                                                         (      80  ) ; /* 48 */ 
    return
    LumensDemandPerMetre ;
  }
 
model
Cell::GetLampModel (
const Sint_32 ThisLamp )
{
   int iCell_6zzqqzz                                                                                        
 = Cell_6zzqqzz                                                                                         (      81 ) ; /* 37 */
  model
    ThisLampModel ;
  Sint_32
    ExitSignSpacing =
    ( SystemData::Instance () ->
                                 GetExitSignSpacing ( ) ) ;
  Sint_32
    SirenSpacing =
    ( SystemData::Instance () ->
                                 GetSirenSpacing ( ) ) ;
  if
 (  /* 50 */
    (
    
  (bool)Cell_6zzdo17                                                                                         (     /*  81 */ 
    
  Cell_6zzzqfz                                                                                         (     /*  52 */ 
    (
    ( ThisLamp %
    ExitSignSpacing ) == 0
    )
   ? Cell_6zzdo17                                                                                        ( 1,     84) : 
Cell_6zzdo17                                                                                        ( 0,     84) ,      82  )  /*  54 */
    &&
    
  Cell_6zzdo17                                                                                         (     /*  72 */ 
    (
    ( ThisLamp %
    SirenSpacing ) == 0
    )
  ? 1 : 0  ,      86  )  /*  73 */
  ? 1 : 0  ,      88  )  /*  82 */
    )
  ) /* 1 */
 {
    {
      ThisLampModel = Duo ;
    }
    Cell_6zzqqzz                                                                                         (     89 ) ; /* 3 */
 }
  else
 {                                                                                                    ;
Cell_6zzqqzz                                                                                         (     90 ); /* 2 */
    {
      if
        (
        ( ThisLamp %
        ExitSignSpacing ) == 0
        )
 {
        {
          ThisLampModel = Guide ;
        }
    Cell_6zzqqzz                                                                                         (     91 ) ; /* 3 */
 }
      else
 {                                                                                                    ;
Cell_6zzqqzz                                                                                         (     92 ); /* 2 */
        {
          if
            (
            ( ThisLamp %
            SirenSpacing ) == 0
            )
 {
            {
              ThisLampModel = Announcer ;
            }
    Cell_6zzqqzz                                                                                         (     93 ) ; /* 3 */
 }
          else
 {                                                                                                    ;
Cell_6zzqqzz                                                                                         (     94 ); /* 2 */
            {
              ThisLampModel = LightSolo ;
            }
 }
        }
 }
    }
 }
    Cell_6zzqqzz                                                                                         (      95  ) ; /* 48 */ 
  return
  ThisLampModel ;
} ;
}
#define qqqbranches     95
#define QQQMAXMCDCSIZE    146
 static FILE * Cell_6zzhfil                                                                                         ;
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
  static int Cell_6zqqzqz(qqnull_params);                                                                                                                                                                                                                           
  static int Cell_6zqqzqz1(qqnull_params);                                                                                                                                                                                                                          
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
   * superceded by Cell_6zqqzqz1 below.                                                                                                                                                                                                                             
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Cell_6zqqzqz(qqnull_params)                                                                                                                                                                                                                            
  {                                                                                                                                                                                                                                                                 
    if ( Cell_6zzopen != 1 )                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
#undef QQQMUSTOPEN                                                                                                                                                                                                                                                  
      Cell_6zzopen = 1;                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  }  /* end of zqqzqz */                                                                                                                                                                                                                                            
  /* ----------- zqqzqz1 --------------------------------------------------* 315 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 317 *                                                                                                                                                                                  
   * This routine also opens the execution history file.  It is called                                                                                                                                                                                              
   * automatically if a probe fires and the execution history is not already                                                                                                                                                                                        
   * opened (Cell_6zzopen = 0 ).                                                                                                                                                                                                                                    
   * Because this always works ( it was intended for files with no main program                                                                                                                                                                                     
   * it is now the de facto common way to open the execution history.                                                                                                                                                                                               
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Cell_6zqqzqz1(qqnull_params)                                                                                                                                                                                                                           
  {                                                                                                                                                                                                                                                                 
    if ( Cell_6zzopen != 1 )                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
      if ( Cell_6zzopen == 0 )                                                                                                                                                                                                                                      
      {                                                                                                                                                                                                                                                             
      Cell_6zzhfil =                                                                                                                                                                                                                                                
           fopen( "Cell_6.exh","w");  /* 12 */                                                                                                                                                                                                                      
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
          Cell_6zzhfil =                                                                                                                                                                                                                                            
               fopen( "Cell_6.exh","a");  /* 13 */                                                                                                                                                                                                                  
      }                                                                                                                                                                                                                                                             
      Cell_6zzopen = 1;                                                                                                                                                                                                                                             
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
   * is usually inserted by Cell_6zqzqzq.                                                                                                                                                                                                                           
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Cell_6zzqqzz(int qqqi)                                                                                                                                                                                                                                 
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
    {                                                                                                                                                                                                                                                               
    if ( Cell_6zzopen != 1 )                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
      Cell_6zqqzqz1();                                                                                                                                                                                                                                              
    }                                                                                                                                                                                                                                                               
    if ( Cell_6zzopen )                                                                                                                                                                                                                                             
    {                                                                                                                                                                                                                                                               
      /* streamed */                                                                                                                                                                                                                                                
      /* unbuffered */                                                                                                                                                                                                                                              
        qqoutput(                                                                                                                                                                                                                                                   
        Cell_6zzhfil,                                                                                                                                                                                                                                               
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
  static int Cell_6zqzqzq(int qqqi)                                                                                                                                                                                                                                 
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
      if ( Cell_6zzopen != 1 )                                                                                                                                                                                                                                      
      {                                                                                                                                                                                                                                                             
        Cell_6zqqzqz1();                                                                                                                                                                                                                                            
      }                                                                                                                                                                                                                                                             
      /* not compressed */                                                                                                                                                                                                                                          
      /* streamed */                                                                                                                                                                                                                                                
      /* notbuffered */                                                                                                                                                                                                                                             
      qqoutput(Cell_6zzhfil,                                                                                                                                                                                                                                        
        qqqqone, qqqi);                                                                                                                                                                                                                                             
      /* upload the history */                                                                                                                                                                                                                                      
        fclose(Cell_6zzhfil);                                                                                                                                                                                                                                       
        Cell_6zzopen = 2;                                                                                                                                                                                                                                           
      }                                                                                                                                                                                                                                                             
    return(1);                                                                                                                                                                                                                                                      
  } /* end of zqzqzq */                                                                                                                                                                                                                                             
  /*   the following routines should be left alone */                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 355 *                                                                                                                                                                                  
   *            Cell_6zzzqtz                                                                                                                                                                                                                                        
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is not 0.                                                                                                                                                                                                                 
   *                                                                                                                                                                                                                                                                
   *   qqqa - value of expression                                                                                                                                                                                                                                   
   *   qqqb - jump table index.                                                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Cell_6zzzqtz(int qqqa, int qqqb)                                                                                                                                                                                                                       
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        Cell_6zzqqzz(qqqb) ;                                                                                                                                                                                                                                        
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* end of zzzqtz */                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 356 *                                                                                                                                                                                  
   *            Cell_6zzzqfz                                                                                                                                                                                                                                        
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is 0.                                                                                                                                                                                                                     
   *                                                                                                                                                                                                                                                                
   *  qqqa - value of expression                                                                                                                                                                                                                                    
   *  qqqb - jump table index.                                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Cell_6zzzqfz(int qqqa,int qqqb)                                                                                                                                                                                                                        
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        return(qqqa);                                                                                                                                                                                                                                               
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
        Cell_6zzqqzz(qqqb);                                                                                                                                                                                                                                         
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* zzzqfz */                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 357 *                                                                                                                                                                                  
   *            Cell_6zzdo17                                                                                                                                                                                                                                        
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Cell_6zzdo17(                                                                                                                                                                                                                                          
    int a, int b)                                                                                                                                                                                                                                                   
  {                                                                                                                                                                                                                                                                 
    if ( a )                                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
      Cell_6zzqqzz(b-1);                                                                                                                                                                                                                                            
    }                                                                                                                                                                                                                                                               
    else                                                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
      Cell_6zzqqzz(b);                                                                                                                                                                                                                                              
    }                                                                                                                                                                                                                                                               
    return a;                                                                                                                                                                                                                                                       
  } /*  end of zzdo17 */                                                                                                                                                                                                                                            
/* END OF TESTBED INSTRUMENTATION */                                                                                                                                                                                                                                
 
