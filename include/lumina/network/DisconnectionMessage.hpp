#pragma once

#include "../protocol/Message.hpp"
#include "../network/Client.hpp"

namespace lumina {
namespace net {

    struct DisconnectionMessage : protocol::Message
    {
        Ref<Client> client;
    };

} // namespace net
} // namespace lumina
