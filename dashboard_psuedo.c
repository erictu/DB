 /*
===============================================================================
 Name        : dashboardP.c
 Author      : Eric Tu & Terence Cho
 Version     : 0.1v
 Copyright   : Copyright (C)
 Description : main Psuodocode
===============================================================================
*/


#include <LPC11xx.h>
#include <can++.h>
#include <uart++.h>
#include "util.h"
#include <mbed.h>
#include "pins.h"
#include "peripherals.h"
#include "ltc680x.h"
#include "pitches.h"
#include "bms_defs.h"
#include "can_id.h"

void setup() {
    configure_CAN();
    configure_PINS(); //in another file with pins
    start polling stuff (Serial);
}

void loop() {
    checkAcceleratorInput;
    checkSteeringWheelInput;
    
    //Steering Wheel Actions
    //LEDS
    if (hazardControl) {
        rightTurnLED();
        leftTurnLED();
    } else if (leftTurn) {
        leftTurnLED();
    } else if (rightTurn) {
        rightTurnLED();
    }
    if (cruiseControl) {
        cruiseControlLED();
    }
    //spareI/O
    //GP101.8

    
    //Accelerator Actions
    if (braking) {
        RegenControl(sendOutput);
    } else if (acclerating) {
        ForwardControl(sendOutput);
    } else if (reversing) {
        ReverseControl(sendOutput);
    }
    
    
    
    
    //ADC
    //AINs
    //spare steering wheel/accelerator
    
    
    //Prints to Display and Debugging
    print("accel: ");
    print("brake: ");
    print("cruise speed: ");
    print("current speed: ");
    print("Cruis On/Off: ");
    print("Driving mode: ");
}