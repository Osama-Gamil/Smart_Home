
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


/***************************Global Pointers**************************************/
void (*Global_PtrToTransmit)(void);
void (*Global_PtrToRevice)(void);

/*****************************Pointer to recieve data ***************************/
u8	* Global_ToReciveData=NULL;


void USART_voidIni(USART_t *PtrToUART)
{

	/*to write on USCRC must bit number 7 =1  */
	/*8 bits */
	u8 USCRC_Value=0;

	/*sel bit 7 =1 */
	SET_BIT(USCRC_Value,UCSRC_URSEL);

	/*set 8 bit  */
	SET_BIT(USCRC_Value,UCSRC_UCSZ0);
	SET_BIT(USCRC_Value,UCSRC_UCSZ1);

	/*chosing between 1 or 2 bits*/
	if(PtrToUART->stop_bits==BIT_2)
		SET_BIT(USCRC_Value,UCSRC_USBS);
	else
		CLR_BIT(USCRC_Value,UCSRC_USBS);



	/*chosing parity  */
	if(PtrToUART->parity==PARITY_EVEN)
	{
		SET_BIT(USCRC_Value,UCSRC_UPM1);
		CLR_BIT(USCRC_Value,UCSRC_UPM0);
	}
	else if(PtrToUART->parity==PARITY_ODD)
	{
		SET_BIT(USCRC_Value,UCSRC_UPM1);
		SET_BIT(USCRC_Value,UCSRC_UPM0);
	}
	else
	{
		CLR_BIT(USCRC_Value,UCSRC_UPM0);
		CLR_BIT(USCRC_Value,UCSRC_UPM1);
	}
	/*Assign the value  into Register  */
	UCSRC=USCRC_Value;

	/*Async mode */
	CLR_BIT(UCSRC,UCSRC_UMSEL);

	/*Set boudrate */
	UBRRL=51;
	if(PtrToUART->mode==TRANSMIT_ENABLE)
		{
			SET_BIT(UCSRB,UCSRB_TXEN);
			CLR_BIT(UCSRB,UCSRB_RXEN);
		}
		else if (PtrToUART->mode==RECIVE_ENABLE)
		{
			CLR_BIT(UCSRB,UCSRB_TXEN);
			SET_BIT(UCSRB,UCSRB_RXEN);
		}
		else if (PtrToUART->mode==TRANSIVE_ENABLE)
		{
			SET_BIT(UCSRB,UCSRB_TXEN);
			SET_BIT(UCSRB,UCSRB_RXEN);
		}
}
void USART_voidSendDataSync(u8 Copy_u8Data)
{
//	SET_BIT(UCSRB,UCSRB_TXEN);
//	SET_BIT(UCSRB,UCSRB_RXEN);

	/* chech UDRE buffer register is empty  */
	while( !  GET_BIT(UCSRA,UCSRA_UDRE));
	/* this register holding the data that will transmit*/
	UDR=Copy_u8Data;

	/*Stack on the flag to check the transmit complete */
	while( ! GET_BIT(UCSRA,UCSRA_TXC));

	/*clear the flag by writing 1 */
	SET_BIT(UCSRA,UCSRA_TXC);
}

/*Recive Data async */
void USART_voidReciveDataSync(u8 *Copy_reciveData)
{
	while(! GET_BIT(UCSRA,UCSRA_RXC));
	/*Get the reading */
	*Copy_reciveData=UDR;
 }


u8 USART_u8SendDataAsynchrouns(u8 Copy_u8Data	,void (*PtrToCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	/*Check the NULL pointer  */
	if(PtrToCallBackFunc!=NULL)
		{
			/* chech UDRE buffer register is empty  */
			while( !  GET_BIT(UCSRA,UCSRA_UDRE));

			/*Enable the interrupt */
			SET_BIT(UCSRB,UCSRB_TXCIE);
			/*Send Data */
			UDR=Copy_u8Data;

			Global_PtrToTransmit=PtrToCallBackFunc;
		}
	else
		{
		Local_u8ErrorState=NULL_POINTER;
		}
return Local_u8ErrorState;

}

u8 USART_u8ReciveDataAsynchronous(u8 * copy_Data,void (*PtrToCallBackFunc)(void))
 {
	u8 Local_u8ErrorState=OK;
	/*Check the NULL pointer  */
	if(PtrToCallBackFunc!=NULL)
		{
			if(copy_Data !=NULL)
				{
				/*Enable the interrupt */
				SET_BIT(UCSRB,UCSRB_RXCIE);
				/*SET Global callback && return value */
				Global_PtrToRevice=PtrToCallBackFunc;
				Global_ToReciveData=copy_Data;
				}
			else
				{
				Local_u8ErrorState=NULL_POINTER;
				}
		}
	else
		{
		Local_u8ErrorState=NULL_POINTER;
		}

	return Local_u8ErrorState;
 }
/*ISR for Reciving  */
 void __vector_13(void)	__attribute__((signal));
 void __vector_13(void)
 {
	 Global_PtrToRevice();
	 *Global_ToReciveData=UDR;
 }

 /*Interrupt for transmit */
 void __vector_15(void)	__attribute__((signal));
 void __vector_15(void)
 {
	 Global_PtrToTransmit();
 }
 u8 USART_u8SendString(char * Copy_Sring)
 {
		u8 Local_u8ErrorState=OK;
		u8 Local_u8Counter=0;
		/*Check the NULL pointer  */
		if(Copy_Sring!=NULL)
			{
				 while(Copy_Sring[Local_u8Counter]	!=	'#')
				 {
					 USART_voidSendDataSync(Copy_Sring[Local_u8Counter]);
					 Local_u8Counter++;
				 }
			}
		else
			{
				Local_u8ErrorState=NULL_POINTER;
			}
		return Local_u8ErrorState;
 }
 u8 USART_u8RecivString(u8 * Copy_Sring)
 {
		u8 Local_u8ErrorState=OK;
		u8 Local_u8Counter=0;
		Copy_Sring[Local_u8Counter] = USART_voidReciveDataSyncSt();
		/*Check the NULL pointer  */
		if(Copy_Sring!=NULL)
			{
				while(Copy_Sring[Local_u8Counter] != '#' )
				{
					Local_u8Counter++;
					Copy_Sring[Local_u8Counter] = USART_voidReciveDataSyncSt();
				}
			Copy_Sring[Local_u8Counter] ='\0';
			}
		else
			{
				Local_u8ErrorState=NULL_POINTER;
			}
		return Local_u8ErrorState;
 }

 u8 USART_voidReciveDataSyncSt(void)
 {
 	while(! GET_BIT(UCSRA,UCSRA_RXC));
 	/*Get the reading */
 	return UDR;
  }
