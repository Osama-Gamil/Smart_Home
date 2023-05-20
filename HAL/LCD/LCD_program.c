#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include <util/delay.h>

#if LCD_MODE==LCD_MODE_8_Bit

void LCD_voidSendCommand(u8 Copy_u8command1)
{

	/*Set RW pin to write*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_PIN_INPUT);

	/*Set Rs pin to command*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_PIN_INPUT);

	/*Send the command to the LCD*/

	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8command1);
	/*Enable pulse*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_OUTPUT);
	/*  protect the LCD from overload commands */
	_delay_ms(2);

	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_INPUT);
}

void LCD_voidSendData(u8 Copy_u8Data)
{

	/*Set RW pin to write*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_PIN_INPUT);

	/*Set Rs pin to Data*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_PIN_OUTPUT);

	/*Send the Data to the LCD*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Data);

	/*Enable pulse*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_OUTPUT);

	_delay_ms(2);

	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_INPUT);
}


void LCD_voidInit(void)
{
	DIO_u8SetPortDirection(LCD_u8_DATA_PORT,DIO_u8_PORT_HIGH);
	DIO_u8SetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_OUTPUT);


	/*Wait for more than 30ms after power up*/
	_delay_ms(40);

	/*Function set command
	 * 1- 2 lines
	 * 2- Font = 5*7
	 * */
	LCD_voidSendCommand(0b00111100);

	/*Wait for more than 39us*/
	_delay_ms(1);

	/* Display On Off control command
	 * 1- Display enable
	 * 2- Cursor off
	 * 3- Blink Cursor off
	 * */
	LCD_voidSendCommand(0x0F);

	/*Wait for more than 39us*/
	_delay_ms(1);

	/*LCD Clear*/
	LCD_voidSendCommand(0x01);

	/*Delay more than 1.53 ms*/
	_delay_ms(2);
}

void LCD_SendString(u8 ARRAY[])
{
	u8 i =0;
	while (ARRAY[i]!='\0')
	{
		LCD_voidSendData(ARRAY[i]);
		i++;
	}
}

void LCD_SendNumber(u32 Copy_u32NUmber)
{
	u32 Local_32Reserved=1;

	/* reverse the number for display  */
	while (Copy_u32NUmber!='\0')
	{
		Local_32Reserved=Local_32Reserved*10 +Copy_u32NUmber%10;
		Copy_u32NUmber/=10;
	}
	/* display the number on LCD*/
	do{
		LCD_voidSendData((Local_32Reserved%10)+'0');
		Local_32Reserved /=10;
	}
	while (Local_32Reserved !=1);
}

void LCD_voidGoToXY(u8 Copy_u8Xpos,u8 Copy_u8Ypos)
{
	u8 Local_u8Address;
	if(0==Copy_u8Xpos)
	{
		Local_u8Address=Copy_u8Ypos;
	}
	else if(1==Copy_u8Xpos)
	{
		Local_u8Address=0x40+Copy_u8Ypos;
	}
	/*SET_BIT(Local_u8Address,7);
	 or Local_u8Address|=1<<7
	 * or Local_u8Adress +0b10000000
	 * or Local_u8Adress+=128 */
	 /* Send command to control Xy display on DD Ram */
	LCD_voidSendCommand(Local_u8Address+128);
}

void LCD_voidWriteSpecialCharacter(u8  *Copy_p8uPattern , u8  Copy_u8PatternNumber , u8 Copy_u8Xpos , u8 Copy_u8Ypos)
{
	 u8 Local_u8Adress,Local_u8patternCounter=0;
	 /* Calculate the addres  */
	 Local_u8Adress=Copy_u8PatternNumber*8;
	 /* Send to CGRam to put the pattern  */

	 /* this command from PDF to access memory CGRam */
	 LCD_voidSendCommand(Local_u8Adress+64);

	 /* Send the pattern inside the CGRAM*/
	 for(Local_u8patternCounter ; Local_u8patternCounter<8 ; Local_u8patternCounter++ )
	 {
		 LCD_voidSendData(Copy_p8uPattern[Local_u8patternCounter]);
	 }
	 /* Sending the pattern from CGRAM to DDRam to display
	  * X-Y to choose the location  */
	 LCD_voidGoToXY(Copy_u8Xpos,Copy_u8Ypos) ;
	 LCD_voidSendData(Copy_u8PatternNumber);
}

void LCD_voidClearDisplay(void)
{
	LCD_voidSendCommand(1);
}

#elif LCD_MODE==LCD_MODE_4_Bit


