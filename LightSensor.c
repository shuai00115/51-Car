#include <REGX52.H>

sbit Sensor=P0^0;

/**
  * @brief 读取红外传感器数据
  * @param  无
  * @retval 红外传感器返回数据，范围为0~1，1为检测到黑线，0为未检测到黑线
  */

char Read_Sensor(void)
{
	return Sensor;
}