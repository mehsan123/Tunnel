/************************************************************************************************************
Config.h

v1.0 Original 23/10/07 Bill Cody 
*************************************************************************************************************/

//types
typedef signed int Sint_32;
typedef double Float_64;
typedef bool Bool;
typedef char Char;

//Latter day #defines
static const Sint_32 NumZones = 5;
static const Sint_32 NumZoneParams = 11;
static const Sint_32 NumSystemParams = 9;
static const Sint_32 NumLampTypes = 2;
static const Sint_32 LampsPerLuminaire = 4;
static const Sint_32 MaxCellsPerZone = 100;
static const Sint_32 MaxLuminairesPerCell=3;
static const Sint_32 IDOffset=100;

static const double MinLampOutput = 0.2;
static const double Small = 0.000001;

enum LampTypeID {Brightest, Dimmest};

