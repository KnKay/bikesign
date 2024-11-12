#pragma onne

#include "Command.h"

namespace bikelamp::protocol {
    class Actor {
        public:
            virtual void handle(bikelamp::protocol::Command command) = 0;
        protected: 
            virtual void toggle_left() = 0;
            virtual void toggle_right() = 0;
            virtual void toggle_brake() = 0;
            void toggle_warn() { toggle_left(); toggle_right();};            
    };
}
