#include "comms.h"

SoftwareSerial softserial(2,3);
XBee xbee = XBee();

// SoftwareSerial softserial(2,3);
void comms_init(void)
{
    xbee.setSerial(softserial);
    softserial.begin(9600);
}

void comms_send_payload(uint8_t* payload, int len)
{

    // Specify the address of the remote XBee (this is the SH + SL)
    XBeeAddress64 addr64 = XBeeAddress64(0, 0);

    // Create a TX Request
    ZBTxRequest zbTx = ZBTxRequest(addr64, payload, len);

    // Send your request
    xbee.send(zbTx);

}

void comms_send_test(void)
{
    // Create an array for holding the data you want to send.
    uint8_t payload[]= {'h', 'e', 'l', 'l', '4'};

    // Specify the address of the remote XBee (this is the SH + SL)
    XBeeAddress64 addr64 = XBeeAddress64(0, 0);

    // Create a TX Request
    ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));

    // Send your request
    xbee.send(zbTx);
}
