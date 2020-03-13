#pragma once

#include "Message.hpp"
#include "../network/Client.hpp"

namespace lumina {
namespace net {

    struct ConnectionMessage : Message
    {
        Ref<net::Client> client;
    };

} // namespace net
} // namespace lumina
