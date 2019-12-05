#include <lumina/Server.hpp>

Server::Server(
    uint16_t port,
    size_t connections,
    size_t channels,
    uint16_t tickRate):
        connections(connections),
        channels(channels),
        tickRate(tickRate)
{
    this->address.host = ENET_HOST_ANY;
    this->address.port = port;

    this->server = enet_host_create(&address, this->connections, this->channels, 0, 0);

    if (server ==  NULL) {
        std::cerr << "An error occurred while trying to create an ENet server host." << std::endl;

        std::exit(EXIT_FAILURE);
    }
}

Server::~Server()
{
    enet_host_destroy(this->server);
}

void Server::listen()
{
    this->listening = true;

    auto currentTime = std::chrono::high_resolution_clock::now();
    double counter = 0;

    while (this->listening) {

        ENetEvent event;

        auto newTime = std::chrono::high_resolution_clock::now();
        counter = std::chrono::duration_cast<std::chrono::milliseconds>(newTime - currentTime).count();

        while (counter >= 1000/this->tickRate) {
            
            while (enet_host_service (this->server, &event, 0) > 0) {

                switch (event.type) {

                    case ENET_EVENT_TYPE_CONNECT:
                        // TODO: Implement connection logic.
                        break;
                    case ENET_EVENT_TYPE_RECEIVE:
                        // TODO: Use packet factory to deal with packages.                
                        break;
                    
                    case ENET_EVENT_TYPE_DISCONNECT:
                        // TODO: Implement disconnection logic.
                        break;
                }

            }

            counter -= 1000/this->tickRate;
        }

        currentTime = std::chrono::high_resolution_clock::now();
    }
}

Server::Builder& Server::Builder::setPort(uint16_t port)
{
    this->port = port;

    return *this;
}

Server::Builder& Server::Builder::setConnections(size_t connections)
{
    this->connections = connections;
    
    return *this;
}

Server::Builder& Server::Builder::setChannels(size_t channels)
{
    this->channels = channels;

    return *this;
}

Server::Builder& Server::Builder::setTickRate(uint16_t tickRate)
{
    this->tickRate = tickRate;

    return *this;
}

Server Server::Builder::build() const
{
    return Server(
        this->port,
        this->connections,
        this->channels,
        this->tickRate
    );
}