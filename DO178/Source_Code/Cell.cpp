/************************************************************************************************************
Cell.cpp

v1.0 Original 23/10/07 Bill Cody 
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/

#include "Config.h"
#include <iostream>
using std::cout;
#include "Lampmodel.h"
#include "Lamp.h"
#include "Lamptype.h"
#include "Systemdata.h"
#include "Cell.h"

namespace TunnelData
{
	Cell::Cell(void)
	/* Constructor */
	{
 		mUniqueCellID=0;
		mLuminaireSetSize=0;
		for (Sint_32 i=0; i<NumLampTypes; i++)
		{
			mLampTypeMaxLumens[i]=0.0;
			mLampTypeMinLumens[i]=0.0;
			mLampTypeCount[i]=0;
		}
	};

	Bool Cell::InitialiseCell(const Sint_32 LuminaireSetSize, const LampTypeID *pLampTypeIDs, const Sint_32 UniqueCellID)
	/* Initialises for both the cell parameters, and the lamps within that cell. */
	{
		Bool Okay=true;
		Sint_32 TypeCount;
		Sint_32 LampCount;
		Sint_32 LuminaireCount;

		mLuminaireSetSize=LuminaireSetSize;

		//Guard against reinitializing
		for (TypeCount=0; TypeCount<NumLampTypes; TypeCount++)
			mLampTypeCount[TypeCount]=0;

		//pLampTypeIDs holds the types for a single Luminaire.
		//Initialise here for each individual lamp.
		Sint_32 ThisLamp=0;
		for (LuminaireCount=0; LuminaireCount<mLuminaireSetSize; LuminaireCount++)
		{
			for (LampCount=0; LampCount<LampsPerLuminaire; LampCount++)
			{
				//Initialise the type IDs
				mLampTypeID[ThisLamp]=pLampTypeIDs[LampCount];
				mThisLamp[ThisLamp].InitialiseLamp(mLampTypeID[ThisLamp], IDOffset*UniqueCellID+ThisLamp, GetLampModel(ThisLamp));
				ThisLamp++;
			}
		}

		//Get the Lumens output for the lamp types, and count how many of each there are per luminaire
		for (LampCount=0; LampCount<LampsPerLuminaire; LampCount++)
		{
			LampTypeID ThisType=mLampTypeID[LampCount];
			if (0==mLampTypeCount[ThisType])
			{
				mLampTypeMaxLumens[ThisType]=mThisLamp[LampCount].GetMaximumLumens();
				mLampTypeMinLumens[ThisType]=mThisLamp[LampCount].GetMinimumLumens();
			}
			mLampTypeCount[ThisType]++;
		}

		//Account for the number of luminaires in this cell
		for (TypeCount=0; TypeCount<NumLampTypes; TypeCount++)
		{
			mLampTypeCount[TypeCount]=mLampTypeCount[TypeCount]*mLuminaireSetSize;
		}

		mUniqueCellID=UniqueCellID;

		return Okay;
	};

	void Cell::SetEmergencyOutputLevel(void)
	/* Use only one of the smallest lamps per luminaire, set to its defined emergency demand level,
	to minimize power demands on emergency supplies */
	{
		Bool OutputSet=false;

		//Lamp types are always in decreasing order of output power
		for (Sint_32 LampCount=0; LampCount<LampsPerLuminaire*mLuminaireSetSize; LampCount++)
		{
			LampTypeID ThisType=mLampTypeID[LampCount];
			if ((ThisType==Dimmest) && !OutputSet)
			{
				mThisLamp[LampCount].SetLumensOutput(SystemData::Instance()->GetEmergencyLampLumens());
				OutputSet=true;
			}
			else
			{
				mThisLamp[LampCount].SetLumensOutput(0);
			}
		}
	};

	void Cell::SetPoweredOutputLevel(const Float_64 LumensDemandPerMetre, const Float_64 CellSpacing)
	/* Assess which lamps should be used, leaning on the larger lamps by preference. Where a setting is such that
	all used lamps will not be at maximum output, then those of a similar type will all use a lower setting.

	Once those settings are ascertained, they are assigned to the lamps in Lumens for conversion to power. */
	{
		Float_64 UnassignedCellOutput;
		Sint_32 LampsUsed[NumLampTypes];
		Float_64 LumensDemand[NumLampTypes];

		Sint_32 TypeCount;
		Sint_32 LampCount;

		//Output required from this cell in Lumens depends on spacing
		UnassignedCellOutput=CalculateCellOutput(LumensDemandPerMetre, CellSpacing);

		//Assumes highest power first, and assign all full power first.
		for (TypeCount=0; TypeCount<NumLampTypes; TypeCount++)
		{
			LampsUsed[TypeCount]=(int)(UnassignedCellOutput/mLampTypeMaxLumens[TypeCount]);
			if (LampsUsed[TypeCount]>mLampTypeCount[TypeCount])
			{
				//Too much demand for this type to handle alone. Use as many as possible.
				LampsUsed[TypeCount]=mLampTypeCount[TypeCount];
			}
			LumensDemand[TypeCount]=mLampTypeMaxLumens[TypeCount];
			UnassignedCellOutput=UnassignedCellOutput-(LampsUsed[TypeCount]*mLampTypeMaxLumens[TypeCount]);
		}

		//Assess what we have left. Find smallest lamp available.
		if (UnassignedCellOutput>Small)
		{
			for (TypeCount=NumLampTypes-1; TypeCount>=0; TypeCount--)
			{
				if (LampsUsed[TypeCount]<mLampTypeCount[TypeCount])
				{
					if ((UnassignedCellOutput>mLampTypeMinLumens[TypeCount]) || (LampsUsed[TypeCount]>=1))
					{
						//Spread the reduced output over all lamps of this size in use
						LampsUsed[TypeCount]++;
						LumensDemand[TypeCount]=((LumensDemand[TypeCount]*(LampsUsed[TypeCount]-1))+UnassignedCellOutput)/LampsUsed[TypeCount];
						break;
					}
				}
			}
		}

		//Set required output for all
		for (LampCount=0; LampCount<LampsPerLuminaire*mLuminaireSetSize; LampCount++)
		{
			LampTypeID ThisType=mLampTypeID[LampCount];
			if (LampsUsed[ThisType]>0)
			{
				/* LDRA_INSPECTED 5D */
				mThisLamp[LampCount].SetLumensOutput(LumensDemand[ThisType]);
				LampsUsed[ThisType]--;
			}
			else
			{
				mThisLamp[LampCount].SetLumensOutput(0);
			}
		}
		cout << "Total Cell Demand: " << LumensDemandPerMetre*CellSpacing << " at " << LumensDemandPerMetre << " per metre" << "\n";
	};


	Float_64 Cell::CalculateCellOutput(Float_64 LumensDemandPerMetre, Float_64 CellSpacing)
	{
	
		LumensDemandPerMetre *= CellSpacing;

		return LumensDemandPerMetre;

	}

	model Cell::GetLampModel(const Sint_32 ThisLamp)
	{
		model ThisLampModel;
		Sint_32 ExitSignSpacing=(SystemData::Instance()->GetExitSignSpacing());
		Sint_32 SirenSpacing=(SystemData::Instance()->GetSirenSpacing());
		
		if (((ThisLamp % ExitSignSpacing)==0) && ((ThisLamp % SirenSpacing) == 0))
			ThisLampModel=Duo;
		else
		{
			if ((ThisLamp % ExitSignSpacing)==0)
				ThisLampModel=Guide;
			else
			{
				if ((ThisLamp % SirenSpacing)==0)
					ThisLampModel=Announcer;
				else 
					ThisLampModel=LightSolo;
			}
		}
		return ThisLampModel;
	};		
}

