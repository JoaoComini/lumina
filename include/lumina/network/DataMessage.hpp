#pragma once

#include "Message.hpp"
#include "../network/Client.hpp"

namespace lumina {
namespace net {

    struct DataMessage : Message
    {
        Ref<Client> client;
        void * data;
        size_t length;
    };

} // namespace net
} // namespace lumina
