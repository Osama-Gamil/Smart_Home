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

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"




void	(*Global_ptrEndOfConversion)(void) =NULL ;
u16 * GLobal_Reading ;


void ADC_voidINi(void)
{
	#if	(SELCT_VOLT_REF==ADC_REF_AVCC)
		/*Set the Refernce Voltage by choosing AVCC*/
		SET_BIT(ADMUX,ADMUX_REFS0);
		CLR_BIT(ADMUX,ADMUX_REFS1);
	#elif	SELCT_VOLT_REF==ADC_REF_AREFF
		CLR_BIT(ADMUX,ADMUX_REFS0);
		CLR_BIT(ADMUX,ADMUX_REFS1);
	#elif 	SELCT_VOLT_REF==ADC_REF_INT2_56
		SET_BIT(ADMUX,ADMUX_REFS0);
		SET_BIT(ADMUX,ADMUX_REFS1);

	#else
	#error "Wrong choise in SELCT_VOLT_REF"

	#endif



	#if	RES_SELET==NU_BIT8
		/*Set Lift adjectment 8 MSB resulation */
		SET_BIT(ADMUX,ADMUX_ADLAR);
	#elif	RES_SELET==NU_BIT10
		CLR_BIT(ADMUX,ADMUX_ADLAR);
	#else
	#error "Wrong choise in RES_SELET"

	#endif


	/* Set clk prescaler */
	ADCSRA &=	PRESCALER	;
	ADCSRA |=SELET_PRESCAL;



	/*Enable ADC */
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}


u8 ADC_u8StartConverAsync(u8 Copy_u8Channel,u16 * Copy_u8Reading)
{
	/*enable the intrrupt */
	SET_BIT(ADCSRA,ADCSRA_ADIE);

	ADMUX &=MUX_MASK ;
	ADMUX |=Copy_u8Channel;


	/*assign the reading value  */

	GLobal_Reading=Copy_u8Reading;

	/*Start Converg */

	SET_BIT(ADCSRA,ADCSRA_ADSC);

}
u8 ADC_u8StartConverSyncRonous(u8 Copy_u8Channel,u16 * Copy_u8Reading)
{

	ADMUX &=MUX_MASK ;
	ADMUX |=Copy_u8Channel;
	/*start conversion */
	/*Start Converg */
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*assign the reading value  */


	/*Read the flag  */
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	/*clear the flag */
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	*Copy_u8Reading=ADCH;
}

void ADC_voidSetCallBack(void (* Copy_PtrToFun)(void))
{
	if(Copy_PtrToFun != NULL )
	{
		Global_ptrEndOfConversion=Copy_PtrToFun;
	}
	else
	{
		/* return Error state */
	}
}
void __vector_16(void) __attribute__ ((signal));
void __vector_16(void)
{
	if(Global_ptrEndOfConversion != NULL )
	{
		Global_ptrEndOfConversion();

		#if MODE_8_10BIT==MODE_8BIT
				*GLobal_Reading=ADCH;
		#elif MODE_8_10BIT==MODE_10BIT
				*GLobal_Reading=ADCR;
		#endif

	}

}


