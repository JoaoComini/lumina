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

        this->host->checksum = enet_crc32;
    }

    void Server::send(void * data, uint32_t length, Ref<Client> destination)
    {
        ENetPacket * enetPacket = enet_packet_create (data, length, ENET_PACKET_FLAG_UNRELIABLE_FRAGMENT);
        enet_peer_send(destination->getPeer(), 0, enetPacket);
        enet_host_flush(this->host);
        enet_packet_destroy(enetPacket);
    }

    void Server::send(void * data, uint32_t length, uint16_t destination)
    {
        this->send(data, length, this->clients[destination]);
    }

    void Server::broadcast(void * data, uint32_t length)
    {
        ENetPacket * enetPacket = enet_packet_create (data, length, ENET_PACKET_FLAG_UNRELIABLE_FRAGMENT);
        enet_host_broadcast(this->host, 0, enetPacket);
        enet_host_flush(this->host);
    }

    void Server::sendReliable(void * data, uint32_t length, Ref<Client> client)
    {
        ENetPacket * enetPacket = enet_packet_create (data, length, ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send(client->getPeer(), 1, enetPacket);
        enet_host_flush(this->host);
    }

    void Server::sendReliable(void * data, uint32_t length, uint16_t destination)
    {
        this->sendReliable(data, length, this->clients[destination]);
    }

    void Server::broadcastReliable(void * data, uint32_t length)
    {
        ENetPacket * enetPacket = enet_packet_create (data, length, ENET_PACKET_FLAG_RELIABLE);
        enet_host_broadcast(this->host, 1, enetPacket);
        enet_host_flush(this->host);
    }

    std::vector<Ref<Message>> Server::poll()
    {
        ENetEvent event;
        std::vector<Ref<Message>> messages;

        while (enet_host_service (this->host, &event, 0) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT:
                    messages.push_back(this->handleConnect(event));
                break;
                case ENET_EVENT_TYPE_RECEIVE:
                    messages.push_back(this->handleReceive(event));
                break;
                case ENET_EVENT_TYPE_DISCONNECT:
                    messages.push_back(this->handleDisconnect(event));
                break;
            }
        }

        return messages;
    }

    Ref<Message> Server::handleConnect(ENetEvent event)
    {
        auto message = makeRef<ConnectionMessage>();

        Ref<Client> client = makeRef<Client>(event.peer);
        this->clients[event.peer->incomingPeerID] = client;

        message->type = ServerMessages::CONNECT;
        message->clientId = client->getId();

        return message;
    }

    Ref<Message> Server::handleReceive(ENetEvent event)
    {
        auto message = makeRef<DataMessage>();

        Ref<Client> client = this->clients[event.peer->incomingPeerID];

        message->type = ServerMessages::DATA;
        message->clientId = client->getId();
        message->data = event.packet->data;
        message->length = event.packet->dataLength;

        return message;
    }

    Ref<Message> Server::handleDisconnect(ENetEvent event)
    {
        auto message = makeRef<DisconnectionMessage>();

        message->type = ServerMessages::DISCONNECT;
        message->clientId = event.peer->incomingPeerID;

        this->clients.erase(event.peer->incomingPeerID);

        return message;
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
