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
#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_



#define TCCR0  *((volatile u8 *)(0x53))

#define WGM00	6
#define WGM01	3


#define COM00	4
#define COM01	5

#define CS00	0
#define CS01	1
#define CS02	2

/*This register that counter counts in it  */
#define TCNT0	*((volatile u8 *)(0x52))

/*To set the compare value on CTC mode  */
#define OCR0	*((volatile u8 *)(0x5C))

#define TIMSK  *((volatile u8 *)(0x59))




/*********************Setting for timer 1 ********************************/

#define TCCR1A *((volatile u8 *)(0x4F))

/*7,6 Compare outmode for channel A */
#define TCCR1A_COM1A1		7
#define TCCR1A_COM1A0		6


/*5,4 Compare outmode for channel B */
#define TCCR1A_COM1B1		5
#define TCCR1A_COM1B0		4


#define TCCR1A_FOC1A		3
#define TCCR1A_FOC1B		2
/* sed to set mode For channel A */
#define TCCR1A_WGM11		1
#define TCCR1A_WGM10		0



#define TCCR1B *((volatile u8 *)(0x4E))

/*used to set mode For channel A */
#define TCCR1B_WGM13		4
#define TCCR1B_WGM12		3

/*For prescaler seletion */
#define TCCR1B_CS10			0
#define TCCR1B_CS11			1
#define TCCR1B_CS12			2


/*Set the top value on ICR1 Regis but it 2 locations */
#define ICR1	*((volatile u16 *)(0x46))


/*this reg to put the compared value For channel A */
#define OCR1A	*((volatile u16 *)(0x4A))

/*this reg to put the compared value in channel B  */
#define OCR1B	*((volatile u16 *)(0x48))


/*This register that counter counts in it  */
#define TCNT1	*((volatile u16 *)(0x4C))

/*This register is for interrupt flages modes  */
#define TIMSK 	*((volatile u8 *)(0x59))

#define TIMSK_TOIE1			2		//over flow interrupt flag
#define TIMSK_OCIE1B		3		//output compare B match interrupt flag
#define TIMSK_OCIE1A		4		//output compare A match interrupt flag
#define TIMSK_TICIE1		5		//Input Capture Interrupt Enable

/*This Reg is about flages that set when an event happen
 * use it to stack the flages in Sync modes  */
#define TIFR 	*((volatile u8 *)(0x58))

#define TIFR_ICF1		5		//Input Capture Flag
#define TIFR_OCF1A		4		//Output compare Match A Flag
#define TIFR_OCF1B		3		//Output compare Match B Flag
#define TIFR_TOV1		2		//OverFlow Flag


#endif 
