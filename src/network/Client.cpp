#include "lumina/network/Client.hpp"

namespace lumina {
namespace net {

    Client::Client(ENetPeer * peer)
    {
        this->peer = peer;
        this->address.port = this->peer->address.port;
        this->address.host = this->peer->address.host;
    }

    uint32_t Client::getHost() const
    {
        return this->address.host;
    }

    uint16_t Client::getPort() const
    {
        return this->address.port;
    }

    uint16_t Client::getId() const
    {
        return this->peer->incomingPeerID;
    }

    ENetPeer * Client::getPeer() const
    {
        return this->peer;
    }
}
}