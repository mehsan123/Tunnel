/************************************************************************************************************
Zone.h

v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody 
*************************************************************************************************************/

namespace TunnelData
{
	class Zone
	{
    public:
        //Constructors
		Zone(void);

		//Accessors
		void InitialiseZone(Sint_32* pZoneData, const Sint_32 UniqueZoneID);

		//Others 
		Bool CalculateOutputFormula(const Sint_32 PercentageDemand);
		Bool AssignPoweredCellsOutput(void);
		Bool AssignEmergencyCellsOutput(void);

	private:
		Sint_32 mLength;
		Sint_32 mLuminaireSetSize;
		Sint_32 mSetSpacing;
		LampTypeID mTheLampTypeID[LampsPerLuminaire];
		Sint_32 mMinimumEntryOutput;
		Sint_32 mMinimumExitOutput;
		Sint_32 mMaximumEntryOutput;
		Sint_32 mMaximumExitOutput;

		Float_64 mFormulaGradient;
		Float_64 mFormulaConstant;

	    Cell mThisCell[MaxCellsPerZone];
	};
}
