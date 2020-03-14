#pragma once

#include <map>
#include <scratchy/scratchy.h>

#include "../Lumina.hpp"
#include "../network/Client.hpp"

#include "Player.hpp"

namespace lumina {
namespace engine {

    class Room
    {
        public:
            Room(size_t capacity);

            void add(uint16_t clientId);
            void receive(Ref<InputBitStream> &stream);

            bool isFull() const;
            std::map<uint16_t, Ref<Player>> getPlayers() const;

        private:
            size_t capacity;
            std::map<uint16_t, Ref<Player>> players;
    };

} // namespace engine
} // namespace lumina
