/************************************************************************************************************
Cell.h

v1.0 Original 23/10/07 Bill Cody 
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/

namespace TunnelData
{
	class Cell
	{
    public:
        //Constructors
        Cell(void);
		
	 	//Accessors
		Bool InitialiseCell(const Sint_32 LuminaireSetSize, const LampTypeID *pLampTypeIDs, const Sint_32 UniqueCellID);

		//Others
		void SetPoweredOutputLevel(const Float_64 LumensDemandPerMetre, const Float_64 CellSpacing);
		void SetEmergencyOutputLevel(void);		

	private:
		LampTypeID mLampTypeID[LampsPerLuminaire*MaxLuminairesPerCell];
		Sint_32 mLuminaireSetSize;
		Sint_32 mUniqueCellID;
		Float_64 mLampTypeMaxLumens[NumLampTypes];
		Float_64 mLampTypeMinLumens[NumLampTypes];
		Sint_32 mLampTypeCount[NumLampTypes];

		Lamp mThisLamp[LampsPerLuminaire*MaxLuminairesPerCell];

    Float_64 CalculateCellOutput(Float_64 LumensDemandPerMetre, Float_64 CellSpacing);
		model GetLampModel(const Sint_32 ThisLamp);
	};
}

