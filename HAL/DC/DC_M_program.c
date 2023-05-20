

#include "..\..\LIB\STD_TYPES.h"

#include "..\..\LIB\BIT_MATH.h"
#include "../../MCAL/DIO_Per/DIO_interface.h"

#include "DC_M_Config.h"
#include "DC_M_Private.h"
#include "DC_M_interface.h"

#if (DC_Confg==DC_Config_PREBUILD)

void DCM_voidInitial(void)
{
	DIO_u8SetPinDirection(DC_M_PORT,DC_M_PIN0,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(DC_M_PORT,DC_M_PIN1,DIO_u8_PIN_OUTPUT);
}

void DCM_voidRotateCW(void)
{
	DIO_u8SetPinValue(DC_M_PORT,DC_M_PIN0,DIO_u8_PIN_INPUT);
	DIO_u8SetPinValue(DC_M_PORT,DC_M_PIN1,DIO_u8_PIN_OUTPUT);
}

void DCM_voidRotateCCW(void)
{
	DIO_u8SetPinValue(DC_M_PORT,DC_M_PIN1,DIO_u8_PIN_INPUT);
	DIO_u8SetPinValue(DC_M_PORT,DC_M_PIN0,DIO_u8_PIN_OUTPUT);
}
void DCM_voidStop(void)
{
	DIO_u8SetPinValue(DC_M_PORT,DC_M_PIN0,DIO_u8_PIN_INPUT);
	DIO_u8SetPinValue(DC_M_PORT,DC_M_PIN1,DIO_u8_PIN_INPUT);


}


#elif (DC_Confg==DC_Config_RUNTIME)



void DCM_voidInitial(DC_Motor * M)
{
	DIO_u8SetPinDirection(M->Copy_u8Port,M->Copy_u8Pin1,M->DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(M->Copy_u8Port,M->Copy_u8Pin2,M->DIO_u8_PIN_OUTPUT);
}

void DCM_voidRotateCW(DC_Motor * M)
{
	DIO_u8SetPinValue(M->Copy_u8Port,M->Copy_u8Pin1,M->DIO_u8_PIN_INPUT);
	DIO_u8SetPinValue(M->Copy_u8Port,M->Copy_u8Pin2,M->DIO_u8_PIN_OUTPUT);
}

void DCM_voidRotateCCW(DC_Motor * M)
{
	DIO_u8SetPinValue(M->Copy_u8Port,M->Copy_u8Pin2,M->DIO_u8_PIN_INPUT);
	DIO_u8SetPinValue(M->Copy_u8Port,M->Copy_u8Pin1,M->DIO_u8_PIN_OUTPUT);
}
void DCM_voidStop(DC_Motor * M)
{
	DIO_u8SetPinValue(M->Copy_u8Port,M->Copy_u8Pin1,M->DIO_u8_PIN_INPUT);
	DIO_u8SetPinValue(M->Copy_u8Port,M->Copy_u8Pin2,M->DIO_u8_PIN_INPUT);


}

