#pragma once

#include <vector>

#include "../Lumina.hpp"
#include "../network/Client.hpp"
#include "Serializable.hpp"

namespace lumina {
namespace engine {

    class Player
    {
        public:
            Player(uint16_t clientId);
            Ref<Serializable> input;
        private:
            uint16_t Id;
    };

} // namespace engine
} // namespace lumina
