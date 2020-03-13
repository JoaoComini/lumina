#pragma once

#include <memory>

#include "Message.hpp"

namespace lumina {
namespace protocol {

    class MessageFactory
    {
        public:
            virtual ~MessageFactory() = default;
            virtual Ref<Message> create(uint8_t type) = 0;
    };

} // namespace net
} // namespace lumina
