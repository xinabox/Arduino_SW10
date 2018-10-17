/*
	This is a library for the SW10 
	DIGITAL TEMPERATURE SENSOR

	The board uses I2C for communication.
	
	The board communicates with the following I2C device:
	-	LM75B
	
	Data Sheets:
	LM75B - https://www.nxp.com/docs/en/data-sheet/LM75B.pdf
*/

#ifndef xSW10_h
#define xSW10_h

// System Includes
#include <inttypes.h>
#include <Arduino.h>
#include "xCore.h"
#include "math.h"

// Register Defines
#define LM75B_REG_CONF   	0x01
#define LM75B_REG_TEMP     	0x00
#define LM75B_REG_TOS 		0x03
#define LM75B_REG_THYST    	0x02

/*=========================================================================*/


/*=========================================================================*/

class xSW10: public xCoreClass
{
    public:
		/**
		* Constructor
		* Creates a new instance of Sensor class.
		*/	
		xSW10();
		xSW10(uint8_t addr);
		
		/*
		* Runs the setup of the sensor. 
		* Call this in setup(), before reading any sensor data.
		*
		* @return true if setup was successful.
		*/
		bool 	begin();			
		
		/*
		* Used read all raw sensors data and convert to usefull results. 
		* Call this in loop(). Used to call sensor data reads.
		*
		* @return none
		*/
		void 	poll(void);                      
		
		/*
		* Used to get the temperature value in degress celcuis.
		* Call this in loop(). Used to get sensor temperature.
		*
		* @return temperature. Returns float value of temperature.
		*/		
		float 	getTempC(void);				
		
		/*
		* Used to get the temperature value in degress farenhied.
		* Call this in loop(). Used to get sensor temperature.
		*
		* @return temperature. Returns float value of temperature.
		*/		
		float 	getTempF(void);			
		
	private:		
    
		/*
		* Reads RAW temperature data.
		*
		* @return none
		*/		
		void readTemperature(void);
    
		float   tempC;	// stores temperature value
		uint8_t LM75B_I2C_ADDR;
};

#endif
