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
            case LobbyMessageType::CREATE_ROOM:
                // @TODO: room creation logic
                this->rooms[this->roomIndex]->add(message->clientId);
            break;

            case LobbyMessageType::ENTER_ROOM: {
                // @TODO: room enter logic
                uint8_t roomId = stream->read<uint8_t>();

                this->rooms[roomId]->add(message->clientId);
            }
            break;

            case LobbyMessageType::MATCHMAKING:
                // @TODO: support matchmaking algorithms
                this->rooms[this->roomIndex]->add(message->clientId);
            break;

            case LobbyMessageType::ROOM_INPUT: {
                uint8_t roomId = stream->read<uint8_t>();

                this->rooms[roomId]->receive(stream);
            }
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
