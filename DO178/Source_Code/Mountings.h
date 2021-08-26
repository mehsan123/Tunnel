/************************************************************************************************************
Mountings.h

v1.0 Original - Provides for different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/

#include "Lampmodel.h"

namespace TunnelData
{
	class MountingArea
	{
		public:
			MountingArea (int l,int b);
			int NumLamps (LampAttributes MyLamp);
		private:
			int length;
			int breadth;
	};
};

