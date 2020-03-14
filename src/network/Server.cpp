#include "lumina/network/Server.hpp"

namespace lumina {
namespace net {

    Server::Server(uint16_t connections) : connections(connections){}

    Server::~Server()
    {
        enet_host_destroy(this->host);
        enet_deinitialize();
    }

    void Server::bind(uint16_t port)
    {
        this->address.host = ENET_HOST_ANY;
        this->address.port = port;

        if (enet_initialize () != 0) {
            std::cerr << "An error occurred while trying to initialize ENet server host." << std::endl;
            std::exit(EXIT_FAILURE);
        }

        this->host = enet_host_create(&this->address, this->connections, 2, 0, 0);

        if (this->host ==  NULL) {
            std::cerr << "An error occurred while trying to create an ENet server host." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    void Server::send(Message * message, Client * client)
    {
        // ENetPacket * enetPacket = enet_packet_create (packet->data, packet->length, type);
        // enet_peer_send(packet->destination->getPeer(), type == PacketType::REALIABLE ? 0 : 1, enetPacket);
        enet_host_flush(this->host);
    }

    std::vector<Ref<Message>> Server::poll()
    {
        ENetEvent event;
        std::vector<Ref<Message>> messages;

        while (enet_host_service (this->host, &event, 0) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT: {
                    auto message = makeRef<ConnectionMessage>();

                    Ref<Client> client = makeRef<Client>(event.peer);
                    this->clients[client->getId()] = client;

                    message->type = ServerMessageType::CONNECT;
                    message->clientId = client->getId();

                    messages.push_back(message);
                }
                break;
                case ENET_EVENT_TYPE_RECEIVE: {
                    auto message = makeRef<DataMessage>();

                    Ref<Client> client = makeRef<Client>(event.peer);
                    this->clients[client->getId()] = client;

                    message->type = ServerMessageType::DATA;
                    message->clientId = client->getId();
                    message->data = event.packet->data;
                    message->length = event.packet->dataLength;

                    messages.push_back(message);
                }
                break;
                case ENET_EVENT_TYPE_DISCONNECT: {
                    auto message = makeRef<DisconnectionMessage>();

                    message->type = ServerMessageType::DISCONNECT;
                    message->clientId = event.peer->incomingPeerID;

                    messages.push_back(message);

                    this->clients.erase(event.peer->incomingPeerID);
                }
                break;
            }
        }

        return messages;
    }

    void Server::stop()
    {
        this->listening = false;
    }

    size_t Server::clientCount() const
    {
        return this->clients.size();
    }

}
}
