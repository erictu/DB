 /*
===============================================================================
 Name        : dashboard_h.h
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

	boolean hazard(void) {

	}



	boolean cruise_control(void) {
		static boolean state = false;
  		static boolean prev_reading = HIGH;
  		boolean current_reading = digitalRead(IN_CRUISE_ON); //use digitalin?
  		if (current_reading == prev_reading) {
    		current_reading == HIGH ? state = false : state = true;
  		}
  		prev_reading = current_reading;
  		return state;
	}

	boolean accelerating(void) {

	}

	boolean braking(void) {

	}

	boolean reversing(void) {

	}

	boolean left_turn(void) {

	}

	boolean right_turn(void) {

	}



