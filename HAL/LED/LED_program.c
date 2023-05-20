#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"


/* Create the initial function to set port and pins as output*/

u8 LED_u8IntialPort(u8 Copy_u8_Port,u8 Copy_u8_Pin)
{
	u8 Local_u8ErrorState =OK;
	if(Copy_u8_Pin >8)
		{
			Local_u8ErrorState=NOK;
		}
	else
		{
			switch(Copy_u8_Port)
			{
				case DIO_u8_PORTA :
				{
					DIO_u8SetPinDirection(DIO_u8_PORTA,Copy_u8_Pin,DIO_u8_PIN_OUTPUT);
					break;
				}
				case DIO_u8_PORTB :
				{
					DIO_u8SetPinDirection(DIO_u8_PORTB,Copy_u8_Pin,DIO_u8_PIN_OUTPUT);
					break;
				}
				case DIO_u8_PORTC :
			 	 {
			 		DIO_u8SetPinDirection(DIO_u8_PORTC,Copy_u8_Pin,DIO_u8_PIN_OUTPUT);
					break;
				}
				case DIO_u8_PORTD :
				{
					DIO_u8SetPinDirection(DIO_u8_PORTD,Copy_u8_Pin,DIO_u8_PIN_OUTPUT);
					break;
				}
				default:
				{
					Local_u8ErrorState=NOK;
					break;
				}

		}
		}
	return Local_u8ErrorState;
}


/* Led on to make the led on */
u8 LED_u8LedOn(u8 Copy_u8_Port,u8 Copy_u8_Pin)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8_Pin >8)
		{
			Local_u8ErrorState=NOK;
		}
	else
		{
			switch(Copy_u8_Port)
			{
				case DIO_u8_PORTA :
				{
					DIO_u8SetPinValue(DIO_u8_PORTA,Copy_u8_Pin,DIO_u8_PIN_OUTPUT);
					break;
				}
				case DIO_u8_PORTB :
				{
					DIO_u8SetPinValue(DIO_u8_PORTB,Copy_u8_Pin,DIO_u8_PIN_OUTPUT);
					break;
				}
				case DIO_u8_PORTC :
			 	 {
			 		DIO_u8SetPinValue(DIO_u8_PORTC,Copy_u8_Pin,DIO_u8_PIN_OUTPUT);
					break;
				}
				case DIO_u8_PORTD :
				{
					DIO_u8SetPinValue(DIO_u8_PORTD,Copy_u8_Pin,DIO_u8_PIN_OUTPUT);
					break;
				}
				default :
				{
					Local_u8ErrorState=NOK;
					break;
				}

		}
}

	return Local_u8ErrorState;
}

/* led off */
u8 LED_u8LedOff(u8 Copy_u8_Port,u8 Copy_u8_Pin)
{
	u8 Local_u8ErrorState=OK;
		if(Copy_u8_Pin >8)
			{
				Local_u8ErrorState=NOK;
			}
		else
			{
				switch(Copy_u8_Port)
				{
					case DIO_u8_PORTA :
					{
						DIO_u8SetPinValue(DIO_u8_PORTA,Copy_u8_Pin,DIO_u8_PORT_INPUT);
						break;
					}
					case DIO_u8_PORTB :
					{
						DIO_u8SetPinValue(DIO_u8_PORTB,Copy_u8_Pin,DIO_u8_PORT_INPUT);
						break;
					}
					case DIO_u8_PORTC :
				 	 {
				 		DIO_u8SetPinValue(DIO_u8_PORTC,Copy_u8_Pin,DIO_u8_PORT_INPUT);
						break;
					}
					case DIO_u8_PORTD :
					{
						DIO_u8SetPinValue(DIO_u8_PORTD,Copy_u8_Pin,DIO_u8_PORT_INPUT);
						break;
					}
					default :
					{
						Local_u8ErrorState=NOK;
						break;
					}

			}
}

		return Local_u8ErrorState;
}



/*toggle a pin  */
u8 LED_u8Toggle(u8 Copy_u8_Port,u8 Copy_u8_Pin)
{
	u8 Local_u8ErrorState=OK;
			if(Copy_u8_Pin >8)
				{
					Local_u8ErrorState=NOK;
				}
			else
				{
					switch(Copy_u8_Port){
						case DIO_u8_PORTA :
						{
							DIO_u8TogglePin(DIO_u8_PORTA,Copy_u8_Pin);
							break;
						}
						case DIO_u8_PORTB :
						{
							DIO_u8TogglePin(DIO_u8_PORTB,Copy_u8_Pin);
							break;
						}
						case DIO_u8_PORTC :
					 	 {
					 		DIO_u8TogglePin(DIO_u8_PORTC,Copy_u8_Pin);
							break;
						}
						case DIO_u8_PORTD :
						{
							DIO_u8TogglePin(DIO_u8_PORTD,Copy_u8_Pin);
							break;
						}
						default :
						{
							Local_u8ErrorState=NOK;
							break;
						}

				}
}

			return Local_u8ErrorState;
}




