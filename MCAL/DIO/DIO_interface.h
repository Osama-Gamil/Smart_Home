/********************************************************************/
/********************************************************************/
/******  Name        : Osama Gamil  	  					*********/
/******  File Name   : DIO_interface.h    					*********/
/******  Layer	     :	MCAL		 	  					*********/
/******  Date 	     : 22/3/2023		  					*********/
/******  Description : function prototype 					*********/
/********************************************************************/
/********************************************************************/


/********************************************************************************/
/**************************Interfacing macro ************************************/
/********************************************************************************/

/* possible port ID */
#define DIO_u8_PORTA	1
#define DIO_u8_PORTB	2
#define DIO_u8_PORTC	3
#define DIO_u8_PORTD	4

/* Possible pin ID */
#define DIO_u8_PIN0     0
#define DIO_u8_PIN1     1
#define DIO_u8_PIN2     2
#define DIO_u8_PIN3     3
#define DIO_u8_PIN4     4
#define DIO_u8_PIN5     5
#define DIO_u8_PIN6     6
#define DIO_u8_PIN7     7


/*Possible pins direction*/
#define DIO_u8_PIN_OUTPUT 1
#define DIO_u8_PIN_INPUT  0

/*set all port */
#define DIO_u8_PORT_OUTPUT   0xFF
#define DIO_u8_PORT_INPUT    0x00


/*set the value of all port*/
#define DIO_u8_PORT_HIGH   0xFF
#define DIO_u8_PORT_LOW    0

//file guards
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/***********************************************************************************/
/************************** Function prototypes ************************************/
/***********************************************************************************/


/*this function shall set the direction of specific pin*/
u8  DIO_u8SetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_PinDirction);

/*write high or low on a specific pin*/
u8  DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_PinValue);

/*set port direction*/
u8  DIO_u8SetPortDirection(u8 Copy_u8Port,u8 Copy_Direction);

/*set port value */
u8  DIO_u8SetPortValue(u8 Copy_u8Port,u8 Copy_PortValue);

/*read signal from pin*/
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 * Copy_PinValue);


/* Dio toggle values */

u8 DIO_u8TogglePin(u8 Copy_u8Port , u8 Copy_u8Pin);





#endif /* DIO_INTERFACE_H_ */
