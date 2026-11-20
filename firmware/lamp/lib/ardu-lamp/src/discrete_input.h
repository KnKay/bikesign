#pragma once

#include <Arduino.h>
#include <abstracts.h>
namespace ardulamp {
    class discrete_input: public bikelamp::protocol::AbstractInput{
        public:
            discrete_input(int pin, bikelamp::protocol::Output dir){
                in_pin = pin;
                direction = dir;
                pinMode(pin, INPUT);
            }

            bikelamp::protocol::Command poll(){
                bikelamp::protocol::Command command;
                command.input = bikelamp::protocol::Input::HUMAN;
                command.output = direction;
                if (digitalRead(in_pin)){
                    command.order = bikelamp::protocol::Order::ON;
                } else {
                    command.order = bikelamp::protocol::Order::OFF;
                }
                return command;
            }
        protected:
            int in_pin = 0;
            bikelamp::protocol::Output direction = bikelamp::protocol::Output::WARN;
    };
}
