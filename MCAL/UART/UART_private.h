

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/*Reg to recive of transmit data  */
#define UDR			*((volatile u8 *)(0x2C))
/*control status register */
#define UCSRA		*((volatile u8 *)(0x2B))

#define UCSRA_RXC		7		/*Flag bit for recive complete mean that recive buffer is empty */
#define UCSRA_TXC		6		//USART transmit complete
#define UCSRA_UDRE		5		//flag to indicate udr is ready to reacive new data
#define UCSRA_FE		4		// Frame Error
#define UCSRA_DOR		3		//Data over run
#define UCSRA_PE		2		//Parity Error
#define UCSRA_U2X		1		//Double the speed
#define UCSRA_MPCM		0		//multi proccess communicate mode


#define UCSRB		*((volatile u8 *)(0x2A))


#define UCSRB_RXCIE		7		//Recive interrupt enable
#define UCSRB_TXCIE		6		//transimt interrupt enable
#define UCSRB_UDRIE		5		//Data register empty interrupt Enable
#define UCSRB_RXEN		4		//enable recive
#define UCSRB_TXEN		3		//enable trancmit
#define UCSRB_UCSZ2		2		//Character size ( used with bit in UCSRC reg )
#define UCSRB_RXB8		1
#define UCSRB_TXB8		0


#define UCSRC		*((volatile u8 *)(0x40))
#define UCSRC_URSEL		7		//Register select
#define UCSRC_UMSEL		6		//Mode select
#define UCSRC_UPM1		5		//Parity select
#define UCSRC_UPM0		4		//Parity select
#define UCSRC_USBS		3		//Stop bit select 1 or 2(0 ->1)(1->2)
#define UCSRC_UCSZ1		2		//Character size ( used with bit in UCSRB reg )
#define UCSRC_UCSZ0		1		//Character size ( used with bit in UCSRB reg )
#define UCSRC_UCPOL		0		//Clock polarity

#define UBRRL		*((volatile u16 *)(0x29))
#define UBBRH		*((volatile u16 *)(0x40))
#endif
