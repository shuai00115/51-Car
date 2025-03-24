#include <REGX52.H>


void Timer0_Init(void)		//100微秒@12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET1 = 1;
	EA = 1;
	PT1 = 0;
}
