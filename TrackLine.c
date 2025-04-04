#include <REGX52.H>
#include "Motor.h"

sbit Left=P0^0;
sbit Middle_Left=P0^1;
sbit Middle_Right=P0^2;
sbit Right=P0^3; //定义红外传感器引脚

void TrackLine(void)
{
	if((Middle_Left == 1 && Middle_Right == 1) || (Middle_Left == 1 && Middle_Right == 1 && Left == 1 && Right == 1)) //若黑线在正中间
	{
		Motor_Forward();  //直行
	}
	if(Right == 0 && Middle_Left == 1 && Middle_Right == 0 && Left == 0)
	{
		Motor_TurnLeft(); //向左微调
	}
	if(Left == 0 && Middle_Right == 1 && Middle_Left == 0 && Right == 0)
	{
		Motor_TurnRight(); //向右微调
	}
	if((Left == 1 && Middle_Left == 1 && Middle_Right == 1 && Right == 0) || (Left == 1 && Middle_Left == 0 && Middle_Right == 0 && Right == 0)) //若黑线在左边
	{
		Motor_TurnSharpLeft(); //左转
	}
	if((Middle_Right == 1 && Right == 1 && Middle_Left == 1 && Left == 0) || (Left == 0 && Middle_Left == 0 && Middle_Right == 0 && Right == 1)) //若黑线在右边
	{
		Motor_TurnSharpRight(); //右转
	}
	
}