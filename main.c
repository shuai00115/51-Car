#include <REGX52.H>
#include "TrackLine.h"
#include "Motor.h"

sbit Left=P0^0;
sbit Middle_Left=P0^1;
sbit Middle_Right=P0^2;
sbit Right=P0^3; //定义红外传感器引脚

void main()
{
	Motor_Init();
	while (1)
  {
		TrackLine();
		if(Right == 1 && Middle_Left == 1 && Middle_Right == 1 && Left == 0)
		{
			if(Right == 1 && Middle_Left == 0 && Middle_Right == 0 && Left == 1)
			{
				Motor_TurnSharpLeft();
				Motor_Forward();
				TrackLine();
				if(Right == 1 && Middle_Left == 0 && Middle_Right == 0 && Left == 1)
				{
					Motor_TurnSharpRight();
				}
			}
		}
  }
}
