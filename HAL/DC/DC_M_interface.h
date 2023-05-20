
#ifndef DC_M_INTERFACE_H_
#define DC_M_INTERFACE_H_

#if (DC_Confg==DC_Config_PREBUILD)

/*initial for DC Motor  */
void DCM_voidInitial(void);


/*Function To rotate CW */
void DCM_voidRotateCW(void);


/* Function To rotate CCW*/
void DCM_voidRotateCCW(void);

/*Stop the Motor */
void DCM_voidStop(void);


#elif (DC_Confg==DC_Config_RUNTIME)

/* Acess struct M and make it's initial values
 * M->Copy_u8Port=DIO_u8_PORTA
 * M->Copy_u8Pin1=DIO_u8_PIN0
 * M->Copy_u8Pin1=DIO_u8_PIN1
 *
 * each motor you create an object you must inilize this ins
 *  */
typedef struct {
	u8 Copy_u8Port ;
	u8 Copy_u8Pin1 ;
	u8 Copy_u8Pin2 ;
}DC_Motor;

/*initial for DC Motor  */ 
void DCM_voidInitial(DC_Motor * M);


/*Function To rotate CW */
void DCM_voidRotateCW(DC_Motor * M);


/* Function To rotate CCW*/
void DCM_voidRotateCCW(DC_Motor * M);

/*Stop the Motor */
void DCM_voidStop(DC_Motor * M);

#endif
