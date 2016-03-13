#include <Arduino.h>
#include <SoftwareSerial.h>
#include <XBee.h>

#ifndef COMMS_H
#define COMMS_H


void comms_init(void);
void comms_send_payload(uint8_t* payload, int len);

#endif
