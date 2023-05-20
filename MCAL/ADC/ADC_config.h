/********************************************************************/
/********************************************************************/
/******  Name        : Osama Gamil  	  					*********/
/******  File Name   : DIO_interface.h    					*********/
/******  Layer	     :	MCAL		 	  					*********/
/******  Date 	     : 22/3/2023		  					*********/
/******  Description : function prototype 					*********/
/********************************************************************/
/********************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
 
/*referance selection  */
/*
 * 1-ADC_REF_INT2_56
 * 2-ADC_REF_AREFF
 * 3-ADC_REF_AVCC
 * */
#define SELCT_VOLT_REF	ADC_REF_AVCC

/*chosing 8 bit or 10 bit resalution
 * 1-NU_BIT8
 * 2-NU_BIT10
 *  */
#define RES_SELET NU_BIT8


/*Set the prescaler
 *  PRE_SCAL2
*	PRE_SCAL4
*	PRE_SCAL8
*   PRE_SCAL16
*   PRE_SCAL32
*   PRE_SCAL64
*   PRE_SCAL128
* */
#define SELET_PRESCAL 		PRE_SCAL128

/* Choose the Modes
 * MODE_8BIT
 * MODE_10BIT
 *  */
#define MODE_8_10BIT	MODE_8BIT
#endif
