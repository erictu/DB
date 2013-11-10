/* 
* Testing trying to get the lpx1114 to blink it's LED using the mbed library
* might need to change pin names? this was for a different chip/board
*/

#include "mbed.h"

Serial pc (USBTX,USBRX);

DigitalOut ledA(xp11);        //p26);
//DigitalOut ledK(dp28);			  //p24);

int main() {

//    ledK = 0;

    while(1) {
        ledA = 1;
        wait(0.2);
        ledA = 0;
        wait(0.2);
    }
}
 