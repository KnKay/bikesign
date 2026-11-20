#include <Arduino.h>

#include <timer_blink.h>
#include <discrete_blink.h>
#include <discrete_input.h>

ardulamp::discrete_blink left = ardulamp::discrete_blink(2, bikelamp::protocol::Output::LEFT);
ardulamp::discrete_blink right = ardulamp::discrete_blink(3, bikelamp::protocol::Output::RIGHT);
ardulamp::discrete_input left_in = ardulamp::discrete_input(4, bikelamp::protocol::Output::LEFT);
ardulamp::discrete_input right_in = ardulamp::discrete_input(5, bikelamp::protocol::Output::RIGHT);

void setup() {
  // put your setup code here, to run once:
  ardulamp::set_pulse_pin(13);
  ardulamp::setup_timer();  
}

void loop() {
  // put your main code here, to run repeatedly:
    bikelamp::protocol::Command command;
    command = left_in.poll();
    left.handle(command);
    delay(1000);
}

