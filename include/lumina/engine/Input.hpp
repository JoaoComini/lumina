#pragma once

#include <scratchy/InputBitStream.hpp>

#include "../Lumina.hpp"

namespace lumina {
namespace engine {

    struct Input
    {
        virtual ~Input() = default;

        uint8_t type;

        virtual void deserialize(Ref<InputBitStream> &stream) = 0;
    };

} // namespace engine
} // namespace lumina
