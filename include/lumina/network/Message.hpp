#pragma once

#include <cstdint>

namespace lumina{
namespace net {

    struct Message
    {
        virtual ~Message() = default;

        uint8_t type;
    };

}  // namespace net
} // namespace lumina

