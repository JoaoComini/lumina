#pragma once

#include "../Lumina.hpp"

#include "../protocol/MessageFactory.hpp"
#include "ConnectionMessage.hpp"
#include "DataMessage.hpp"
#include "DisconnectionMessage.hpp"

namespace lumina {
namespace net {

    enum ServerMessageType : uint8_t
    {
        CONNECT,
        DISCONNECT,
        DATA,
    };

    class ServerMessageFactory : public protocol::MessageFactory
    {
        public:
            Ref<protocol::Message> create(uint8_t type) override;
    };
    
} // namespace net
} // namespace lumina

