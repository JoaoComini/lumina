#pragma once

#include "Message.hpp"
#include "../network/Client.hpp"

namespace lumina {
namespace net {

    struct ConnectionMessage : Message
    {
        uint16_t clientId;
    };

} // namespace net
} // namespace lumina
