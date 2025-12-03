#pragma once

namespace bikelamp::protocol
{
        enum Order {
        ON = 1,
        OFF = 2,
        TOGGLE = 3,
        UP = 10,
        DOWN = 11
    };
    enum Output {
        LEFT = 1,
        RIGHT = 2,
        LIGHT = 3,
        BRAKE = 10,
        WARN = 99
    };
    enum Input {
        HUMAN = 1,
        BIKE = 2,
        EMERGENCY = 99
    };
    struct Command{
        bikelamp::protocol::Order order;
        bikelamp::protocol::Output output;
        bikelamp::protocol::Input input;
    };
} // namespace bikelamp::protocol
