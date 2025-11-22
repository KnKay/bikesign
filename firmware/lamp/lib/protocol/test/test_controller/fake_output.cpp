#include "abstracts.h"
#include "protocol.h"

namespace fakes {
    class fakeOutput: bikelamp::protocol::AbstractSink {
        public:
            virtual void handle(bikelamp::protocol::Command command){
                switch (command.order)
                {
                case bikelamp::protocol::Order::ON:
                    state = true;
                    break;
                case bikelamp::protocol::Order::OFF:
                    state = true;
                    break;          
                default:
                    break;
                }
            }
        private:
            bool state = false;
    };
}
