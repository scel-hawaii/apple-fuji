#include "sensors.h"

OneWire oneWire1(_PIN_AMB_TEMP);
DallasTemperature dallas_amb_sen(&oneWire1);

OneWire oneWire2(_PIN_ROOF_TEMP);
DallasTemperature dallas_roof_sen(&oneWire2);

SHT1x sht1x(_PIN_HUMID_DATA, _PIN_HUMID_CLK);

Adafruit_BMP085 bmp085;
Adafruit_INA219 ina219_Solar;

void sensors_init(void)
{
    bmp085.begin();
    ina219_Solar.begin();
}

int sensors_sample_batt(void)
{
    int value = analogRead(_PIN_BATT_V)*5000.0/1023;
    return value;
}

int sensors_sample_panel(void)
{
    int value = 2*analogRead(_PIN_SOLAR_V)*5000.0/1023;
    return value;
}

int sensors_sample_irr(void)
{
    int value = analogRead(_PIN_APOGEE_V)*5000.0/1023;
    return value;
}

int sensors_sample_press(void)
{
    int value = bmp085.readPressure();
    return value;
}

int sensors_sample_humid(void)
{
    int value =  sht1x.readHumidity();
    return value;
}

int sensors_sample_temp(void)
{
    int value =  bmp085.readTemperature()*10;
    return value ;
}
