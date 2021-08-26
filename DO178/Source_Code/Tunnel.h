/************************************************************************************************************
Tunnel.h

v1.0 Original 23/10/07 Bill Cody 
*************************************************************************************************************/

namespace TunnelData
{
	class Tunnel
	{
	public:
		//Accessors
		void InitialiseTunnel(const Sint_32 ZoneNumber, Sint_32 *pZoneData);
		void AdjustLighting (const Float_64 PhotometerDemand, Bool PowerFailure);

	private:
		Zone TunnelZone[NumZones];

		void AdjustPoweredLighting (const Float_64 PhotometerDemand);
		void AdjustEmergencyLighting (void);
	}; 
}
