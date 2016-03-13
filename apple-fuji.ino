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

typedef struct {
    uint16_t schema;
    uint16_t address;       // Address of Arduino
    uint32_t uptime_ms;     // Time since start of program

    uint16_t batt_mv;   // Battery Voltage (in milli volts)
    uint16_t panel_mv;  // Panel Voltage (in milli volts)
    uint16_t bmp085_press_pa;   // Pressure Value (in pascals)
    uint16_t bmp085_temp_decic;  // Temperature Value (in celsius)
    uint16_t humidity_centi_pct;
    uint16_t apogee_w_m2;
} schema_1;

typedef struct {
    uint16_t schema;
    uint16_t address;       // Address of Arduino
    uint32_t uptime_ms;     // Time since start of program

    uint8_t message[40];
} schema_2;

schema_1 data;
schema_2 data_message;

void payload_init(void);
void payload_init2(void);

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

    // Initialize payloads
    payload_init();
    payload_init2();

    // Send regular payload
    uint8_t* payload = (uint8_t*) &data;
    int size = sizeof(data);
    comms_send_payload(payload, size);

    // Send a message
    payload = (uint8_t*) &data_message;
    size = sizeof(data_message);
    comms_send_payload(payload, size);

    delay(300);
}

void payload_init2()
{

    uint8_t text[40] = "Hello, my name is kenny and I like";
    int len = sizeof(text);

    data_message.schema = 2;
    data_message.address = 178;
    memcpy(&data_message.message, text, len);
}

void payload_init()
{
    data.schema = 1;
    data.address = 178;
    data.uptime_ms = millis();

    data.bmp085_press_pa = sensors_sample_press();
    data.bmp085_temp_decic = sensors_sample_temp();
    data.humidity_centi_pct = sensors_sample_humid();
    data.batt_mv = sensors_sample_batt();
    data.panel_mv = sensors_sample_panel();
    data.apogee_w_m2 = sensors_sample_irr();
}
