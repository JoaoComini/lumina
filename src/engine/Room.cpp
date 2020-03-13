#include "lumina/engine/Room.hpp"

namespace lumina {
namespace engine {

    Room::Room(size_t capacity): capacity(capacity) { }

    void Room::addPlayer(Ref<net::Client> client)
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

    std::vector<Ref<net::Client>> Room::getPlayers() const
    {
        return this->players;
    }

} // namespace engine
} // namespace lumina
