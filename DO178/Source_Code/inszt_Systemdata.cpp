/*
C++ TESTBED VERSION  : 9.8.6
FILE UNDER TEST  : "C:\_LDRA_Workarea\986\Examples\Toolsuite\Tunnel_5.2\DO178\Source_Code\Systemdata.cpp"
DATE OF ANALYSIS : Wed May 26 15:21:21 2021
*/
/************************************************************************************************************
SystemData.cpp
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
 static int zzfileid =     13;
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
 static int Systemdata_13zzopen                                                                                  = 0;
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
  static int Systemdata_13zqqzqz(qqnull_params);                                                                                                                                                                                                                    
  static int Systemdata_13zqqzqz1(qqnull_params);                                                                                                                                                                                                                   
  static int Systemdata_13zzqqzz (int qqqi);                                                                                                                                                                                                                        
  static int Systemdata_13zqzqzq (int qqqi);                                                                                                                                                                                                                        
  static int Systemdata_13zzzqtz (int qqqa, int qqqb);                                                                                                                                                                                                              
  static int Systemdata_13zzzqfz (int qqqa, int qqqb);                                                                                                                                                                                                              
  static int Systemdata_13zzdo17 (int a, int b);                                                                                                                                                                                                                    
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
 


class ldra_class_3100030000{ public:  /* 76 */
 ldra_class_3100030000(){ };
 ldra_class_3100030000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Systemdata_13zzqqzz                                                                                 ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Systemdata_13zzqqzz                                                                                 ( from );
                         }  ;};
                    };
class LampAttributes
        :public ldra_class_3100030000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_13;
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
 


class ldra_class_3100040000{ public:  /* 76 */
 ldra_class_3100040000(){ };
 ldra_class_3100040000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Systemdata_13zzqqzz                                                                                 ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Systemdata_13zzqqzz                                                                                 ( from );
                         }  ;};
                    };
class SquareLamp :
        public ldra_class_3100040000, /* 69 */
public LampAttributes
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_13;
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
 


class ldra_class_3100050000{ public:  /* 76 */
 ldra_class_3100050000(){ };
 ldra_class_3100050000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Systemdata_13zzqqzz                                                                                 ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Systemdata_13zzqqzz                                                                                 ( from );
                         }  ;};
                    };
class LampType
        :public ldra_class_3100050000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_13;
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
 


class ldra_class_3100060000{ public:  /* 76 */
 ldra_class_3100060000(){ };
 ldra_class_3100060000(int i, char * s){ int from,to,j,k;
  sscanf(s,"%d",&to);   s += 7; j = i - 1;
  Systemdata_13zzqqzz                                                                                 ( to );
  for( k = 1; k <= j; k++){
  sscanf(s,"%d",&from); s += 7;
  Systemdata_13zzqqzz                                                                                 ( from );
                         }  ;};
                    };
class SystemData
        :public ldra_class_3100060000 /* 75 */
{
#if defined(ldra_qq_tbrun)
 friend class ldra_driver_13;
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
    ldra_class_3100060000(),  /* 71 c1*/
  mTheLampType ( )
  {
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (       1 ) ; /* 37 */
    Systemdata_13zzqqzz                                                                                  (       2 ) ; /* 30 */  
  }                                        //No copy
 
  void
  operator = ( const SystemData & )
  {
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (       3 ) ; /* 37 */
    Systemdata_13zzqqzz                                                                                  (       4 ) ; /* 30 */  
  }                                            //No copy
} ;
}
/*   CLOSE_FILE Include File */
namespace TunnelData {
 
SystemData *
SystemData::Instance()
{
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (       5 ) ; /* 37 */
         //This method is the one and only way of getting hold
         //of the one and only instance of a SystemData object.
    static   /* type 26 */ 
 int                                                                                                  ZZ13100191 = (
 Systemdata_13zzqqzz                                                                                  (       6 ) * /* 26 + 23 */
  1 ) ; /* 26 */
  static SystemData
    singleton ;                       //This is the one-and-only instance
    Systemdata_13zzqqzz                                                                                  (       7  ) ; /* 48 */ 
  return
  & singleton ;             //return it
}
 
