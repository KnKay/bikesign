#pragma once 

#include "abstracts.h"
#include "protocol.h"

namespace fakes {
    class fakeOutput: public bikelamp::protocol::AbstractSink {
        public:
            virtual void handle(bikelamp::protocol::Command command){
                switch (command.order)
                {
                case bikelamp::protocol::Order::ON:
                    state = true;
                    break;
                case bikelamp::protocol::Order::OFF:
                    state = false;
                    break;          
                default:
                    break;
                }
            }
    
        bool state = false;
    };
}
