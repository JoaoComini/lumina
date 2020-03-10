#include "lumina/engine/Room.hpp"

namespace lumina
{
    
    Room::Room(size_t capacity): capacity(capacity) { }

    void Room::addPlayer(std::shared_ptr<net::Client> client)
    {
        if (this->isFull()) {
            return;
        }

        this->players.push_back(client);
    }

    bool Room::isFull()
    {
        return this->capacity == this->players.size();
    }

} // namespace lumina
