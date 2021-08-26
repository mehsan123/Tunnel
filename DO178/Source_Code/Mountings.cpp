/************************************************************************************************************
Mountings.cpp

v1.0 Original - Provides for different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/
#include "Mountings.h"
#include <math.h>

namespace TunnelData
{
	MountingArea::MountingArea (int l,int b)
	{
		length = l;
		breadth = b;
	}

	int MountingArea::NumLamps (LampAttributes MyLamp)
	{
		int num = 0;
		int x;
		int y;

		x = (int) ceil ((float) length / (float) MyLamp.Width ());
		y = (int) ceil ((float) breadth / (float) MyLamp.Height ());

		num = x * y;

		return num;
	}
}
