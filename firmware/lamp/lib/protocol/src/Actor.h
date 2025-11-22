#pragma onne

#include "Command.h"

namespace bikelamp::protocol {
    // Something that will listen to commands and handle them if relevant.
    class AbstractOutput {
        public:
            virtual void handle(bikelamp::protocol::Command command) = 0;
    };
}