void LCD_voidSendCommand(u8 Copy_u8command1)
{

	/*Set RW pin to write*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_PIN_INPUT);

	/*Set Rs pin to command*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_PIN_INPUT);

	/*Send the command to the LCD*/

	DIO_u8SetPortValue(LCD_u8_DATA_PORT,(Copy_u8command1)&0xF0);

	/*Enable pulse*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_OUTPUT);
	/*  protect the LCD from overload commands */
	_delay_ms(2);

	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_INPUT);

	DIO_u8SetPortValue(LCD_u8_DATA_PORT,(Copy_u8command1<<4)&(0xF0));

	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_OUTPUT);
		/*  protect the LCD from overload commands */
	_delay_ms(2);

		DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_INPUT);
}

void LCD_voidSendData(u8 Copy_u8Data)
{

	/*Set RW pin to write*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_PIN_INPUT);

	/*Set Rs pin to Data*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_PIN_OUTPUT);

	/*Send the Data to the LCD*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,(Copy_u8Data&0xF0));

	/*Enable pulse*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_OUTPUT);

	_delay_ms(2);

	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_INPUT);

	DIO_u8SetPortValue(LCD_u8_DATA_PORT,((Copy_u8Data<<4)&0xF0));

	/*Enable pulse*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_OUTPUT);

	_delay_ms(2);

	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_INPUT);
}


void LCD_voidInit(void)
{
	/* these pins are for RS/RW/E */
	DIO_u8SetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_OUTPUT);
	/* these pins are for Data */
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT,LCD_BIT0,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT,LCD_BIT0,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT,LCD_BIT0,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT,LCD_BIT0,DIO_u8_PIN_OUTPUT);

	/*Wait for more than 30ms after power up*/
	_delay_ms(40);

	/*Function set command
	 * 1- 2 lines
	 * 2- Font = 5*7
	 * */
	/* 4bit mode */
	LCD_voidSendCommand(0x02);
	LCD_voidSendCommand(0x28);
	LCD_voidSendCommand(0x0c);

	/*Wait for more than 39us*/
	//_delay_ms(1);

	/* Display On Off control command
	 * 1- Display enable
	 * 2- Cursor off
	 * 3- Blink Cursor off
	 * */
	LCD_voidSendCommand(0x06);
	LCD_voidSendCommand(0x01);

	/*Wait for more than 39us*/
	//_delay_ms(1);

	/*LCD Clear*/
	/*LCD_voidSendCommand(0);
	LCD_voidSendCommand(1);

	/*Delay more than 1.53 ms*/
	_delay_ms(2);
}

void LCD_SendString(u8 ARRAY[])
{
	u8 i =0;
	while (ARRAY[i]!='\0')
	{
		LCD_voidSendData(ARRAY[i]);
		i++;
	}
}

void LCD_SendNumber(u32 Copy_u32NUmber)
{
	u32 Local_32Reserved=1;

	/* reverse the number for display  */
	while (Copy_u32NUmber!='\0')
	{
		Local_32Reserved=Local_32Reserved*10 +Copy_u32NUmber%10;
		Copy_u32NUmber/=10;
	}
	/* display the number on LCD*/
	do{
		LCD_voidSendData((Local_32Reserved%10)+'0');
		Local_32Reserved /=10;
	}
	while (Local_32Reserved !=1);
}

void LCD_voidGoToXY(u8 Copy_u8Xpos,u8 Copy_u8Ypos)
{
	u8 Local_u8Address;
	if(0==Copy_u8Xpos)
	{
		Local_u8Address=Copy_u8Ypos;
	}
	else if(1==Copy_u8Xpos)
	{
		Local_u8Address=0x40+Copy_u8Ypos;
	}
	/*SET_BIT(Local_u8Address,7);
	 or Local_u8Address|=1<<7
	 * or Local_u8Adress +0b10000000
	 * or Local_u8Adress+=128 */
	 /* Send command to control Xy display on DD Ram */


	//LCD_voidSendCommand(1);
	LCD_voidSendCommand(Local_u8Address+128);

}

void LCD_voidWriteSpecialCharacter(u8  *Copy_p8uPattern , u8  Copy_u8PatternNumber , u8 Copy_u8Xpos , u8 Copy_u8Ypos)
{
	 u8 Local_u8Adress,Local_u8patternCounter=0;
	 /* Calculate the addres  */
	 Local_u8Adress=Copy_u8PatternNumber*8;
	 /* Send to CGRam to put the pattern  */

	 /* this command from PDF to access memory CGRam */
	 LCD_voidSendCommand(Local_u8Adress+64);

	 /* Send the pattern inside the CGRAM*/
	 for(Local_u8patternCounter ; Local_u8patternCounter<8 ; Local_u8patternCounter++ )
	 {
		 LCD_voidSendData(Copy_p8uPattern[Local_u8patternCounter]);
	 }
	 /* Sending the pattern from CGRAM to DDRam to display
	  * X-Y to choose the location  */
	 LCD_voidGoToXY(Copy_u8Xpos,Copy_u8Ypos) ;
	 LCD_voidSendData(Copy_u8PatternNumber);
}

void LCD_voidClearDisplay(void)
{
	LCD_voidSendCommand(1);
}



























#endif



