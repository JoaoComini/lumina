#include "lumina/network/Server.hpp"

namespace lumina {
namespace network {

    Server::Server(uint16_t port, uint16_t connections) : connections(connections) {
        this->address.host = ENET_HOST_ANY;
        this->address.port = port;
    }

    Server::~Server()
    {
        enet_host_destroy(this->host);
    }

    void Server::sendUnreliable(std::shared_ptr<Client> client, Packet * packet)
    {
        ENetPacket * enetPacket = enet_packet_create (packet->data, packet->length, ENET_PACKET_FLAG_UNRELIABLE_FRAGMENT);
        enet_peer_send (client->getPeer(), 0, enetPacket);
    }

    void Server::sendReliable(std::shared_ptr<Client> client, Packet * packet)
    {
        ENetPacket * enetPacket = enet_packet_create (packet->data, packet->length, ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send (client->getPeer(), 1, enetPacket);
    }

    void Server::bind()
    {
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

    void Server::listen()
    {
        this->listening = true;

        ENetEvent event;

        while (this->listening) {
            while (enet_host_service (this->host, &event, 0) > 0) {    
                std::cout << "lel" << std::endl;

                switch (event.type) {
                    
                    case ENET_EVENT_TYPE_CONNECT: {
                        std::shared_ptr<Client> client = std::make_shared<Client>(event.peer);

                        auto key = std::make_pair(client->getHost(), client->getPort());

                        this->clients[key] = client;

                        this->onConnect(client);

                        break;
                    }
                    case ENET_EVENT_TYPE_RECEIVE: {
                        Packet * packet = new Packet();

                        packet->data = event.packet->data;
                        packet->length = event.packet->dataLength;
                        packet->source = std::make_shared<Client>(event.peer);

                        this->onReceive(packet);

                        break;
                    }
                    case ENET_EVENT_TYPE_DISCONNECT: {
                        std::shared_ptr<Client> client = std::make_shared<Client>(event.peer);

                        auto key = std::make_pair(client->getHost(), client->getPort());

                        this->clients.erase(key);

                        this->onDisconnect(client);

                        break;
                    }
                }

            }
        }
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