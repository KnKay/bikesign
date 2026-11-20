#pragma once

#include <Arduino.h>
// Configure the timer interrupt that will drive the blink frequence. 
// The interrupt will not be stopped at any time but give a permanent blink frequence. 
// Some helps here https://forum.arduino.cc/t/trying-to-get-started-with-timer-interrupts/1049208

namespace ardulamp {
    int PULSE_PIN = 13;
    int PULSE_CONTER =     15624;

    void set_pulse_pin(int pin){
        PULSE_PIN = pin;
        pinMode(PULSE_PIN, OUTPUT);
    }

    void setup_timer(){
        // Mostly based on this: https://www.visualmicro.com/page/Timer-Interrupts-Explained.aspx
        noInterrupts();           // disable all interrupts
        TCCR1A = 0;
	    TCCR1B = 0;

        TCNT1 = PULSE_CONTER;   // preload timer
        TCCR1B |= (1 << CS12);    // 256 prescaler 
        TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
	    interrupts();             // enable all interrupts
    }
}

// We toggle our frequency pin on interrupt.
ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
	TCNT1 = ardulamp::PULSE_CONTER;   // preload timer
    digitalWrite(ardulamp::PULSE_PIN, !digitalRead(ardulamp::PULSE_PIN));
}
