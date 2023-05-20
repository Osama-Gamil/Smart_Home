
#ifndef DC_M_CONFIG_H_

#define DC_M_CONFIG_H_


/* chose the mode you want
 * 1- Constant pin and port chose (DC_Config_PREBUILD)
 * 2-For change the pin through the run time chose (DC_Config_RUNTIME)*/
#define DC_Confg DC_Config_PREBUILD
/* this config for the PreBuild Configuration */

/*PORT */
#define DC_M_PORT 	 DIO_u8_PORTA

/* For H-bridge define 2 Pins */
#define DC_M_PIN0    DIO_u8_PIN0
#define DC_M_PIN1	 DIO_u8_PIN1



#endif
