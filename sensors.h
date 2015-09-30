#include "apple.h"
#include <SHT1x.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_INA219.h>
#include <Adafruit_BMP085.h>

#ifndef SENSORS_H
#define SENSORS_H

extern OneWire oneWire1;
extern DallasTemperature dallas_amb_sen;

extern OneWire oneWire2;
extern DallasTemperature dallas_roof_sen;

extern SHT1x sht1x;

extern Adafruit_BMP085 bmp085;
extern Adafruit_INA219 ina219_Solar;

void sensors_init(void);
int sensors_sample_batt(void);
int sensors_sample_panel(void);
int sensors_sample_irr(void);
int sensors_sample_press(void);
int sensors_sample_humid(void);
int sensors_sample_temp(void);
#endif

