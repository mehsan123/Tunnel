/************************************************************************************************************
Lamp.h

v1.0 Original 23/10/07 Bill Cody 
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
namespace TunnelData
{
	class Lamp
	{
    public:
        //Constructors
        Lamp(void);

		//Accessors
		void InitialiseLamp(const LampTypeID ThisLampTypeID, const Sint_32 UniqueLampID, const model LampModelID);
		Float_64 GetMaximumLumens(void) const; 
		Float_64 GetMinimumLumens(void) const; 

		//Others
		void SetLumensOutput(Float_64 LumensRequired);
	
	private:
		void SendPowerToLamp(Sint_32 PowerSetting) const;
		LampTypeID mThisLampTypeID;
		Sint_32 mUniqueLampID;
		model mLampModel;
	};
} 
