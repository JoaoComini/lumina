#pragma once

#include <vector>

#include "../Lumina.hpp"
#include "../network/Client.hpp"

namespace lumina {
namespace engine {

    class Player
    {
        public:
            Player(uint16_t clientId);

        private:
            uint16_t clientId;
    };

} // namespace engine
} // namespace lumina
