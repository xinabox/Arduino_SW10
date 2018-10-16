/*************************************************************
  This is an examples for the SW10
  Digital TemperatureSensor

  You can buy one on our store!
  -----> https://xinabox.cc/products/SW10

  This example request a temperature meausrement to be
  made by the SW10 and display the data over the Serial
  bus.

  Supported on the all ☒CHIPs

  The sensor communicates over the I2C Bus.

*************************************************************/

#include <xCore.h>
#include <arduino-SW10.h>

// Singleton Instance of the Sensor
xSW10 SW10;

// Variable to store the Print delat timer
unsigned long lastPrint;

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);

  // Set the I2C Pins for CW01
#ifdef ESP8266
  Wire.pins(2, 14);
  Wire.setClockStretchLimit(15000);
#endif

  // Start the I2C Comunication
  Wire.begin();

  // Start the  SW01 Sensor
  SW10.begin();

  Serial.println("================================");
  Serial.println("    XINABOX SW10 Temperature    ");
  Serial.println("================================");

  //Delay for sensor to normalise
  delay(5000);
}

void loop() {
  // Create a variable to store the data read from SW01
  float tempC;
  float tempF;
  tempC = tempF = 0;

  // Read and calculate data from SW10 sensor
  SW10.poll();

  if ((millis() - lastPrint) > 2000/*SERIAL_PRINT_DELAY*/) {

    // Request SW10 to get the temperature measurement and store in
    // the temperature variable
    tempC = SW10.getTempC(); // Temperature in Celcuis
    tempF = SW10.getTempF(); // Temperature in Farenheit

    // Display the recoreded data over the Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println(" C");
    Serial.print("Temperature: ");
    Serial.print(tempF);
    Serial.println(" F");

    Serial.println();

    lastPrint = millis();
  }
}