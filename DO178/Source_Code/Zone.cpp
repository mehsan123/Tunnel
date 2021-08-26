/************************************************************************************************************
Zone.cpp

v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/

#include "Config.h"
#include "Lampmodel.h"
#include "Lamp.h"
#include "Lamptype.h"
#include "Systemdata.h"
#include "Cell.h"
#include "Zone.h"

namespace TunnelData
{
	Zone::Zone(void)
	/* Constructor*/
	{
		mLength=0;
		mLuminaireSetSize=0;
		mSetSpacing=0;
		for (Sint_32 i=0; i<LampsPerLuminaire; i++)
			mTheLampTypeID[i]=Brightest;
		mMinimumEntryOutput=0;
		mMaximumEntryOutput=0;
		mMinimumExitOutput=0;
		mMaximumExitOutput=0;
   		mFormulaGradient=0.0;
		mFormulaConstant=0.0;
	};

	void Zone::InitialiseZone (Sint_32* pZoneData, const Sint_32 UniqueZoneID)
	/* Initialises both the zone parameters, and the luminaire count in cells */
	{
		Sint_32 j=0;

		mLength=pZoneData[j++];
		mLuminaireSetSize=pZoneData[j++];
		mSetSpacing=pZoneData[j++];
		for (Sint_32 i=0; i<LampsPerLuminaire; i++) {
			mTheLampTypeID[i]=(LampTypeID)pZoneData[j++];
		}

		mMinimumEntryOutput=pZoneData[j++];
		mMaximumEntryOutput=pZoneData[j++];
		mMinimumExitOutput=pZoneData[j++];
		mMaximumExitOutput=pZoneData[j++];

		//Initialise Luminaire count in cells
		Sint_32	TotalCells=mLength/mSetSpacing;
		for (Sint_32 CellCount=0; CellCount<TotalCells; CellCount++)
		{
			mThisCell[CellCount].InitialiseCell(mLuminaireSetSize, mTheLampTypeID, IDOffset*UniqueZoneID+CellCount);
		}
    };

	Bool Zone::CalculateOutputFormula(const Sint_32 PercentageDemand)
	/* Calculates formula for required output in lumens/metre in the format y=mx+c, where
	y=output, x=distance from beginning of zone, m=gradient, c=constant (offset)
	with appropriate adjustment for soiling etc */
	{
		Bool Okay=true;
		Float_64 ActualEntryOutput=0.0;
		Float_64 ActualExitOutput=0.0;
		Float_64 SoilingFactor=0.0;

		//Calculate required output at zone boundaries
		ActualEntryOutput=(mMinimumEntryOutput+((mMaximumEntryOutput-mMinimumEntryOutput)*PercentageDemand/100.0))*(SystemData::Instance()->GetSoilingFactor());
		ActualExitOutput=(mMinimumExitOutput+((mMaximumExitOutput-mMinimumExitOutput)*PercentageDemand/100.0))*(SystemData::Instance()->GetSoilingFactor());

		//Derive formula parameters "m" and "c" viz. y=mx+c
		if (mLength>Small)
		{
			mFormulaGradient=(ActualExitOutput-ActualEntryOutput)/mLength;
			mFormulaConstant=ActualEntryOutput;
		}
		else
			Okay=false;

		return Okay;
	};

	Bool Zone::AssignPoweredCellsOutput(void)
	/* For each cell, calculate distance from zone start to derive lumens output required from line formula */
	{
		Sint_32 TotalCells;
		Bool Okay=true;

		if (mSetSpacing>0)
		{
			TotalCells=mLength/mSetSpacing;
			for (Sint_32 CellCount=0; CellCount<TotalCells; CellCount++)
			{
				Float_64 LumensOutput=CellCount*mSetSpacing*mFormulaGradient+mFormulaConstant;
				mThisCell[CellCount].SetPoweredOutputLevel(LumensOutput, mSetSpacing);
			}
		}
		else
			Okay=false;

		return Okay;
	};

	Bool Zone::AssignEmergencyCellsOutput(void)
	/* Power failure */
	{
		Sint_32 TotalCells;
		Bool Okay=true;

		if (mSetSpacing>0)
		{
			TotalCells=mLength/mSetSpacing;
			for (Sint_32 CellCount=0; CellCount<TotalCells; CellCount++)
			{
				mThisCell[CellCount].SetEmergencyOutputLevel();
			}
		}
		else
			Okay=false;

		return Okay;
	};
}
