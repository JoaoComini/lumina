#include "lumina/engine/Room.hpp"

namespace lumina {
namespace engine {

    Room::Room(size_t capacity): capacity(capacity) { }

    void Room::add(uint16_t clientId)
    {
        if (this->isFull()) {
            return;
        }

        this->players[clientId] = makeRef<Player>(clientId);
    }

    void Room::receive(Ref<InputBitStream> &stream)
    {
        uint16_t clientId = stream->read<uint16_t>();
    }

    bool Room::isFull() const
    {
        return this->capacity == this->players.size();
    }

    std::map<uint16_t, Ref<Player>> Room::getPlayers() const
    {
        return this->players;
    }

} // namespace engine
} // namespace lumina
