/********************************************************************/
/********************************************************************/
/******  Name        : Osama Gamil  	  					*********/
/******  File Name   : DIO_mainProgram.c    				*********/
/******  Layer	     :	MCAL		 	  					*********/
/******  Date 	     : 22/3/2023		  					*********/
/******  Description : function prototype 					*********/
/********************************************************************/
/********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"



/*this function shall set the direction of specific pin*/
u8  DIO_u8SetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_PinDirction)
{
	u8 Local_u8ErrorState=OK; /* to check if the function worked correctly of not */

	/*to check the number he enter about the pins*/
	if(Copy_u8Pin>7)
	{
		Local_u8ErrorState=NOK;
	}
	else{
	if(Copy_PinDirction==DIO_u8_PIN_INPUT) /* pin input = 0 so we use clear bit*/
	{
		switch(Copy_u8Port) /*chose witch port the use enter */
		{
			case DIO_u8_PORTA:
			{
				CLR_BIT(DDRA,Copy_u8Pin);
				break;
			}
			case DIO_u8_PORTB:
			{
				CLR_BIT(DDRB,Copy_u8Pin);
				break;
			}
			case DIO_u8_PORTC:
			{
				CLR_BIT(DDRC,Copy_u8Pin);
				break;
			}
			case DIO_u8_PORTD:
			{
				CLR_BIT(DDRD,Copy_u8Pin);
				break;
			}
			default:
			{
				Local_u8ErrorState=NOK;
			}
		}
	}
	else if(Copy_PinDirction==DIO_u8_PIN_OUTPUT) /* output then pin =1 so we use set pin fun*/
	{
		switch(Copy_u8Port) /*chose witch port the use enter */
		{
			case DIO_u8_PORTA:
			{
				SET_BIT(DDRA,Copy_u8Pin);
				break;
			}
			case DIO_u8_PORTB:
			{
				SET_BIT(DDRB,Copy_u8Pin);
				break;
			}
			case DIO_u8_PORTC:
			{
				SET_BIT(DDRC,Copy_u8Pin);
				break;
			}
			case DIO_u8_PORTD:
			{
				SET_BIT(DDRD,Copy_u8Pin);
				break;
			}
			default:
			{
				Local_u8ErrorState=NOK;
			}
		}
	}
	else
	{
			Local_u8ErrorState=NOK;
	}
	}
	return Local_u8ErrorState;

}

/*write high or low on a specific pin*/
u8  DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_PinValue)
{
	u8 Local_u8ErrorState=OK; /* to check if the function worked correctly of not */

		/*to check the number he enter about the pins*/
		if(Copy_u8Pin>7)
		{
			Local_u8ErrorState=NOK;
		}
		else{
		if(DIO_u8_PIN_OUTPUT==Copy_PinValue) /* pin input = 0 so we use set bit*/
		{
			switch(Copy_u8Port) /*chose witch port the use enter */
			{
				case DIO_u8_PORTA:
				{
					SET_BIT(PORTA,Copy_u8Pin);
					break;
				}
				case DIO_u8_PORTB:
				{
					SET_BIT(PORTB,Copy_u8Pin);
					break;
				}
				case DIO_u8_PORTC:
				{
					SET_BIT(PORTC,Copy_u8Pin);
					break;
				}
				case DIO_u8_PORTD:
				{
					SET_BIT(PORTD,Copy_u8Pin);
					break;
				}
				default:
				{
					Local_u8ErrorState=NOK;
				}
			}
		}
		else if(DIO_u8_PIN_INPUT==Copy_PinValue) /* output then pin =1 so we use set pin fun*/
		{
			switch(Copy_u8Port) /*chose witch port the use enter */
			{
				case DIO_u8_PORTA:
				{
					CLR_BIT(PORTA,Copy_u8Pin);
					break;
				}
				case DIO_u8_PORTB:
				{
					CLR_BIT(PORTB,Copy_u8Pin);
					break;
				}
				case DIO_u8_PORTC:
				{
					CLR_BIT(PORTC,Copy_u8Pin);
					break;
				}
				case DIO_u8_PORTD:
				{
					CLR_BIT(PORTD,Copy_u8Pin);
					break;
				}
				default:
				{
					Local_u8ErrorState=NOK;
				}
			}
		}
		else
		{
				Local_u8ErrorState=NOK;
		}
		}
		return Local_u8ErrorState;

}

