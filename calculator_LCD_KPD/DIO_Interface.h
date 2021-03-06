#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_


void DIO_VoidSetPinDirection(u8 Port,u8 Pin,u8 Direction);

void DIO_VoidSetPortDirection(u8 Port,u8 Dir);

void DIO_VoidSetPinValue(u8 Port,u8 Pin,u8 Value);

void DIO_VoidSetPortValue(u8 Port,u8 Value);

u8 DIO_U8GetPinValue(u8 port,u8 Pin);

void DIO_VoidTogglePin(u8 Port,u8 Pin);

#endif