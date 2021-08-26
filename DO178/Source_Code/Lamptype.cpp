/************************************************************************************************************
LampType.cpp

v1.0 Original 23/10/07 Bill Cody 
*************************************************************************************************************/

#include "Config.h"
#include "Lamptype.h"

namespace TunnelData
{
	LampType::LampType(void)
	/* Constructor */
	{
		Sint_32 mMaximumPower=0;
		Float_64 mMaximumLumens=0.0;
		Sint_32 mMinimumPower=0;
		Float_64 mMinimumLumens=0.0;
	};


	void LampType::InitialiseLampType(const Float_64 HighestPercentOutput, const Float_64 LowestPercentOutput, const Sint_32 MaximumPower)
	/* Initialise member variables */
	{
		mMaximumPower=MaximumPower;
		mMaximumLumens=HighestPercentOutput*MaximumPower;
		mMinimumLumens=mMaximumLumens*MinLampOutput;
		mMinimumPower=(int)(mMinimumLumens/LowestPercentOutput);
	}
 
	Float_64 LampType::GetMaximumLumens(void) const
	{
		return mMaximumLumens;
	}

	Float_64 LampType::GetMinimumLumens(void) const
	{
		return mMinimumLumens;
	}

	Sint_32 LampType::GetPowerRequired(const Float_64 LumensRequired) const
	/* Assume a linear deterioration of efficiency from HighestPercentOutput lm/W output from each lamp at
	maximum output, down to LowestPercentOutput lm/W at 20% output. Calculate power required based on the
	resulting interpolation. */
	{
		Sint_32 Power=0;
		if (((mMaximumLumens-mMinimumLumens)>Small) && (LumensRequired>=mMinimumLumens))
		{
			Power = (Sint_32)(mMinimumPower + (mMaximumPower-mMinimumPower)*((LumensRequired-mMinimumLumens)/(mMaximumLumens-mMinimumLumens)));
		}
		return Power;
    }
}
