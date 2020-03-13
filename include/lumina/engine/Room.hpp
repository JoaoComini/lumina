#pragma once

#include "../Lumina.hpp"
#include "../network/Client.hpp"

#include <vector>

namespace lumina
{ 
    
    class Room
    {       
        public:
            Room(size_t capacity);

            void addPlayer(Ref<net::Client> client);

            bool isFull();

            std::vector<Ref<net::Client>> getPlayers() const;

        private:
            size_t capacity;
            std::vector<Ref<net::Client>> players;
    };

} // namespace lumina
