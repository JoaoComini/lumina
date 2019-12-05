#include <enet/enet.h>
#include <iostream>
#include <chrono>

class Server
{

public:
    class Builder;

    ~Server();

    void listen();

protected:
    Server(uint16_t port, size_t connections, size_t channels, uint16_t tickRate);

private:    
    ENetAddress address;
    ENetHost *server;
    
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
    
    private:
        uint16_t port = 7777;
        size_t connections = 32;
        size_t channels = 1;
        uint16_t tickRate = 10;
};
