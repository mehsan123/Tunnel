/************************************************************************************************************
LampModel.h

v1.0 Original - Provides for different lamp types for exit signs & sirens 03/05/08 Bill Cody
*************************************************************************************************************/

namespace TunnelData
{
  typedef enum
  {
 	LightSolo,Announcer,Guide,Duo
  } model;
	
  class LampAttributes
  {
  public:
    LampAttributes (int h,int w, model m);
    int Height ();
    int Width ();
	int Drain ();
  private:
    int Area ();
    int height;
    int width;
    model ThisModel;
  };

  class SquareLamp : public LampAttributes
  {
  public:
    SquareLamp (int l,model ThisModel);
  };
}



