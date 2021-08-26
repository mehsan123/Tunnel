/************************************************************************************************************
SystemData.h

v1.0 Original 23/10/07 Bill Cody 
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
namespace TunnelData
{
	class SystemData
	{
	public:
		Sint_32 mDaysBetweenCleaning;
		Sint_32 mSoiledEfficiency;
		Sint_32 mHighestPercentOutput;
		Sint_32 mLowestPercentOutput;
		Sint_32 mDaysSinceCleaning;
		Sint_32 mExitSignSpacing;
		Sint_32 mSirenSpacing;
		Float_64 mEmergencyLampLumens;
		Sint_32 mLampTypeWatts[NumLampTypes];
		LampType mTheLampType[NumLampTypes];

		//Singleton accessor
		static SystemData *Instance();

		//Accessors
		void InitialiseParams (Sint_32* pSystemDataArray);

		Float_64 GetSoilingFactor(void) const;
		Sint_32 GetLampPowerRequired(LampTypeID ThisLampTypeID, Float_64 LumensRequired) const;
		Float_64 GetLampMaximumLumens(LampTypeID ThisLampTypeID) const;
		Float_64 GetLampMinimumLumens(LampTypeID ThisLampTypeID) const;
		Float_64 GetEmergencyLampLumens(void) const;
		Sint_32 GetDaysBetweenCleaning(void) const;
		Sint_32 GetExitSignSpacing(void) const;
		Sint_32 GetSirenSpacing(void) const;

		void SetDaysSinceCleaning(Sint_32 Days);

	private:
		SystemData();
		SystemData(const SystemData &) {} //No copy
		void operator=(const SystemData &) {} //No copy
	};
}
