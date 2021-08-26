/************************************************************************************************************
Main.cpp

v1.0 Original 23/10/07 Bill Cody 
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
v2.0 Addition of ini file handling  13/08/15 Bill Cody
*************************************************************************************************************/

#include <iostream>
#include <fstream>
using std::cout;
using std::cin;

#include "Config.h"
#include "Lampmodel.h"
#include "Lamptype.h"
#include "Systemdata.h"
#include "Lamp.h"
#include "Cell.h"
#include "Zone.h"
#include "Tunnel.h"
#include "Datain.h"

/* For emergency command */

#ifdef CAndCpp 
	#include "SignCommand.h"
#endif

#ifdef CDLLAndCpp
	extern "C" __declspec(dllimport) int SignCommand(void);
#endif

#ifndef INI_FILE
	void CheckForInitialisation();
#endif

Sint_32 main()
// Initialise from ini file, and then enter "Photometer input loop".
{
	using namespace TunnelData;

	DataIn ThisDataIn;
	Tunnel TheTunnel;

	Sint_32 Choice;
    Bool Quit=false;
	Bool PowerFailure=false;
	Float_64 Photometer=4.0;
	Sint_32 DaysSinceCleaning=0;

    const Sint_32 MaxChoice=3;
	const Float_64 MinPhotometer=4.0;
	const Float_64 MaxPhotometer=20.0;

#ifndef INI_FILE
	CheckForInitialisation();
#endif

    //Initialise from ini file
	if (!ThisDataIn.GetData(&TheTunnel))
    {
        cout << "Flawed or missing ini file. (0) quit \n";
		cin  >> Choice ;
		cout << "\n" ;
    }
    else
	{
		while (!Quit)
		{
			cout << "\nPhotometer Input: " << Photometer << "mA    Days since cleaning: " << DaysSinceCleaning << "    Power: ";
			if (PowerFailure)
			{
				cout << "Failed" ;
			}
			else
			{
				cout << "Live" ;
			}

			cout << " \n \n(0) quit (1) Photometer Input (4-20) \n(2) Set days since cleaning (3) Toggle Power Failure Status: \n" ;
			cin  >> Choice ;
			cout << "\n" ;

			if (0<=Choice && MaxChoice>=Choice)
			{
				switch (Choice)
				{
					case 0:
						Quit=true;
						break;
					case 1:
						// Get user input in absence of hardware
						{
							do
							{
								cout << "Enter photometer input in range 4-20mA: ";
								cin >> Photometer;
							}
							while (Photometer < MinPhotometer || Photometer > MaxPhotometer);
							TheTunnel.AdjustLighting(Photometer, PowerFailure);
							break;
						}
					case 2:
						// Get user input for days elapsed.
						{
							do
							{
								cout << "Enter days since cleaning in the range 0-" << SystemData::Instance()->GetDaysBetweenCleaning() << " : ";
								cin >> DaysSinceCleaning;
							}
							while (DaysSinceCleaning > (SystemData::Instance()->GetDaysBetweenCleaning()) || DaysSinceCleaning < 0);
							SystemData::Instance()->SetDaysSinceCleaning(DaysSinceCleaning);
							TheTunnel.AdjustLighting(Photometer, PowerFailure);
							break;
						}
					case 3:
						// Get user input for power failure.
						{
							PowerFailure=!PowerFailure;
							TheTunnel.AdjustLighting(Photometer, PowerFailure);
#ifndef CppOnly
							if (PowerFailure)
								SignCommand();
#endif
							break;
						}
				}
			}
		}
	}
    return 0;
}

#ifndef INI_FILE
void CheckForInitialisation()
{
	// Check for existing ini file
	std::ifstream in ("Tunnel.ini");

	if (!in.good())
	{
		// Write out a default ini file
		std::ofstream out ("Tunnel.ini");
		if (out.good())
		{
			out << "1: Tunnel wide parameters " << std::endl;
			out << "2: 50, 75, 182, 50, 120, 60, 5500, 400, 200" << std::endl;
			out << "1:" << std::endl;
			out << "1: TUNNEL ZONES" << std::endl;
			out << "1: Zone 1" << std::endl;
			out << "3: 300, 3, 20, 0, 0, 1, 1, 5000, 10000, 4000, 6000" << std::endl;
			out << "1:" << std::endl;
			out << "1: Zone 2" << std::endl;
			out << "3: 500, 2, 20, 0, 0, 1, 1, 4000, 6000, 2000, 2000" << std::endl;
			out << "1:" << std::endl;
			out << "1: Zone 3" << std::endl;
			out << "3: 600, 1, 30, 0, 0, 1, 1, 2000, 2000, 2000, 2000" << std::endl;
			out << "1:" << std::endl;
			out << "1: Zone 4" << std::endl;
			out << "3: 400, 2, 20, 0, 0, 1, 1, 2000, 2000, 3000, 5000" << std::endl;
			out << "1:" << std::endl;
			out << "1: Zone 5" << std::endl;
			out << "3: 200, 3, 20, 0, 0, 1, 1, 3000, 5000, 5000, 10000" << std::endl;
		}
		out.close();
	}
	in.close();
}
#endif
