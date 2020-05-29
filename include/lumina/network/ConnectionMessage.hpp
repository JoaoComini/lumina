#pragma once

#include "Message.hpp"

namespace lumina {
namespace net {

    struct ConnectionMessage : Message
    {
        uint16_t clientId;
    };

} // namespace net
} // namespace lumina
