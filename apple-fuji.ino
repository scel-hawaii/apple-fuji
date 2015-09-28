/*
 * Apple Core
 *
 */

/* Include program libs */
#include "apple.h"
#include "sensors.h"

/* Include arduino libs */
#include <Wire.h>
#include <XBee.h>
#include <SoftwareSerial.h>

/* Include external libs */
#include <SHT1x.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_INA219.h>
#include <Adafruit_BMP085.h>
uint8_t test = 0;

void xbeeLoop(){
    SoftwareSerial softserial(2,3);
    softserial.begin(9600);
    test++;

    // Create an XBee object at the top of your sketch
    XBee xbee = XBee();
    
    // Start the serial port
    Serial.begin(9600);

    // Tell XBee to use Hardware Serial. It's also possible to use SoftwareSerial
    xbee.setSerial(softserial);
    
    // Create an array for holding the data you want to send.
    uint8_t payload[] = { test };
    
    // Specify the address of the remote XBee (this is the SH + SL)
    XBeeAddress64 addr64 = XBeeAddress64(0, 0);
    
    // Create a TX Request
    ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
    
    // Send your request
    xbee.send(zbTx);
}

void setup(){
    Sensors_init();
    Serial.begin(9600);
    test = 0;
}

void loop(){
   xbeeLoop();
   int temp = Sensors_sampleTempdecic();
   Serial.println(temp);
   delay(100);
}
