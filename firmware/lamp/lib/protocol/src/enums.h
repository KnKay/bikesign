#pragma once
namespace bikelamp::protocol
{
    enum Output {
        LEFT = 1,
        RIGHT = 2,
        BRAKE = 10,
        WARN = 99
    };
    enum Input {
        HUMAN = 1,
        BIKE = 2,
        EMERGENCY = 99
    };
} // namespace bikelamd::protocol
