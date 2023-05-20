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
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define ADC_CHANNEL0	0
#define ADC_CHANNEL1	1
#define ADC_CHANNEL2	2
#define ADC_CHANNEL3	3
#define ADC_CHANNEL4	4
#define ADC_CHANNEL5	5
#define ADC_CHANNEL6	6
#define ADC_CHANNEL7	7



/*this fun shal inilize the ADC convert */
void ADC_voidINi(void);


u8 ADC_u8StartConverAsync(u8 Copy_u8Channel,u16 * Copy_u8Reading);

u8 ADC_u8StartConverSyncRonous(u8 Copy_u8Channel,u16 * Copy_u8Reading);

void ADC_voidSetCallBack(void(* Copy_PtrToFun)(void));





#endif /* DIO_INTERFACE_H_ */
