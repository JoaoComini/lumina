#include "lumina/network/Client.hpp"


namespace lumina {
namespace network {

    Client::Client(ENetPeer * peer)
    {
        this->peer = peer;
        this->address.port = this->peer->address.port;
        this->address.host = this->peer->address.host;
    }

    uint32_t Client::getHost()
    {
        return this->address.host;
    }

    uint16_t Client::getPort()
    {
        return this->address.port;
    }
}
}