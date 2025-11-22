#pragma once

#include "protocol.h"
#include "abstracts.h"


namespace bikelamp::protocol
{   
    // The controller will take care on signal handling
    class BasicController: AbstractSink  {
        public:
            // Can be called after startup
            void loop();
            virtual void handle(bikelamp::protocol::Command command);
        private:
            bikelamp::protocol::AbstractSink *turn_left;
            bikelamp::protocol::AbstractSink *turn_right;
            bikelamp::protocol::AbstractSink *lamps;
            bikelamp::protocol::AbstractSink *brake;
    };
}
