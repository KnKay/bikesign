#include <Arduino.h>

#include <timer_blink.h>
#include <discrete_blink.h>

ardulamp::discrete_blink left = ardulamp::discrete_blink(2, bikelamp::protocol::Output::LEFT);
ardulamp::discrete_blink right = ardulamp::discrete_blink(2, bikelamp::protocol::Output::RIGHT);

void setup() {
  // put your setup code here, to run once:
  ardulamp::set_pulse_pin(13);
  ardulamp::setup_timer();  
}

void loop() {
  // put your main code here, to run repeatedly:
}

