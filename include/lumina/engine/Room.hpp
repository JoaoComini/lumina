#pragma once

#include "../network/Client.hpp"

#include <vector>

namespace lumina
{ 
    
    class Room
    {       
        public:
            Room(size_t capacity);

            void addPlayer(std::shared_ptr<net::Client> client);

            bool isFull();

        private:
            size_t capacity;
            std::vector<std::shared_ptr<net::Client>> players;
    };

} // namespace lumina
