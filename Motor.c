#include <REGX52.H>

sbit AIN1 = P2^0;
sbit AIN2 = P2^1;
sbit BIN1 = P2^2;
sbit BIN2 = P2^3;


void Motor_Foward(void)
{
	AIN1 = 1;
	AIN2 = 0;
	BIN1 = 1;
	BIN2 = 0;
}