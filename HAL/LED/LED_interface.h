/*
 * LED_interface.h
 *
 *  Created on: 25Mar.,2023
 *      Author: osama
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/* Create the initial function to set port and pins as output*/

u8 LED_u8IntialPort(u8 Copy_u8_Port,u8 Copy_u8_Pin);


/* Led on to make the led on */
u8 LED_u8LedOn(u8 Copy_u8_Port,u8 Copy_u8_Pin);

/* led off */
u8 LED_u8LedOff(u8 Copy_u8_Port,u8 Copy_u8_Pin);

/*toggle a pin  */
u8 LED_u8Toggle(u8 Copy_u8_Port,u8 Copy_u8_Pin);





#endif /* LED_INTERFACE_H_ */
