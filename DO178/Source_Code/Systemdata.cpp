/************************************************************************************************************
SystemData.cpp

v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/

#include "Config.h"
#include "Lampmodel.h"
#include "Lamptype.h"
#include "Systemdata.h"

namespace TunnelData
{
	SystemData* SystemData::Instance()
	{
		//This method is the one and only way of getting hold
		//of the one and only instance of a SystemData object.

		static SystemData singleton; //This is the one-and-only instance
		return &singleton; //return it
	}

	SystemData::SystemData()
	{
		mExitSignSpacing = 0;
		mSirenSpacing = 0;
		mDaysBetweenCleaning = 0;
		mSoiledEfficiency = 0;
		mHighestPercentOutput = 0;
		mLowestPercentOutput = 0;
		mEmergencyLampLumens = 0.0;

		for (Sint_32 TypeCount=0; TypeCount<NumLampTypes; TypeCount++)
		{
			mLampTypeWatts[TypeCount]=0;
			mTheLampType[TypeCount].InitialiseLampType(mHighestPercentOutput, mLowestPercentOutput, mLampTypeWatts[TypeCount]);
		}
	}

	void SystemData::InitialiseParams (Sint_32* pSystemDataArray)
	{
		Sint_32 ElementCount=0;

		mExitSignSpacing = pSystemDataArray[ElementCount++];
		mSirenSpacing = pSystemDataArray[ElementCount++];
		mDaysBetweenCleaning = pSystemDataArray[ElementCount++];
		mSoiledEfficiency = pSystemDataArray[ElementCount++];
		mHighestPercentOutput = pSystemDataArray[ElementCount++];
		mLowestPercentOutput = pSystemDataArray[ElementCount++];
		mEmergencyLampLumens = (Float_64)(pSystemDataArray[ElementCount++]);
		for (Sint_32 TypeCount=0; TypeCount<NumLampTypes; TypeCount++)
		{
			mLampTypeWatts[TypeCount]=pSystemDataArray[ElementCount++];
			mTheLampType[TypeCount].InitialiseLampType(mHighestPercentOutput, mLowestPercentOutput, mLampTypeWatts[TypeCount]);
		}
	};

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

	Float_64 SystemData::GetSoilingFactor(void) const
	{
		Float_64 SoilingFactor=1.0;
		Float_64 SoiledEfficiency=(Float_64)mSoiledEfficiency/100.0;

		//Calculate percentage efficiency after the days elapsed since last clean
		if (mDaysBetweenCleaning>0 && SoiledEfficiency>Small)
			SoilingFactor = 1.0 + (((1.0/SoiledEfficiency)-1.0)/((Float_64)mDaysBetweenCleaning)*(Float_64)mDaysSinceCleaning);

		return SoilingFactor;
	}


	Sint_32 SystemData::GetLampPowerRequired(const LampTypeID ThisLampTypeID, const Float_64 LumensRequired) const
	{
		return mTheLampType[ThisLampTypeID].GetPowerRequired(LumensRequired);
	};

	Float_64 SystemData::GetLampMaximumLumens(const LampTypeID ThisLampTypeID) const
	{
		return mTheLampType[ThisLampTypeID].GetMaximumLumens();
	};

	Float_64 SystemData::GetLampMinimumLumens(const LampTypeID ThisLampTypeID) const
	{
		return mTheLampType[ThisLampTypeID].GetMinimumLumens();
	};

	Float_64 SystemData::GetEmergencyLampLumens() const
	{
		return mEmergencyLampLumens;
	};

	void SystemData::SetDaysSinceCleaning(const Sint_32 Days)
	{
		mDaysSinceCleaning=Days;
	};

	Sint_32 SystemData::GetDaysBetweenCleaning(void) const
	{
		return mDaysBetweenCleaning;
	};

	Sint_32 SystemData::GetExitSignSpacing(void) const
	{
		return mExitSignSpacing;
	};

	Sint_32 SystemData::GetSirenSpacing(void) const
	{
		return mSirenSpacing;
	};


}
