#include "lumina/engine/Room.hpp"

namespace lumina {
namespace engine {

    void Room::connect(Ref<net::ConnectionMessage> message)
    {
        auto player = this->players[message->clientId] = makeRef<Player>(message->clientId);
        this->onPlayerConnect(player);
    }

    void Room::receive(Ref<net::DataMessage> message)
    {
        Ref<InputBitStream> stream = makeRef<InputBitStream>(message->data, message->length);

        switch (stream->read<uint8_t>()) {
            case RoomMessages::INPUT:
                this->players[message->clientId]->input->deserialize(stream);
                break;

            case RoomMessages::ACTION: {
                uint8_t type = stream->read<uint8_t>();
                auto action = this->actionFactory->create(type);

                action->type = type;

                this->onAction(action, this->players[message->clientId]);
            }
                break;
            default:
                throw "Invalid Room message type";
                break;
        }
    }

    void Room::disconnect(Ref<net::DisconnectionMessage> message)
    {
        this->onPlayerDisconnect(this->players[message->clientId]);
        this->players.erase(message->clientId);
    }


} // namespace engine
} // namespace lumina
