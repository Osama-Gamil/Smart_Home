#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_u8_FIRST_LINE  0
#define LCD_u8_SECOND_LINE 1

/* choose between 8 bit or 4 bit mode
 * for 4 bit mode replace 8 with 4  */
#define LCD_MODE LCD_MODE_8_Bit


/*Send commands to LCD  */
void LCD_voidSendCommand(u8 Copy_u8command);


/*Display data on LCD  1 character */
void LCD_voidSendData(u8 Copy_u8Data);

/*inilize the lcd to work  */
void LCD_voidInit(void);

/*print any string  */
void LCD_SendString(u8 ARRAY[]);
/*display numbers  */
void LCD_SendNumber(u32 Copy_u32NUmber);

/*   1- LCD_u8_FIRST_LINE  0
 	 2- LCD_u8_SECOND_LINE 1
 * */

void LCD_voidGoToXY(u8 Copy_u8Xpos,u8 Copy_u8Ypos);

void LCD_voidWriteSpecialCharacter(u8 * Copy_p8uPattern , u8  Copy_u8PatternNumber , u8 Copy_u8Xpos , u8 Copy_u8Ypos);

void LCD_voidClearDisplay(void);

void LCD_voidShiftRight(u8 Copy_u8DirectionofShift);

#endif
