#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

void LCD_VoidInit(void);

void LCD_VoidWriteData(u8 data);

void LCD_VoidWriteCommand(u8 command);

void LCD_VoidWriteString(u8 *ptr);

void LCD_VoidSendNum(u32 num);

#endif
