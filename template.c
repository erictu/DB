//TODO create a template of the code

#include <can++.h>
#include "util.h" //basic utilities
#include <mbed.h> //move mbed utilities to what we're using
#include "ltc680x.h" //specific chip
#include "can.id.h" //filter out everything we don't need, keep things we need
#define LEDpin 5;

void setup() {
	configure_CAN();
	SpiStart();
}

void loop() {
	int sendOverSPI 61;
	int receivedSPI 5;
	SendToSPI(&sendOverSPI, 2); //bc takes in a pointer
	GetFromSpi(&receivedSPI, byte 0xff, 2);
	digitalWrite(LEDpin, receivedSPI); //turn on LED based on what we get from receivedSPI
}

static inline void SpiStart() { //redefine the function inside
	lt_cs.write(0);
}

static inline void SpiEnd() {
	lt_cs.write(1);
}

void SendToSpi(const byte * data, int length) {
        for (int i = 0; i < length; ++i) {
                spi.write(data[i]);
        }
        #ifdef SPI_DEBUG
                Serial.print("SPI: Sent ");
                for (int i = 0; i < length; ++i) {
                        Serial.print(data[i], HEX);
                        Serial.print(", ");
                }
        Serial.println("end of message");
        #endif
}

void GetFromSpi(byte * data, byte info, int length) {
        for (int i = 0; i < length; ++i) {
                data[i] = (byte)(spi.write(info));
        }
        #ifdef SPI_DEBUG
                Serial.print("SPI: With ");
                Serial.print(info, HEX);
                Serial.print(", Got ");
                for (int i = 0; i < length; ++i) {
                        Serial.print(data[i], HEX);
                        Serial.print(", ");
                }
                Serial.println("end of message");
        #endif
}