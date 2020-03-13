#pragma once

#include "Message.hpp"
#include "../network/Client.hpp"

namespace lumina {
namespace net {

    struct DisconnectionMessage : Message
    {
        Ref<Client> client;
    };

} // namespace net
} // namespace lumina
