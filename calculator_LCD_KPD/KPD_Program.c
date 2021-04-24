#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include <avr/delay.h>

void KPD_VoidInit(void)
{
	DIO_VoidSetPortDirection(0,0b11110000);
	
	DIO_VoidSetPortValue(0,0b11111111);
}


u8 KPD_U8GetPressedKey(void)
{
	u8 pressed_kay=32;
	

	for(u8 col=0;col<4;col++)
	{
		DIO_VoidSetPinValue(0,col+4,0);
		for(u8 row=0;row<4;row++)
		{

			u8 x=DIO_U8GetPinValue(0,row);
			if(0==x)
			{
				pressed_kay=(row*4+col);
				while(0==DIO_U8GetPinValue(0,row))
				{
					
				}
				_delay_ms(2);
			}
			

		}
		DIO_VoidSetPinValue(0,col+4,1);
	}
	return pressed_kay;
}







