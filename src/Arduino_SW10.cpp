/*
	This is a library for the SW10 
	DIGITAL TEMPERATURE SENSOR

	The board uses I2C for communication.
	
	The board communicates with the following I2C device:
	-	LM75B
	
	Data Sheets:
	LM75B - https://www.nxp.com/docs/en/data-sheet/LM75B.pdf
*/

#include "Arduino_SW10.h"
#include <math.h>
  
/*--Public Class Function--*/

/********************************************************
 	Constructor
*********************************************************/
xSW10::xSW10(void)
{
	tempC = 0.0;
    LM75B_I2C_ADDR = 0x48;
}

xSW10::xSW10(uint8_t addr)
{
	tempC = 0.0;
    LM75B_I2C_ADDR = addr; 
}

/********************************************************
 	Configure Sensor
*********************************************************/
bool xSW10::begin(void)
{
    if(xCore.ping(LM75B_I2C_ADDR)) {
        return true;
    } else {
        return false;
    }
} 

/********************************************************
 	Read Data from LM75B Sensor
*********************************************************/
void xSW10::poll(void)
{
	readTemperature();
}


/********************************************************
 	Temperature from LM75B Sensor in Celcuis
*********************************************************/
float xSW10::getTempC(void)
{
    return tempC;	
}

/********************************************************
 	Convert Temperature from LM75B Sensor to Farenhied
*********************************************************/
float xSW10::getTempF(void)
{
    return (tempC * 1.8 + 32);	
}

/*--Private Class Function--*/

/********************************************************
 	Read Temperature from LM75B Sensor 
*********************************************************/
void xSW10::readTemperature(void)
{
  uint16_t data = xCore.read16(LM75B_I2C_ADDR, LM75B_REG_TEMP);
  tempC = (data >> 5) * 0.125; 
}

