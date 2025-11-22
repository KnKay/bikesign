#pragma once

#include "protocol.h"

namespace bikelamp::protocol {
    // Something that will listen to commands and handle them if relevant.
    class AbstractSink {
        public:
            virtual void handle(bikelamp::protocol::Command command) = 0;
    };
    //Something that is representing an inout. This may trigger on interrupt as well.
    class AbstractInput {
        public: 
            virtual bikelamp::protocol::Command poll() = 0;
            bikelamp::protocol::AbstractSink *sink = 0;
    };
}
