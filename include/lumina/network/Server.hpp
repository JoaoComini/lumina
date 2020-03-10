#pragma once

#include <iostream>
#include <functional>
#include <map>
#include <atomic>

#include "lumina/network/Packet.hpp"


namespace lumina {
namespace net {

class Server
{

public:
    Server(uint16_t port, uint16_t connections);
    ~Server();

    void bind();
    void close();
    
    void poll();
    void stop();

    void sendUnreliable(std::shared_ptr<Client> destination, Packet * packet);
    void sendReliable(std::shared_ptr<Client> destination, Packet * packet);
    size_t clientCount() const;

protected:
    virtual void onReceive(Packet * packet) = 0;
    virtual void onConnect(std::shared_ptr<Client> client) = 0;
    virtual void onDisconnect(std::shared_ptr<Client> client) = 0;

    std::map<std::pair<uint32_t, uint16_t>, std::shared_ptr<Client>> clients;

private:    
    ENetAddress address;
    ENetHost *host;
    std::atomic<bool> listening;
    uint16_t connections;
}; 

}
}
