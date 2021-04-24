/*
 * main.c
 *
 *  Created on: Apr 24, 2021
 *      Author: Hashim
 */

#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include "LCD_Interface.h"
#include "KPD_Interface.h"

int main()
{
	LCD_VoidInit();
	KPD_VoidInit();

	u8 x=0;
	u8 num1[10]={0};//x=0
	u32 num_1=0;
	u8 num2[10]={0};  //x=1
	u32 num_2=0;
	u8 counter_1=0; //for num1
	u8 counter_2=0; //for num2

	u8 operator=0;

	while(1)
	{
		u8 key=KPD_U8GetPressedKey();


		if(key!=32)
		{

			// numbers from 0 to 9
			if(key==12)
			{
				LCD_VoidWriteData('0');
				switch(x)
				{
					case 0:num1[counter_1]=0; counter_1++; break;
					case 1:num2[counter_2]=0; counter_2++; break;
				}
			}
			else if (key<3)
			{
				LCD_VoidSendNum(key+1);
				switch(x)
				{
					case 0:num1[counter_1]=key+1; counter_1++; break;
					case 1:num2[counter_2]=key+1; counter_2++; break;
				}
			}
			else if(key >= 4 && key <= 6)
			{
				LCD_VoidSendNum(key);
				switch(x)
				{
					case 0:num1[counter_1]=key; counter_1++; break;
					case 1:num2[counter_2]=key; counter_2++; break;
				}
			}
			else if(key >= 8 && key <= 10)
			{
				LCD_VoidSendNum(key-1);
				switch(x)
				{
					case 0:num1[counter_1]=key-1; counter_1++; break;
					case 1:num2[counter_2]=key-1; counter_2++; break;
				}
			}

			//calc
			switch(key)
			{
				case 3 :LCD_VoidWriteData('+');  operator=3;   TOG_BIT(x,0);  break;
				case 7 :LCD_VoidWriteData('-') ; operator=7;   TOG_BIT(x,0);  break;
				case 11:LCD_VoidWriteData('*'); operator=11;   TOG_BIT(x,0);  break;
				case 15:LCD_VoidWriteData('/'); operator=15;   TOG_BIT(x,0);  break;
				case 14:
				{
					LCD_VoidWriteData('=');

					//calcuates num1 and num2
					for(int i=0; i<counter_1 ;i++)
					{
						num_1=num_1*10+num1[i];
					}

					for(int i=0; i<counter_2 ;i++)
					{
						num_2=num_2*10+num2[i];
					}

					switch(operator)
					{
						case 3 :LCD_VoidSendNum(num_1+num_2);  break;
						case 7 :LCD_VoidSendNum(num_1-num_2);  break;
						case 11:LCD_VoidSendNum(num_1*num_2);  break;
						case 15:LCD_VoidSendNum(num_1/num_2);  break;
					}

				}
			}
		}



	}
}

