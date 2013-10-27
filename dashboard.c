 /*
===============================================================================
 Name        : dashboard.c
 Author      : Eric Tu & Terence Cho
 Version     : 0.1v
 Copyright   : Copyright (C)
 Description : main definition
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
    SpiStart();
}

void loop() {

}

static inline void SpiStart() {

}

static inline void SpiEnd() {

}

void ToSpi() {

}

void FromSpi() {

}