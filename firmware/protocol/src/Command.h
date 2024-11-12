#pragma once

#include "signals.h"

namespace bikelamp::protocol
{
    struct Command{
        unsigned char priority;
        bikelamp::protocol::Signal signal;
    };
} // namespace bikelamp::protocol
