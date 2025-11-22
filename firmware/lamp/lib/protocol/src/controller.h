#pragma once

#include "protocol.h"
#include "abstracts.h"


namespace bikelamp::protocol
{   
    // The controller will take care on signal handling
    class BasicController: public AbstractSink  {
        public:
            // Can be called after startup
            void loop();
            virtual void handle(bikelamp::protocol::Command command){    
                bikelamp::protocol::AbstractSink *output = 0;
                //Set output;
                switch (command.output)
                {
                case bikelamp::protocol::Output::LEFT:
                    output = turn_left;
                    break;
                case bikelamp::protocol::Output::RIGHT:
                    output = turn_right;
                    break;
                case bikelamp::protocol::Output::LIGHT:
                    output = lamps;
                    break;
                case bikelamp::protocol::Output::BRAKE:
                    output = brake;
                    break;
                default:
                    return;
                }
                output->handle(command);
            }
            bikelamp::protocol::AbstractSink *turn_left;
            bikelamp::protocol::AbstractSink *turn_right;
            bikelamp::protocol::AbstractSink *lamps;
            bikelamp::protocol::AbstractSink *brake;
    };
}
