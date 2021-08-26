/************************************************************************************************************
Lamp.cpp

v1.0 Original 23/10/07 Bill Cody 
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/

#include <iostream>
using std::cout;
#include "Config.h"
#include "Lampmodel.h"
#include "Lamp.h"
#include "Lamptype.h"
#include "Systemdata.h"


namespace TunnelData
{
	Lamp::Lamp(void)
	{	
		mUniqueLampID=0;
		mThisLampTypeID=Brightest;
	};
		
	void Lamp::InitialiseLamp(const LampTypeID ThisLampTypeID, const Sint_32 UniqueLampID, const model LampModelID )
	/* Initialise member variables */
	{
		mThisLampTypeID = ThisLampTypeID;
		mUniqueLampID = UniqueLampID;
		mLampModel = LampModelID;
	};
	
	void Lamp::SetLumensOutput(Float_64 LumensRequired)
	/* Assigns the lumens required to the appropriate lamp, and converts to power output */ 
	{		
		if (LumensRequired>0)
		{
			//0 power output not shown to make text manageable
			cout <<" Lumens: " << LumensRequired;
		}
		SendPowerToLamp(SystemData::Instance()->GetLampPowerRequired(mThisLampTypeID,LumensRequired));
	};
	
	Float_64 Lamp::GetMaximumLumens(void) const
	/* Retrieve maximum lumens from system parameters */
	{
		return (SystemData::Instance()->GetLampMaximumLumens(mThisLampTypeID));
	};

	Float_64 Lamp::GetMinimumLumens(void) const
	/* Retrieve minimum lumens from system parameters */
	{
		return (SystemData::Instance()->GetLampMinimumLumens(mThisLampTypeID));
	};

	void Lamp::SendPowerToLamp(const Sint_32 PowerSetting) const
	/* Interface to hardware */
	{
		//Replace this code with the output to the hardware. .	
		if (PowerSetting>0)
		{
			//0 power output not shown to make text manageable
			cout <<" Power Setting: " << PowerSetting << " for lamp ID: " << mUniqueLampID << "\n";
		}
	};
} 
