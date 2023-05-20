#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "UART_interface.h"
#include "SRVO_interface.h"
#include "LED_interface.h"
#include "TIM_interface.h"
#include "ADC_interface.h"
#include "EEPROM_interface.h"
#include <util/delay.h>
#include <string.h>


void LED_initFun(void);
u8 Global_Reading=0;
u8 mapping(u8 reading);
void StartConv(void);
void Buzz(void);

void main (void)
{
	/*inilization function for Leds  */
	LED_initFun();

	/*The ADC channal that Get the Temperature  */
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_PIN_INPUT);

	/*inilize LCD */
	LCD_voidInit();

	/*inilize DC */
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_PIN_OUTPUT);
	/*Make the DC at stop condition */
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_PIN_INPUT);
	/*inilization of ADC */
	ADC_voidINi();

	/*Set pin for Buzz */
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_PIN_OUTPUT);

	/* PD5 for servo motor */
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN5,DIO_u8_PIN_OUTPUT);

	SERVO_voidIni(CHANNEL_A);

	/*Function to Start converting and Send the reading to the LCD  */
	//StartConv();

	TWI_voidMasterInit(0);

	char Local_Recive=0;
		USART_t U1;
		U1.mode=TRANSIVE_ENABLE;
		U1.parity=NO_PARITY;
		U1.stop_bits=BIT_1;

		USART_voidIni(&U1);



	/*For transmit and recive PD0 Recive input */
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_PIN_INPUT);
	/*For transmit and recive PD1 Transmit output */
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_PIN_OUTPUT);

	/*Get the ID of user */
	char arr[]={"1:chose admin mode \r\n2:user mode #"};
	USART_u8SendString(arr);
	int number1=0;
	USART_voidReciveDataSync(&number1);
	/*Check the ID is O or M  or S */
	char  name;
	char password;
	u8 ID =0;
	u8 user;
	u8 pass;
	u8 UserName[10];
	u8 PassNew[4];
	if(number1 == '1')
	{
		char arr10[]={"\r\nWelcome to the admin mode\r\n1:insert user\r\n2:remove user #"};
		USART_u8SendString(arr10);
		USART_voidReciveDataSync(&number1);
		if(number1 == '1')
		{
			char arryy[]={"\r\nplease enter the ID :#"} ;
			USART_u8SendString(arryy);
			USART_voidReciveDataSync(&name);
			char arr_2[]={"\r\nplease enter the password :#"};
			USART_u8SendString(arr_2);
			USART_voidReciveDataSync(&ID);

			if((name=='o') && (ID == '1'))
			{
				char arr_3={"\r\nPlease write the new user name :#"};
				USART_u8SendString(arr_3);
				USART_u8RecivString(&UserName);
				u8 address1=100;
				EEPROM_u8SendStr(address1 ,UserName );
				char arr_4={"\r\nPlease write the new Password :#"};
				USART_u8SendString(arr_4);
				USART_u8RecivString(&PassNew);
				/*Sending the data to the EEPROM */
				/*Fixed address but it can change  */

				u8 address2=110;
				EEPROM_u8SendStr(address2 ,PassNew );

				char arryy[]={"\r\n User added succeeded \r\n1:for go to user mode\r\n2:close the program.#"} ;
				USART_u8SendString(arryy);
				USART_voidReciveDataSync(&name);
				if(name =='2')
				{
					char arryy[]={"\r\n Thanks for using the application#"} ;
					USART_u8SendString(arryy);
					while(1);
				}


			}
			else
			{
				char arr_77[]={"\r\n worng admin setting#"};
				USART_u8SendString(arr_77);
			while(1){	Buzz();}
			}
		}
		else
		{
			/*Do nothing */
		}

	}
		u8 User1=0;
		u8 Pass1=0;
		char arr_7={"\r\nWelcome to User Mode please enter ID #"};
		USART_u8SendString(arr_7);
		USART_voidReciveDataSync(&User1);


	if(User1 =='o' )
	{
		char arr2[]={"\r\nEnter Password #"};
		USART_u8SendString(arr2);
		for(u8 counter=0;counter<=3;counter++)
		{
			/*recive password*/
			USART_voidReciveDataSync(&password);

			if((password=='1')|(password=='2')|(password=='3'))
			{
				break;
			}
			else
			{
				char arr3[]={" \r\ninvalid password please try agian #"};
				USART_u8SendString(arr3);


			}
			if(counter==2)
			{
				char arr4[]={"\r\n 3 Times Wrong Password #"};
				USART_u8SendString(arr4);
				while(1)
				{
					Buzz();
				}
			}
		}

	}
	else
	{
		char arr5[]={"\r\ninvalid password please restart the application #"};
		USART_u8SendString(arr5);

		while(1)
		{
			Buzz();
		}
	}

	char arr6[]={"\r\nwelcome home #"};
	USART_u8SendString(arr6);
	_delay_ms(200);

	/*first open the Door  */
	char arr7[]={"\r\nopen the door ? #"};
	USART_u8SendString(arr7);
	/* check yes or no*/
	USART_voidReciveDataSync(&Local_Recive);

	if(Local_Recive=='y')
	{
		SERVO_voidRotate(150);

	}
	else if(Local_Recive=='n')
	{
		char arr8[]={"\r\n Thanks for using the application #"};
		USART_u8SendString(arr8);
		while(1);
	}
	char arr12[]={"Light on ?  #"};
	USART_u8SendString(arr12);

	while(1){
	USART_voidReciveDataSync(&Local_Recive);

	if(Local_Recive=='y')
	{
		USART_voidReciveDataSync(&Local_Recive);
		LED_u8LedOn(DIO_u8_PORTC,DIO_u8_PIN7);
		LED_u8LedOn(DIO_u8_PORTC,DIO_u8_PIN6);
		LED_u8LedOn(DIO_u8_PORTC,DIO_u8_PIN5);
	}
	else if(Local_Recive=='n')
	{
		LED_u8LedOff(DIO_u8_PORTC,DIO_u8_PIN7);
		LED_u8LedOff(DIO_u8_PORTC,DIO_u8_PIN6);
		LED_u8LedOff(DIO_u8_PORTC,DIO_u8_PIN5);
	}
	_delay_ms(250);
	char arr122[]={"\r\nThanks for using the application  #"};
	USART_u8SendString(arr122);
		while(1)
		{
			StartConv();

		}
}
}
void LED_initFun(void){
	/*LEDs for home lightning */
	LED_u8IntialPort(DIO_u8_PORTC,DIO_u8_PIN7);
	LED_u8IntialPort(DIO_u8_PORTC,DIO_u8_PIN6);
	LED_u8IntialPort(DIO_u8_PORTC,DIO_u8_PIN5);
}

void StartConv(void)
{
	u8 local_reading = 0;
	ADC_u8StartConverSyncRonous(ADC_CHANNEL0,&local_reading);

		/*function to map the value to temp */
	local_reading = mapping(local_reading);

	LCD_voidGoToXY(0 , 0);
	LCD_SendNumber((u32)local_reading );

		if(local_reading > 37)
		{
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_PIN_OUTPUT);
		}
		else if (local_reading <= 37)
		{
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_PIN_INPUT);
		}
}
void Buzz(void)
{
	while(1){
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_PIN_OUTPUT);
	_delay_ms(100);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_PIN_INPUT);
	_delay_ms(100);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_PIN_OUTPUT);
	_delay_ms(100);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_PIN_INPUT);
	_delay_ms(100);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_PIN_OUTPUT);
	_delay_ms(100);
	}
}
u8 mapping(u8 reading)
{

u8 local_reading;
local_reading =(u8) (500UL * (u32)(reading) /256UL);
return local_reading ;
}

