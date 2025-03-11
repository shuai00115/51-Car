#include <REGX52.H>
#include "LightSensor.h"


void main()
{
	while (1)
  {
		if(Read_Sensor() == 1)
		{
			P2=0x01;
		}
		else
		{
			P2=0x00;
		}
  }
}
