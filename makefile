BOARD_TAG    = uno
MONITOR_PORT = /dev/ttyUSB0

include /usr/share/arduino/Arduino.mk
ARDUINO_LIBS = Wire SoftwareSerial SHT1x OneWire DallasTemperature Adafruit_INA219 Adafruit_BMP085 XBee

gui:
	arduino --verify apple-core.ino
