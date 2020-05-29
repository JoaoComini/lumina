#pragma once

#include "Serializable.hpp"

namespace lumina {
namespace engine {

    struct Action : public Serializable {
            virtual ~Action() = default;
            virtual void serialize(Ref<OutputBitStream> &stream) = 0;
            virtual void deserialize(Ref<InputBitStream> &stream) = 0;

            uint8_t type;
    };

} // namespace engine
} // namespace lumina
