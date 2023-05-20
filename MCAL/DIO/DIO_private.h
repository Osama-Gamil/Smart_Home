/********************************************************************************/
/********************************************************************************/
/******  Name        : Osama Gamil  	  								*********/
/******  File Name   : DIO_Private.h    								*********/
/******  Layer	     :	MCAL		 	  								*********/
/******  Date 	     : 22/3/2023		  								*********/
/******  Description : function prototype 								*********/
/********************************************************************************/
/********************************************************************************/

/* File guard */
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*Registers to access port A  */
#define   DDRA      *((volatile u8 *)(0x3A))
#define   PORTA		*((volatile u8 *)(0x3B))
#define   PINA      *((volatile u8 *)(0x39))

/*Registers to access port B  */
#define   DDRB      *((volatile u8 *)(0x37))
#define   PORTB		*((volatile u8 *)(0x38))
#define   PINB 		*((volatile u8 *)(0x36))

/*Registers to access port C  */
#define   DDRC		*((volatile u8 *)(0x34))
#define   PORTC		*((volatile u8 *)(0x35))
#define   PINC		*((volatile u8 *)(0x33))

/*Registers to access port D  */
#define   DDRD 		*((volatile u8 *)(0x31))
#define   PORTD	 	*((volatile u8 *)(0x32))
#define   PIND		*((volatile u8 *)(0x30))


#endif /* DIO_PRIVATE_H_ */
