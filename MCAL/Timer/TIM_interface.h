/********************************************************************/
/********************************************************************/
/******  Name        : Osama Gamil  	  					*********/
/******  File Name   : DIO_interface.h    					*********/
/******  Layer	     :	MCAL		 	  					*********/
/******  Date 	     : 22/3/2023		  					*********/
/******  Description : function prototype 					*********/
/********************************************************************/
/********************************************************************/


/****************************************************************************************/
/**************************  Interfacing macro ******************************************/
/****************************************************************************************/
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/*this func shall start timer 0 in compare match mode  */
void TimR0_voidRunTimetoAsync(void(*Copy_ofComareMatch)(void));

void TMR0_voidRunPwmasNonINv(void);

void TMR0_voidSETREGCOM(u8 copy_OCRvalue); // this fun shall set OCR0 reg value to adjust duty cycle

/*That functions to set TMR1  */

void TMR1_voidinit(void);

void TMR1_voidSetCompareChannelA(u16 Copy_u16Value);

/* TMR1clear */
void TMR1_voiCLRTimer1(void);

/*TMR Get reading from timer 1  */
u16 TMR1_voidGetTimerReading(void);



/*this Fun are specfic for PWM
 * 1- Generate PWM with specific Frequancy
 * 2- Select the channel
 * 3- Select the Duty cycle Compare mode(write in OCR)
 *  */

/*Config for Frequancy in TMR1 */

#define FREG_SEL_20			50000
#define FREG_SEL_40			25000
#define FREG_SEL_50			20000
#define FREG_SEL_100		10000
#define FREG_SEL_200		5000
#define FREG_SEL_250		4000
#define FREG_SEL_500		2000
#define FREG_SEL_1000		1000
#define FREG_SEL_2000		500
#define FREG_SEL_2500		400
#define FREG_SEL_5000		200
#define FREG_SEL_10000		100
#define FREG_SEL_20000		50
#define FREG_SEL_50000		20



#define CHANNEL_A		5
#define CHANNEL_B		4
/*Please Set pin Direction to output mode using dio before using the fun*/
void TMR1_PWMMode(u8 Copy_u8Channel,u16 Copy_u8Frequancy);
void TMR1_SetPWMCompare(u16 Copy_u16Compare);

/*FunC to Set the Duty Cycle Direct*/
void TMR1_voidSetDutyCyc(u8 Copy_u8DutyCyle);




/*Function For Delay (input in msec)
 * 1- Sync
 * 2- Asnyc */
void TMR1_voidDelayMsSync(u16 Copy_u16TimeMs);


/*Delay in ms ASynchrounous then activate the ISR and interrupts  */
void TMR1_voidDelayMsAsync(u16 Copy_u16TimeMs);

/*Call bakc fun to send Interrupt event */
u8 Delay_u8CallBack(void (*PtrToFun)(void));

#endif /* DIO_INTERFACE_H_ */
