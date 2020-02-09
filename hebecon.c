#include <avr/io.h>

#include "define_delay.h"

#define OFF  5u;
#define ON_REV 15u;
#define ON_FWD 15u;

void delay_100us(int count) {
    while (count > 0) {
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");
        count--;
    }
}

void delay_10us(int count) {
    while (count > 0) {
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\
        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\


        asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");\

        count--;
    }
}


int main( void ){
    // PIN PB0 and PB1 set as output
    // PIN PB3 and PB4 set as input with pull ups
    DDRB = 0x03u;
    PORTB |= 0x18u;

    // pulse 1.5
    /*
    volatile int loop; 
    volatile int speed=15;
    for(loop=0; loop<20; loop++) {
        PORTB |= 0x03u;
        //delay_100us(15);
        delay_100us((speed-loop)*15/20);
        PORTB &= ~0x03u;
        //delay_100us(185);
        delay_100us((speed+loop)*185/20);
    }
    */

    volatile int i;
    while(1){
        PORTB |= 0x03u;

        delay_100us(14);
        asm("nop");asm("nop");asm("nop");asm("nop");


        if(PINB & 0x10u){
            PORTB &= ~0x01u;
        }

        if(PINB & 0x08u){
            PORTB &= ~0x02u;
        }


        /*
        delay_100us(1);
        delay_10us(1);
        */

        /*
        if(PINB & 0x08u == 0){
            PORTB &= ~0x02u;
        }

        if(PINB & 0x10u == 0){
            PORTB &= ~0x01u;
        }
        */


        //delay_18_4();
        delay_100us(186);
    }
}
