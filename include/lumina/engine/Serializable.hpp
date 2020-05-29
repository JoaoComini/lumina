#pragma once

#include <scratchy/scratchy.h>
#include "../Lumina.hpp"


namespace lumina {
namespace engine {

    struct Serializable
    {
        virtual ~Serializable() = default;
        virtual void serialize(Ref<OutputBitStream> &stream) = 0;
        virtual void deserialize(Ref<InputBitStream> &stream) = 0;
    };

} // namespace net
} // namespace lumina

