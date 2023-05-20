# Smart_Home#Exciting to share that I just completed a smart home project and I'm thrilled to share the details with you all.

The project involved Automated Air Conditioning and Smart Lock System with Lighting Control System via mobile application(Bluetooth Connection).

Smart Lock System : Have 2 modes Admin mode and User mode you can only add Users to your system through admin mode if you write wrong ID and password in admin mode an alarm system will work.

In user mode you have 3 trials for user name and password if you entered wrong user name or password the alarm system will work.


when enter the right ID and Password the application will ask the user if he want to open the door then ask if he want to open the lighting.

The Air Conditioning system check periodically the temperature and display it on screen(LCD), if temperature above 37 the Motor start to rotate if temperature <37 the Motor stops.

I worked on my project using Layered Architecture .

I used AVR atmega32 microcontroller.

The interfaces I used in HAL layer are EEPROM ,LCD ,DC Motor , Servo Motor ,LEDs and Buzzer.

The peripheral I used in MCAL layer are ADC , Timer ,UART , TWI and DIO.


The EEPROM to save the users .

LCD and DC Motor for Air Condition system.

Servo for Lock System.

LED for lighting.

Buzzer for Alarm system.
