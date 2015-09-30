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

void setup()
{
    comms_init();
    Serial.begin(9600);

    Serial.println("Startup sequence.");
    Serial.println("Startup sequence.");
    Serial.println("Startup sequence.");
    Serial.println("OKAY");
    Serial.println("OKAY");
    Serial.println("OKAY");
    Serial.println("OKAY");
}

void loop()
{
    comms_send_payload();
    delay(1000);
}
