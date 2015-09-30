/*
 * Apple Fuji
 *
 * Experimental code for the apple weatherbox.
 * Meant to be a complete re-write of the original apple code
 * in clear, concise way.
 *
 */

/* Include program libs */
#include "apple.h"
#include "sensors.h"
#include "comms.h"

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

void sample_sensors(void);

void setup(){
    sensors_init();
    comms_init();
    Serial.begin(9600);
}

void loop(){
    sample_sensors();
    delay(500);
}

void sample_sensors(void){
    int temp = sensors_sampleTempdecic();
    Serial.println(temp);
}
