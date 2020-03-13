#pragma once

#include "../protocol/Message.hpp"
#include "../network/Client.hpp"

namespace lumina {
namespace net {
        
    struct ConnectionMessage : protocol::Message 
    {
        Ref<net::Client> client;
    };

} // namespace net
} // namespace lumina
