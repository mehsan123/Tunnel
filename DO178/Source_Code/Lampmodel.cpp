/************************************************************************************************************
Lampmodel.cpp

v1.0 Original - Provides for different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/

#include "Lampmodel.h"

namespace TunnelData
{
  LampAttributes::LampAttributes (int h,int w,model m)
  {
    if (h < 1)
    {
      height = 1;
    }
    else
    {
      height = h;
    }
    if (w < 1)
    {
      width = 1;
    }
    else
    {
      width = w;
    }
    ThisModel = m;
  }

  int LampAttributes::Height ()
  {
    return height;
  }

  int LampAttributes::Width ()
  {
    return width;
  }

  int LampAttributes::Drain ()
  /*Current drain when on emergency battery backup depends on type of device. 
  Drain from LCD exit instruction panels depends on their surface area */
  {
	  int drain;
	  
	  switch (ThisModel)
	  {
		  case LightSolo:
			    drain=0;
				break;
	  
		  case Announcer:
				drain=5;
				break;

		  case Guide:
				drain=6*width*height;
				break;

		  default:
				drain=5 + 6*width*height;
				break;
	  }
	  return drain;
  }

  int LampAttributes::Area ()
  {
    return width * height;
  }

  SquareLamp::SquareLamp (int l,model m) : LampAttributes (l,l,m)
  {
  }
}
