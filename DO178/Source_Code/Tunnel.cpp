/************************************************************************************************************
Tunnel.cpp

v1.0 Original 23/10/07 Bill Cody
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/

#include "Config.h"
#include "Lampmodel.h"
#include "Lamp.h"
#include "Cell.h"
#include "Zone.h"
#include "Tunnel.h"

namespace TunnelData
{
	void Tunnel::InitialiseTunnel(const Sint_32 ZoneNumber, Sint_32 *pZoneData)
	{
		TunnelZone[ZoneNumber].InitialiseZone(pZoneData, ZoneNumber);
	}

	void Tunnel::AdjustLighting (const Float_64 PhotometerDemand, Bool PowerFailure)
	{
		if (PowerFailure)
		{
			AdjustEmergencyLighting();
		}
		else
		{
			AdjustPoweredLighting(PhotometerDemand);
		}
    };

	void Tunnel::AdjustPoweredLighting (const Float_64 PhotometerDemand)
	/* Turn 0-20mA from the Photometer into a percentage demand value. Calculate formulae
	for required outputs based on those demands, and assign the required output values to cells */
	{
		Sint_32 j=0;

		//Turn 0-20mA into a percentage
		Sint_32 PhotometerPercentageDemand=(int)(100.0*(PhotometerDemand-4.0)/16.0);

		for (Sint_32 ZoneCount=0; ZoneCount<NumZones; ZoneCount++)
		{
			TunnelZone[ZoneCount].CalculateOutputFormula(PhotometerPercentageDemand);
			TunnelZone[ZoneCount].AssignPoweredCellsOutput();
        }
    };

	void Tunnel::AdjustEmergencyLighting (void)
	/* Power failure */
	{
		for (Sint_32 ZoneCount=0; ZoneCount<NumZones; ZoneCount++)
		{
			TunnelZone[ZoneCount].AssignEmergencyCellsOutput();
        }
    };
}
