#pragma once

#include <Arduino.h>
#include <abstracts.h>
namespace ardulamp {
    class discrete_blink : public bikelamp::protocol::AbstractSink{
        public: 
            discrete_blink(int pin, bikelamp::protocol::Output lamp){
                comperator = lamp;
                output_pin = pin;
                pinMode(pin, OUTPUT);
            }

            virtual void handle(bikelamp::protocol::Command command){
                // If the message is not for us, we leave
                if (command.output != comperator){
                    return;
                }
                switch (command.order)
                {
                case bikelamp::protocol::Order::ON:
                    digitalWrite(output_pin, LOW);
                    break;
                case bikelamp::protocol::Order::OFF:
                    digitalWrite(output_pin, HIGH);
                    break;
                case bikelamp::protocol::Order::TOGGLE:
                    digitalWrite(output_pin, !digitalRead(output_pin));
                    break;
                default:
                    break;
                }
            }
        protected: 
            bikelamp::protocol::Output comperator = bikelamp::protocol::Output::LEFT;
            int output_pin = 0;
        };
    }