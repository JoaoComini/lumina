#pragma once

#include "../network/Server.hpp"

#include "Room.hpp"

namespace lumina {

    class LuminaServer : network::Server
    {

    public:
        LuminaServer(uint16_t port);


    protected:
        void onReceive (network::Packet * packet) override;
        void onConnect(std::shared_ptr<network::Client> client) override;
        void onDisconnect(std::shared_ptr<network::Client> client) override;

    private:        
        size_t roomIndex = 0;
        std::map<size_t, std::shared_ptr<Room>> rooms;
    };

}