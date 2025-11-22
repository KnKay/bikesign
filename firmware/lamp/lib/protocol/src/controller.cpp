#include "controller.h"

void bikelamp::protocol::BasicController::loop(){
    
}

void bikelamp::protocol::BasicController::handle(bikelamp::protocol::Command command){
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

