#include <REGX52.H>
#include "Timer1.h"

sbit PWMA = P1^0;
sbit AIN1 = P1^2;
sbit AIN2 = P1^1; //左轮
sbit STBY = P1^3;
sbit PWMB = P1^6;
sbit BIN1 = P1^4;
sbit BIN2 = P1^5; //右轮
//引脚初始化


unsigned char Counter,Speed_Left,Speed_Right;

/**
  * @brief 马达初始化
  * @param  无
  * @retval 无
  */

void Motor_Init(void)
{
	Timer1_Init(); //定时器1初始化
	AIN1 = 0; 
	AIN2 = 0;
	BIN1 = 0; 
	BIN2 = 0;
	STBY = 1;
}

/**
  * @brief 小车直行
  * @param  无
  * @retval 无
  */

void Motor_Forward(void) 
{
	AIN1 = 0;
	AIN2 = 1;
	BIN1 = 0;
	BIN2 = 1;
	Speed_Left = 55;
	Speed_Right = 55;
}

/**
  * @brief 小车向右微调
  * @param  无
  * @retval 无
  */

void Motor_TurnRight(void)
{
	AIN1 = 0;
	AIN2 = 1;
	BIN1 = 0;
	BIN2 = 1;
	Speed_Right = 40;
	Speed_Left = 55;
}

/**
  * @brief 小车向左微调
  * @param  无
  * @retval 无
  */

void Motor_TurnLeft(void)
{
	AIN1 = 0;
	AIN2 = 1;
	BIN1 = 0;
	BIN2 = 1;
	Speed_Right = 55;
	Speed_Left = 40;
}

/**
  * @brief 小车急右转
  * @param  无
  * @retval 无
  */

void Motor_TurnSharpRight(void) 
{
	AIN1 = 0;
	AIN2 = 1;
	BIN1 = 1;
	BIN2 = 0;
	Speed_Left = 45;
	Speed_Right = 18;
}

/**
  * @brief 小车急左转
  * @param  无
  * @retval 无
  */

void Motor_TurnSharpLeft(void) 
{
	AIN1 = 1;
	AIN2 = 0;
	BIN1 = 0;
	BIN2 = 1;
	Speed_Right = 45; 
	Speed_Left = 18;
}

void Timer1_Rountine() interrupt 3
{
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	Counter++;
	if(Counter>=100) Counter=0;
	//设置左轮PWM
	if(Counter<Speed_Left)
	{
		PWMA=1;
	}
	else
	{
		PWMA=0;
	}
	//设置右轮PWM
	if(Counter<Speed_Right)
	{
		PWMB=1;
	}
	else
	{
		PWMB=0;
	}
}