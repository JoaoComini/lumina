#pragma once

#include "../Lumina.hpp"
#include "Action.hpp"

namespace lumina {
namespace engine {


    class ActionFactory {
        public:
            virtual ~ActionFactory() = default;
            virtual Ref<Action> create(uint8_t type) = 0;
    };

} // namespace engine
} // namespace lumina
