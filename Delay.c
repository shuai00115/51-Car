#include <INTRINS.H>

void Delay100us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	i = 47;
	while (--i);
}
