#include "lumina/engine/Lobby.hpp"

namespace lumina {
namespace engine {

    Lobby::Lobby()
    {
        // @TODO: implement room management
        this->rooms[this->roomIndex] = makeRef<Room>(256);
    }

    void Lobby::connect(Ref<net::ConnectionMessage> message)
    {
        this->rooms[this->roomIndex]->addPlayer(message->client);
    }

    void Lobby::process(Ref<net::DataMessage> message)
    {
        // @TODO
    }

    void Lobby::disconnect(Ref<net::DisconnectionMessage> message)
    {
        // @TODO
    }

} // namespace engine
} // namespace lumina
