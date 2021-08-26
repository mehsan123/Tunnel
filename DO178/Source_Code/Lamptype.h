/************************************************************************************************************
LampType.h

v1.0 Original 23/10/07 Bill Cody 
*************************************************************************************************************/

namespace TunnelData
{
	class LampType
	{
	public:
        //Constructors
        LampType(void);

		//Accessors
		void InitialiseLampType(const Float_64 HighestPercentOutput, const Float_64 LowestPercentOutput, const Sint_32 MaximumPower);
		Float_64 GetMaximumLumens(void) const;
		Float_64 GetMinimumLumens(void) const;

		//Others
		Sint_32 GetPowerRequired(Float_64 LumensRequired) const;

	private:
		Sint_32 mMaximumPower;
		Float_64 mMaximumLumens;
		Sint_32 mMinimumPower;
		Float_64 mMinimumLumens;
	};
} 