/*set port direction*/
u8  DIO_u8SetPortDirection(u8 Copy_u8Port,u8 Copy_Direction)
{
	/*to check the function worked correctly or not */
	u8 Local_u8ErrorState=OK;

	/*to check the user enter the direction correctly or not */
	if((Copy_Direction==DIO_u8_PORT_INPUT)||(Copy_Direction==DIO_u8_PORT_OUTPUT))
	{
		switch(Copy_u8Port)    /*to check any port he entered*/
		{
			case DIO_u8_PORTA:
			{
				DDRA=Copy_Direction;  	/* set the direction of register as port */
				break;
			}
			case DIO_u8_PORTB:
			{
				DDRB=Copy_Direction;
				break;
			}
			case DIO_u8_PORTC:
			{
				DDRC=Copy_Direction;
				break;
			}case DIO_u8_PORTD:
			{
				DDRD=Copy_Direction;
				break;
			}
			default:
			{
				Local_u8ErrorState=NOK;
				break;
			}
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

/*set port value */
u8  DIO_u8SetPortValue(u8 Copy_u8Port,u8 Copy_PortValue)
{
	/*to check the function worked correctly or not */
		u8 Local_u8ErrorState=OK;

		/*to check the user enter the direction correctly or not */
		if((Copy_PortValue>=0) || (Copy_PortValue >= 255))
		{
			switch(Copy_u8Port)    /*to check any port he entered*/
			{
				case DIO_u8_PORTA:
				{
					PORTA=Copy_PortValue;  	/* set the direction of register as port */
					break;
				}
				case DIO_u8_PORTB:
				{
					PORTB=Copy_PortValue;
					break;
				}
				case DIO_u8_PORTC:
				{
					PORTC=Copy_PortValue;
					break;
				}case DIO_u8_PORTD:
				{
					PORTD=Copy_PortValue;
					break;
				}
				default:
				{
					Local_u8ErrorState=NOK;
					break;
				}
			}
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
		return Local_u8ErrorState;
}

/*read signal from pin*/
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 * Copy_PinValue) /* pointer is for the pin value return  */
{
	u8 Local_u8ErrorState=OK;
	if(Copy_PinValue!=NULL)
	{
		if(Copy_u8Pin<8)
		{
			switch(Copy_u8Port)
			{
				case DIO_u8_PORTA:
					{
						* Copy_PinValue=GET_BIT(PINA,Copy_u8Pin);	/* read the value that in register pina  */
						break;
					}
					case DIO_u8_PORTB:
					{
						* Copy_PinValue=GET_BIT(PINB,Copy_u8Pin);
						break;
					}
					case DIO_u8_PORTC:
					{
						* Copy_PinValue=GET_BIT(PINC,Copy_u8Pin);
						break;
					}case DIO_u8_PORTD:
					{
						* Copy_PinValue=GET_BIT(PIND,Copy_u8Pin);
						break;
					}
					default:
					{
						Local_u8ErrorState=NOK;
						break;
					}
			}
		}
		else
			{
				Local_u8ErrorState=NOK;
			}
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}

	return Local_u8ErrorState;
}


/*  this function is to toggle (reverse a specific value 1 > 0 or 0> 1)*/
u8 DIO_u8TogglePin(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	/* to check the error if this function done or not */
	u8 Local_u8ErrorState=OK;
	if(Copy_u8Pin<8)
	{
		switch(Copy_u8Port)
		{
			case DIO_u8_PORTA:
			{
				TGL_BIT(PORTA,Copy_u8Pin);
				break;
			}
			case DIO_u8_PORTB:
			{
				TGL_BIT(PORTB,Copy_u8Pin);
				break;
			}
			case DIO_u8_PORTC:
			{
				TGL_BIT(PORTC,Copy_u8Pin);
				break;
			}
			case DIO_u8_PORTD:
			{
				TGL_BIT(PORTD,Copy_u8Pin);
				break;
			}
			default :
			{
				Local_u8ErrorState=NOK;
				break;
			}
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;

}


