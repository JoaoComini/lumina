#include "lumina/engine/LuminaServer.hpp"

namespace lumina
{
    LuminaServer::LuminaServer(uint16_t port) : net::Server(port, 256)
    {
        this->rooms[roomIndex] = std::make_shared<Room>(5);
    }


    void LuminaServer::onConnect(std::shared_ptr<net::Client> client)
    {
        if (this->rooms[roomIndex]->isFull()) {
            roomIndex += 1;
        }

        this->rooms[roomIndex]->addPlayer(client);
    }

    void LuminaServer::onReceive(net::Packet * packet)
    {

    }

    void LuminaServer::onDisconnect(std::shared_ptr<net::Client> client)
    {

    }
}
