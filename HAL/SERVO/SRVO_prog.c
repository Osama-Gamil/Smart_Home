
#include "STD_TYPES.h"
#include "SRVO_interface.h"
#include "TIM_interface.h"


void SERVO_voidIni(u8 Copy_u8Channel)
{


	/*Constant Frequancy 50 Hz */
	 TMR1_PWMMode(Copy_u8Channel,FREG_SEL_50);

}

void SERVO_voidRotate(u8 Copy_u8Degree)
{
	u16 Local_u16ComapreValue;
	 /*Get Compare Value*/
		 Local_u16ComapreValue=(((u16)Copy_u8Degree*175UL)/18)+750;


		 /*Change Degree */
		 TMR1_SetPWMCompare(Local_u16ComapreValue);
}
