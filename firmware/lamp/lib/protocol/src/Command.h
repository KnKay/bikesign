#pragma once

#include "enums.h"

namespace bikelamp::protocol
{
    struct Command{
        unsigned char priority;
        bikelamp::protocol::Output output;
        bikelamp::protocol::Input input;
    };
} // namespace bikelamp::protocol
