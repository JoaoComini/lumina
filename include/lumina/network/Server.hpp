#include "enet/enet.h"
#include <iostream>
#include <chrono>

namespace lumina {

namespace network {

class Server
{

public:
    class Builder;

    ~Server();

    void listen();
    size_t getChannels() const;
    size_t getConnections() const;
    uint16_t getTickRate() const;
    ENetAddress getAddress() const;

protected:
    Server(uint16_t port, size_t connections, size_t channels, uint16_t tickRate);

private:    
    ENetAddress address;
    ENetHost *host;
    
    size_t connections;
    size_t channels;
    uint16_t tickRate;

    bool listening;
}; 

class Server::Builder
{
    public:
        Builder& setPort(uint16_t port);
        Builder& setConnections(size_t connections);
        Builder& setChannels(size_t channels);
        Builder& setTickRate(uint16_t tickRate);

        Server build() const;
        Server * buildPtr() const;
    
    private:
        uint16_t port = 7777;
        size_t connections = 32;
        size_t channels = 1;
        uint16_t tickRate = 10;
};

}

}
