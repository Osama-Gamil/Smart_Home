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


#include "TIM_config.h"
#include "TIM_interface.h"
#include "TIM_private.h"

void (*GlobalPTFCTCcallback)(void)=NULL;

/*this Global ptr for ISR of delay of Async Func */
void (*GlobalPtrCallbackDelayA)(void)=NULL;

void TimR0_voidRunTimetoAsync(void(*Copy_ofComareMatch)(void))
{
	/*Set timer 0 mode to be CTC */
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);


	/*Disconnected OC0 pin */
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);



	/*setting compare match value = 250 */
	OCR0=250;


	SET_BIT(TIMSK,0);


	GlobalPTFCTCcallback=Copy_ofComareMatch;


	/*setting prescaller  */
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);




}

void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	GlobalPTFCTCcallback();
}

void TMR0_voidRunPwmasNonINv(void)
{
	/*Set Fast pwm mode */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/*Set NonInverted mode */
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);

	/*Set prescaler */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}

void TMR0_voidSETREGCOM(u8 copy_OCRvalue)// this fun shall set OCR0 reg value to adjust duty cycle
{
	OCR0=copy_OCRvalue;
}

/*For timer 1 setting  */
void TMR1_voidinit(void)
{
	/*Set on top clear on compare  */
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	/* Set Fast pwm mode number 14*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	SET_BIT(TCCR1B,TCCR1B_WGM12);


	/*Set the value in ISR1 Register for mode 20msec(the required value) */
	ICR1=20000;



	/*Set the presscaler to 8  */
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
	SET_BIT(TCCR1B,TCCR1B_CS11);



}
/*Set the Compare value To set duty cycle  */
void TMR1_voidSetCompareChannelA(u16 Copy_u16Value)
{
		OCR1A=Copy_u16Value;
}


/* Get the current reading from TMR1 */
u16 TMR1_voidGetTimerReading(void)
{
	return TCNT1;

}

/*CLR Timer 1  */
void TMR1_voiCLRTimer1(void)
{
	TCNT1=0;
}


/* Functions	For Control the Pwm signals   */
void TMR1_PWMMode(u8 Copy_u8Channel,u16 Copy_u8Frequancy)
{



	/* Set Fast pwm mode number 14*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	SET_BIT(TCCR1B,TCCR1B_WGM12);

	/*Set the value in ISR1 Register for mode 20msec(the required value) */
	ICR1=20000;

SET_BIT(TCCR1A,TCCR1A_COM1A1);
CLR_BIT(TCCR1A,TCCR1A_COM1A0);



	/*Set the presscaler to 8  */
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
	SET_BIT(TCCR1B,TCCR1B_CS11);


}
void TMR1_SetPWMCompare(u16 Copy_u16Compare)
{
	OCR1A=Copy_u16Compare;
}

void TMR1_voidSetDutyCyc(u8 Copy_u8DutyCyle)
{
	OCR1A=((u32)Copy_u8DutyCyle*16384UL)/25;
}

/*Delay in ms Synchrounous Stack on the flag */
void TMR1_voidDelayMsSync(u16 Copy_u16TimeMs)
{
	/*Disconnect Channel A and B Normal Port operation */
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	/*Set on mode CTC number 4*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
	SET_BIT(TCCR1B,TCCR1B_WGM12);

	/*Calculate the Compare Value to put it in OCR1 Reg */
	OCR1A=(((u32)Copy_u16TimeMs*125UL)/16);


	/*Set the prescaler to 1024 */

	SET_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS12);
	CLR_BIT(TCCR1B,TCCR1B_CS11);


	/*Check that the interrupt flag not activate
	 * and stack on the flag till time  */
	while(GET_BIT(TIFR,TIFR_OCF1A)==0);

	/*CLR the Flag  by write logical one to it (overflow flag) */
	SET_BIT(TIFR,TIFR_OCF1A);



}




/*Delay in ms ASynchrounous then activate the ISR and interrupts  */
void TMR1_voidDelayMsAsync(u16 Copy_u16TimeMs)
{
	/*Disconnect Channel A and B Normal Port operation */
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1B1);
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);

	/*Set on mode CTC number 4*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
	SET_BIT(TCCR1B,TCCR1B_WGM12);

	/*Calculate the Compare Value to put it in OCR1 Reg */
	OCR1A=(((u32)Copy_u16TimeMs*125UL)/16);

/* enable the specific interrupt flag */
	SET_BIT(TIMSK,TIMSK_OCIE1A);


	/*Set the prescaler to 1024 */

		SET_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS12);
		CLR_BIT(TCCR1B,TCCR1B_CS11);




}


/* Set the Call Back Function for delay Async*/
u8 Delay_u8CallBack(void (*PtrToFun)(void))
{
	u8 Local_u8ErrorState=OK;
	if(PtrToFun!=NULL)
	{
		GlobalPtrCallbackDelayA=PtrToFun;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}

/* ISR for Async fun*/
void __vector_9(void)	__attribute__((signal));
void __vector_9(void)
{
	GlobalPtrCallbackDelayA();
}