  SystemData::SystemData() :
    ldra_class_3100060000(),  /* 71 c1*/
  mTheLampType ( )
  {
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (       8 ) ; /* 37 */
    mExitSignSpacing = 0 ;
    mSirenSpacing = 0 ;
    mDaysBetweenCleaning = 0 ;
    mSoiledEfficiency = 0 ;
    mHighestPercentOutput = 0 ;
    mLowestPercentOutput = 0 ;
    mEmergencyLampLumens = 0.0 ;
    for
      (
      Sint_32 TypeCount = 0
      ;
  ( /* 28 */
      TypeCount < NumLampTypes
  )  /* 7 */
      ;
  ( /* 7 */
      TypeCount ++
  ,Systemdata_13zzqqzz                                                                                  (       9 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Systemdata_13zzqqzz                                                                                  (      10 ) ; /* 32 */
        mLampTypeWatts [ TypeCount ] = 0 ;
        mTheLampType [ TypeCount ].
        InitialiseLampType ( mHighestPercentOutput , mLowestPercentOutput , mLampTypeWatts [ TypeCount ] ) ;
    Systemdata_13zzqqzz                                                                                  (     11 ) ;} /* 6 */
      }
    Systemdata_13zzqqzz                                                                                  (     12 ) ; /* 5 */
    Systemdata_13zzqqzz                                                                                  (      13 ) ; /* 30 */  
  }
 
void
  SystemData::InitialiseParams (
  Sint_32 * pSystemDataArray )
  {
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (      14 ) ; /* 37 */
    Sint_32
      ElementCount = 0 ;
    mExitSignSpacing = pSystemDataArray [ ElementCount ++ ] ;
    mSirenSpacing = pSystemDataArray [ ElementCount ++ ] ;
    mDaysBetweenCleaning = pSystemDataArray [ ElementCount ++ ] ;
    mSoiledEfficiency = pSystemDataArray [ ElementCount ++ ] ;
    mHighestPercentOutput = pSystemDataArray [ ElementCount ++ ] ;
    mLowestPercentOutput = pSystemDataArray [ ElementCount ++ ] ;
    mEmergencyLampLumens = ( Float_64 ) ( pSystemDataArray [ ElementCount ++ ] ) ;
    for
      (
      Sint_32 TypeCount = 0
      ;
  ( /* 28 */
      TypeCount < NumLampTypes
  )  /* 7 */
      ;
  ( /* 7 */
      TypeCount ++
  ,Systemdata_13zzqqzz                                                                                  (      15 )) /* 27e */
      )
      {
 { /* 32 */
 int                  QZZZ =   
Systemdata_13zzqqzz                                                                                  (      16 ) ; /* 32 */
        mLampTypeWatts [ TypeCount ] = pSystemDataArray [ ElementCount ++ ] ;
        mTheLampType [ TypeCount ].
        InitialiseLampType ( mHighestPercentOutput , mLowestPercentOutput , mLampTypeWatts [ TypeCount ] ) ;
    Systemdata_13zzqqzz                                                                                  (     17 ) ;} /* 6 */
      }
    Systemdata_13zzqqzz                                                                                  (     18 ) ; /* 5 */
    Systemdata_13zzqqzz                                                                                  (      19 ) ; /* 30 */  
  } ;
/*
        Float_64 SystemData::GetSoilingFactor(void) const
        {
         Float_64 SoilingFactor=1.0;
         Float_64 SoiledEfficiency=(Float_64)mSoiledEfficiency/100.0;
         //Calculate percentage efficiency after the days elapsed since last clean
         if (mDaysBetweenCleaning>0)
          SoiledEfficiency=mSoiledEfficiency+(100-mSoiledEfficiency)*((Float_64)(mDaysBetweenCleaning-mDaysSinceCleaning)/mDaysBetweenCleaning);
         //Derive multiplication factor due to soiling
         if (SoiledEfficiency>Small)
          SoilingFactor=100.00/SoiledEfficiency;
         return SoilingFactor;
        };
*/
//Corrected algorithm
 
Float_64
  SystemData::GetSoilingFactor ( void ) const
  {
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (      20 ) ; /* 37 */
    Float_64
      SoilingFactor = 1.0 ;
    Float_64
      SoiledEfficiency =
      ( Float_64 ) mSoiledEfficiency /
      100.0 ;
         //Calculate percentage efficiency after the days elapsed since last clean
    if
 (  /* 50 */
      (
      
  (bool)Systemdata_13zzdo17                                                                                  (     /*  81 */ 
      
  Systemdata_13zzzqfz                                                                                  (     /*  52 */ 
      mDaysBetweenCleaning > 0
   ? Systemdata_13zzdo17                                                                                 ( 1,     23) : 
Systemdata_13zzdo17                                                                                 ( 0,     23) ,      21  )  /*  54 */
      &&
      
  Systemdata_13zzdo17                                                                                  (     /*  72 */ 
      SoiledEfficiency > Small
  ? 1 : 0  ,      25  )  /*  73 */
  ? 1 : 0  ,      27  )  /*  82 */
      )
  ) /* 1 */
 {
      {
        SoilingFactor = 1.0 + (
        (
        ( 1.0 /
        SoiledEfficiency ) - 1.0 ) /
        (
        ( Float_64 ) mDaysBetweenCleaning ) * ( Float_64 ) mDaysSinceCleaning ) ;
      }
 }                                                                                                   
else                                                                                                
  Systemdata_13zzqqzz                                                                                  (     28 ) ; /* 4 */
    Systemdata_13zzqqzz                                                                                  (      29  ) ; /* 48 */ 
    return
    SoilingFactor ;
  }
 
Sint_32
  SystemData::GetLampPowerRequired (
  const LampTypeID ThisLampTypeID ,
  const Float_64 LumensRequired ) const
  {
typedef Sint_32  zzqtype;
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (      30 ) ; /* 37 */
 qqswitchyy();
   zzqtype  Systemdata_13izzzqq =
    mTheLampType [ ThisLampTypeID ].
    GetPowerRequired ( LumensRequired ) ;
 
 qqswitchyy();
    Systemdata_13zzqqzz                                                                                  (      31 ) ; /* 30 */  
    ;
return ( Systemdata_13izzzqq );
  } ;
 
Float_64
  SystemData::GetLampMaximumLumens (
  const LampTypeID ThisLampTypeID ) const
  {
typedef Float_64  zzqtype;
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (      32 ) ; /* 37 */
 qqswitchyy();
   zzqtype  Systemdata_13izzzqq =
    mTheLampType [ ThisLampTypeID ].
    GetMaximumLumens () ;
 
 qqswitchyy();
    Systemdata_13zzqqzz                                                                                  (      33 ) ; /* 30 */  
    ;
return ( Systemdata_13izzzqq );
  } ;
 
Float_64
  SystemData::GetLampMinimumLumens (
  const LampTypeID ThisLampTypeID ) const
  {
typedef Float_64  zzqtype;
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (      34 ) ; /* 37 */
 qqswitchyy();
   zzqtype  Systemdata_13izzzqq =
    mTheLampType [ ThisLampTypeID ].
    GetMinimumLumens () ;
 
 qqswitchyy();
    Systemdata_13zzqqzz                                                                                  (      35 ) ; /* 30 */  
    ;
return ( Systemdata_13izzzqq );
  } ;
 
Float_64
  SystemData::GetEmergencyLampLumens() const
  {
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (      36 ) ; /* 37 */
    Systemdata_13zzqqzz                                                                                  (      37  ) ; /* 48 */ 
    return
    mEmergencyLampLumens ;
  } ;
 
void
  SystemData::SetDaysSinceCleaning (
  const Sint_32 Days )
  {
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (      38 ) ; /* 37 */
    mDaysSinceCleaning = Days ;
    Systemdata_13zzqqzz                                                                                  (      39 ) ; /* 30 */  
  } ;
 
Sint_32
  SystemData::GetDaysBetweenCleaning ( void ) const
  {
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (      40 ) ; /* 37 */
    Systemdata_13zzqqzz                                                                                  (      41  ) ; /* 48 */ 
    return
    mDaysBetweenCleaning ;
  } ;
 
Sint_32
  SystemData::GetExitSignSpacing ( void ) const
  {
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (      42 ) ; /* 37 */
    Systemdata_13zzqqzz                                                                                  (      43  ) ; /* 48 */ 
    return
    mExitSignSpacing ;
  } ;
 
Sint_32
  SystemData::GetSirenSpacing ( void ) const
  {
   int iSystemdata_13zzqqzz                                                                                 
 = Systemdata_13zzqqzz                                                                                  (      44 ) ; /* 37 */
    Systemdata_13zzqqzz                                                                                  (      45  ) ; /* 48 */ 
    return
    mSirenSpacing ;
  } ;
}
#define qqqbranches     45
#define QQQMAXMCDCSIZE     74
 static FILE * Systemdata_13zzhfil                                                                                  ;
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
  static int Systemdata_13zqqzqz(qqnull_params);                                                                                                                                                                                                                    
  static int Systemdata_13zqqzqz1(qqnull_params);                                                                                                                                                                                                                   
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
   * superceded by Systemdata_13zqqzqz1 below.                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Systemdata_13zqqzqz(qqnull_params)                                                                                                                                                                                                                     
  {                                                                                                                                                                                                                                                                 
    if ( Systemdata_13zzopen != 1 )                                                                                                                                                                                                                                 
    {                                                                                                                                                                                                                                                               
#undef QQQMUSTOPEN                                                                                                                                                                                                                                                  
      Systemdata_13zzopen = 1;                                                                                                                                                                                                                                      
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  }  /* end of zqqzqz */                                                                                                                                                                                                                                            
  /* ----------- zqqzqz1 --------------------------------------------------* 315 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 317 *                                                                                                                                                                                  
   * This routine also opens the execution history file.  It is called                                                                                                                                                                                              
   * automatically if a probe fires and the execution history is not already                                                                                                                                                                                        
   * opened (Systemdata_13zzopen = 0 ).                                                                                                                                                                                                                             
   * Because this always works ( it was intended for files with no main program                                                                                                                                                                                     
   * it is now the de facto common way to open the execution history.                                                                                                                                                                                               
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Systemdata_13zqqzqz1(qqnull_params)                                                                                                                                                                                                                    
  {                                                                                                                                                                                                                                                                 
    if ( Systemdata_13zzopen != 1 )                                                                                                                                                                                                                                 
    {                                                                                                                                                                                                                                                               
      if ( Systemdata_13zzopen == 0 )                                                                                                                                                                                                                               
      {                                                                                                                                                                                                                                                             
      Systemdata_13zzhfil =                                                                                                                                                                                                                                         
           fopen( "Systemdata_13.exh","w");  /* 12 */                                                                                                                                                                                                               
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
          Systemdata_13zzhfil =                                                                                                                                                                                                                                     
               fopen( "Systemdata_13.exh","a");  /* 13 */                                                                                                                                                                                                           
      }                                                                                                                                                                                                                                                             
      Systemdata_13zzopen = 1;                                                                                                                                                                                                                                      
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
   * is usually inserted by Systemdata_13zqzqzq.                                                                                                                                                                                                                    
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Systemdata_13zzqqzz(int qqqi)                                                                                                                                                                                                                          
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
    {                                                                                                                                                                                                                                                               
    if ( Systemdata_13zzopen != 1 )                                                                                                                                                                                                                                 
    {                                                                                                                                                                                                                                                               
      Systemdata_13zqqzqz1();                                                                                                                                                                                                                                       
    }                                                                                                                                                                                                                                                               
    if ( Systemdata_13zzopen )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
      /* streamed */                                                                                                                                                                                                                                                
      /* unbuffered */                                                                                                                                                                                                                                              
        qqoutput(                                                                                                                                                                                                                                                   
        Systemdata_13zzhfil,                                                                                                                                                                                                                                        
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
  static int Systemdata_13zqzqzq(int qqqi)                                                                                                                                                                                                                          
  {                                                                                                                                                                                                                                                                 
    if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                    
      {                                                                                                                                                                                                                                                             
      if ( Systemdata_13zzopen != 1 )                                                                                                                                                                                                                               
      {                                                                                                                                                                                                                                                             
        Systemdata_13zqqzqz1();                                                                                                                                                                                                                                     
      }                                                                                                                                                                                                                                                             
      /* not compressed */                                                                                                                                                                                                                                          
      /* streamed */                                                                                                                                                                                                                                                
      /* notbuffered */                                                                                                                                                                                                                                             
      qqoutput(Systemdata_13zzhfil,                                                                                                                                                                                                                                 
        qqqqone, qqqi);                                                                                                                                                                                                                                             
      /* upload the history */                                                                                                                                                                                                                                      
        fclose(Systemdata_13zzhfil);                                                                                                                                                                                                                                
        Systemdata_13zzopen = 2;                                                                                                                                                                                                                                    
      }                                                                                                                                                                                                                                                             
    return(1);                                                                                                                                                                                                                                                      
  } /* end of zqzqzq */                                                                                                                                                                                                                                             
  /*   the following routines should be left alone */                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 355 *                                                                                                                                                                                  
   *            Systemdata_13zzzqtz                                                                                                                                                                                                                                 
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is not 0.                                                                                                                                                                                                                 
   *                                                                                                                                                                                                                                                                
   *   qqqa - value of expression                                                                                                                                                                                                                                   
   *   qqqb - jump table index.                                                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Systemdata_13zzzqtz(int qqqa, int qqqb)                                                                                                                                                                                                                
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
  {                                                                                                                                                                                                                                                                 
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        Systemdata_13zzqqzz(qqqb) ;                                                                                                                                                                                                                                 
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* end of zzzqtz */                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 356 *                                                                                                                                                                                  
   *            Systemdata_13zzzqfz                                                                                                                                                                                                                                 
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is 0.                                                                                                                                                                                                                     
   *                                                                                                                                                                                                                                                                
   *  qqqa - value of expression                                                                                                                                                                                                                                    
   *  qqqb - jump table index.                                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Systemdata_13zzzqfz(int qqqa,int qqqb)                                                                                                                                                                                                                 
  {                                                                                                                                                                                                                                                                 
  if ( qqswitchgetxx () == 0 )                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                               
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        return(qqqa);                                                                                                                                                                                                                                               
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
        Systemdata_13zzqqzz(qqqb);                                                                                                                                                                                                                                  
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* zzzqfz */                                                                                                                                                                                                                                                    
  /* ----------------------------------------------------------------------* 357 *                                                                                                                                                                                  
   *            Systemdata_13zzdo17                                                                                                                                                                                                                                 
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int Systemdata_13zzdo17(                                                                                                                                                                                                                                   
    int a, int b)                                                                                                                                                                                                                                                   
  {                                                                                                                                                                                                                                                                 
    if ( a )                                                                                                                                                                                                                                                        
    {                                                                                                                                                                                                                                                               
      Systemdata_13zzqqzz(b-1);                                                                                                                                                                                                                                     
    }                                                                                                                                                                                                                                                               
    else                                                                                                                                                                                                                                                            
    {                                                                                                                                                                                                                                                               
      Systemdata_13zzqqzz(b);                                                                                                                                                                                                                                       
    }                                                                                                                                                                                                                                                               
    return a;                                                                                                                                                                                                                                                       
  } /*  end of zzdo17 */                                                                                                                                                                                                                                            
/* END OF TESTBED INSTRUMENTATION */                                                                                                                                                                                                                                
 
