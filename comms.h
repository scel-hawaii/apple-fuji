#include <Arduino.h>
#include <SoftwareSerial.h>
#include <XBee.h>

#ifndef COMMS_H
#define COMMS_H

extern SoftwareSerial softserial;

void comms_init(void);
void comms_send_payload(void);

#endif
