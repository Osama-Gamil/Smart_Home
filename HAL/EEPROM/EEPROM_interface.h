
#ifndef	EEPROM_INTERFACE_
#define EEPROM_INTERFACE_



/*This Function Shall Send Data to EEPROM*/
void EEPROM_voidSendByte(u16 Copy_u16Address,u8 Copy_u8Data);

/*This Function Shall Read Data from EEPROM*/
u8 EEPROM_u8ReceiveByte(u16 Copy_u16Address);

/*This Function Shall Read String From EEPROM*/
void EEPROM_u8ReceiveStr(u16 Copy_u16Address,u8* Copy_u8Str, u8 Copy_strlength);

/*This Function Shall Send String to EEPROM*/
void EEPROM_u8SendStr(u16 Copy_u16Address,u8* Copy_u8Str);

#endif
