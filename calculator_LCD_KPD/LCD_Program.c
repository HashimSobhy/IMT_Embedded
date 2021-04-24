#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include <avr/delay.h>

u8 counter_columns=0;

void LCD_VoidWriteString(u8 *ptr)
{
	u8 i=0;

	while(ptr[i]!='\0')
	{
		LCD_VoidWriteData(ptr[i]);
		i++;

		counter_columns++;
		if(counter_columns==16)
		{
			LCD_VoidWriteCommand(0xc0);
		}

	}
}

void LCD_VoidSendNum(u32 num)
{
	u8 x=0;
	u32 rev=1;
	if (num ==0)
	{
		LCD_VoidWriteData('0');
	}
	else
	{
		while(num!=0)
		{
			rev=(rev*10) + (num%10);
			num/=10;
		}

		while (rev!=1)
		{
			x= rev%10;
			rev=rev/10;
			LCD_VoidWriteData(x+48);
		}
	}
}




void LCD_VoidInit(void)
{
	DIO_VoidSetPortDirection(2,0b11111111);
	DIO_VoidSetPinDirection(3,0,1);
	DIO_VoidSetPinDirection(3,1,1);
	DIO_VoidSetPinDirection(3,2,1);

	_delay_ms(40);
	// function set 
	LCD_VoidWriteCommand(0b00111000);
	_delay_us(100);
	//display On/off control
	LCD_VoidWriteCommand(0b00001111);
	_delay_us(100);
	// display clear
	LCD_VoidWriteCommand(0b00000001);
	_delay_ms(2);	
}

void LCD_VoidWriteData(u8 data)
{
	//  Rs =1 to write data
	DIO_VoidSetPinValue(3,0,1);
	// R/W =0 to write
	DIO_VoidSetPinValue(3,1,0);
	// send command to data port
	DIO_VoidSetPortValue(2,data);
	//Enable sequence
	DIO_VoidSetPinValue(3,2,1);
	_delay_ms(1);
	DIO_VoidSetPinValue(3,2,0);
	_delay_ms(2);
	counter_columns++;
	if(counter_columns==16)
	{
		LCD_VoidWriteCommand(0xc0);
	}
}


void LCD_VoidWriteCommand(u8 command)
{
	//  Rs =0 to write command
	DIO_VoidSetPinValue(3,0,0);
	// R/W =0 to write
	DIO_VoidSetPinValue(3,1,0);
	// send command to data port
	DIO_VoidSetPortValue(2,command);
	//Enable sequence
	DIO_VoidSetPinValue(3,2,1);
	_delay_ms(1);
	DIO_VoidSetPinValue(3,2,0);
	_delay_ms(2);
}

