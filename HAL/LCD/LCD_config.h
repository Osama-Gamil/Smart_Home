#ifndef LCD_CONFG_H_
#define LCD_CONFG_H_



#define LCD_u8_CTRL_PORT  	DIO_u8_PORTA
#define LCD_u8_DATA_PORT	DIO_u8_PORTB
/*Common pins of control LCD  */
#define LCD_u8_RS_PIN		DIO_u8_PIN5
#define LCD_u8_RW_PIN		DIO_u8_PIN6
#define LCD_u8_E_PIN		DIO_u8_PIN7

/* Modes of LCD */
 #define LCD_MODE_4_Bit		1
 #define LCD_MODE_8_Bit		2

/*Data pins for 4 bit modes */
#define LCD_BIT0		DIO_u8_PIN0
#define LCD_BIT1		DIO_u8_PIN1
#define LCD_BIT2		DIO_u8_PIN2
#define LCD_BIT3		DIO_u8_PIN3

#define LCD_Shift_Right 1
#define LCD_Shift_Left  0


#endif
