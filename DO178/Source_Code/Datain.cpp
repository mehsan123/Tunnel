/************************************************************************************************************
DataIn.cpp

v1.0 Original 23/10/07 Bill Cody 
v1.1 Addition of different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/

#include <stdlib.h>
#include <fstream>
#include <string.h>
using std::ifstream;

#include "Config.h"
#include "Lampmodel.h"
#include "Lamptype.h"
#include "Systemdata.h"
#include "Lamp.h"
#include "Cell.h"
#include "Zone.h"
#include "Tunnel.h"
#include "Datain.h"

namespace TunnelData
{
	Bool DataIn::GetData(Tunnel* pTunnel)
	/* Reads all data from the "Tunnel.ini" initialisation file, and allocates appropriately.*/
	{
		ifstream loadcsv("./Tunnel.ini");
		Char Sep[]=":,";
		Char* ValidLine;
		Bool Okay=true;
		Sint_32 ZoneCount=0;
		Sint_32 ParamLineCount=0;

		do
		{
			//Check whether all is well with the ini file
			Okay=loadcsv.good();
			if (Okay)
			{
				loadcsv.getline(Buffer, sizeof(Buffer));
				ValidLine = strtok(Buffer, Sep);
			}
			if (Okay && ValidLine)	// Is this a valid entry?			
			{
				Sint_32 LineType=atoi(ValidLine);
				switch (LineType)
				{
					case 1: //Comment - do nothing
					{
						break;
					}
					case 2: //System parameters
					{
						Char *Token;
						Sint_32 Count=0;
						Sint_32 SystemDataArray[NumSystemParams];

						ParamLineCount++;
						Token = (Char *)malloc(sizeof(Char));
						Token = strtok(NULL, Sep);

						//ReadContent(SystemDataArray, Token, Count);
											
						//Data line so read contents
						while (Token && Count<NumSystemParams)
						{
							//Zone data
							SystemDataArray[Count]=atoi(Token);
							// Next token while there are tokens in "string"
							Count++;
							Token = strtok(NULL, ",");
						}
						free(Token);
						SystemData::Instance()->InitialiseParams(SystemDataArray);
						free(Token);
						break;
					}
					case 3: //Zone
					{
						Char *Token;
						Sint_32 Count=0;
						Sint_32 ZoneData[NumZoneParams];

						Token = strtok(NULL, Sep); //Get first data entry
						//ReadContent(ZoneData, Token, Count);
										
						while (Token && Count<NumZoneParams)
						{
							//Zone data
							ZoneData[Count]=atoi(Token);
							// Next token while there are tokens in "string"
							Count++;
							Token = strtok(NULL, ",");
						}
						
						pTunnel->InitialiseTunnel(ZoneCount, ZoneData);
						ZoneCount++;
						break;
					}
					default: //Unrecognised line - abort
					{
						Okay=false;
					}
				}
			}
		}
		while (Okay && ValidLine);

		loadcsv.close();
		
		goto End;
		  ZoneCount++;
		
    End:
		  return (Okay && (NumZones==ZoneCount) && (1==ParamLineCount));
	}
	
	
	void DataIn::ReadContent(Sint_32* array, char* Token, Sint_32 Count)
	{
    
        while (Token && Count<NumZoneParams)
        {
          //Zone data
          array[Count]=atoi(Token);
          // Next token while there are tokens in "string"
          Count++;
          Token = strtok(NULL, ",");
        }
	}
}

