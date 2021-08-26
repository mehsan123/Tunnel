/************************************************************************************************************
DataIn.h

v1.0 Original 23/10/07 Bill Cody 
*************************************************************************************************************/

namespace TunnelData
{	
	class DataIn
    {
    public:
        //Other methods
		Bool GetData(Tunnel* pTunnel);
		void ReadContent(Sint_32* array, char* Token, Sint_32 count);

    protected:
		Char Buffer[1023];	
    };
} 

