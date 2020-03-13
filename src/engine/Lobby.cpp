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
        // @TODO: send lobby information to player
    }

    void Lobby::process(Ref<net::DataMessage> message)
    {
        Ref<InputBitStream> stream = makeRef<InputBitStream>(message->data, message->length);

        uint8_t type = stream->read<uint8_t>();

        switch (type) {
            case LobbyInputType::CREATE_ROOM:
                // @TODO: room creation logic
                this->rooms[this->roomIndex]->addPlayer(message->client);
            break;

            case LobbyInputType::ENTER_ROOM: {
                // @TODO: room enter logic
                uint8_t room = stream->read<uint8_t>();

                this->rooms[room]->addPlayer(message->client);
            }
            break;

            case LobbyInputType::MATCHMAKING:
                // @TODO: support matchmaking algorithms
                this->rooms[this->roomIndex]->addPlayer(message->client);
            break;

            case LobbyInputType::ROOM_INPUT:
                // @TODO: proxy input to the right room
            break;

            default:
                break;
        }
    }

    void Lobby::disconnect(Ref<net::DisconnectionMessage> message)
    {
        // @TODO
    }

} // namespace engine
} // namespace lumina
