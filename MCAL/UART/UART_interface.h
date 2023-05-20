


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*Run Time Config*/
typedef struct {
	u8 parity;
	u8 stop_bits;
	u8 mode;
}USART_t;

/*for chose mode  */
#define TRANSMIT_ENABLE		0
#define RECIVE_ENABLE		1
#define TRANSIVE_ENABLE		2

/*Parity */
#define NO_PARITY			0
#define PARITY_EVEN			2
#define PARITY_ODD			3

/*Stop bits */
#define 	BIT_1			0
#define 	BIT_2			1

void USART_voidIni(USART_t * PtrToUART);

/***********************Send and recive Async *************************/
u8 USART_u8SendDataAsynchrouns(u8 Copy_u8Data	,	void (*PtrToCallBackFunc)(void));

 u8 USART_u8ReciveDataAsynchronous(u8 * copy_Data,void (*PtrToCallBackFunc)(void));

/**********************Send and recive synchronous ********************/
 void USART_voidSendDataSync(u8 Copy_u8Data);
 void USART_voidReciveDataSync(u8 * Copy_reciveData);

 /********************Send String and recive String********************/
u8 USART_u8SendString(char * Copy_Sring);
u8 USART_u8RecivString(u8 * Copy_Sring);
u8 USART_voidReciveDataSyncSt(void);
#endif
