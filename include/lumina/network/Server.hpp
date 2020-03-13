#pragma once

#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <atomic>

#include "../Lumina.hpp"

#include "ConnectionMessage.hpp"
#include "DataMessage.hpp"
#include "DisconnectionMessage.hpp"

#include "Client.hpp"

namespace lumina {
namespace net {

    enum ServerMessageType : uint8_t
    {
        CONNECT,
        DISCONNECT,
        DATA,
    };

    class Server
    {

        public:
            Server(uint16_t connections);
            ~Server();

            void bind(uint16_t port);
            void close();

            std::vector<Ref<Message>> poll();
            void stop();

            void send(Message * message, Client * destination);

            size_t clientCount() const;

        protected:
            std::map<uint16_t, Ref<Client>> clients;

        private:
            ENetAddress address;
            ENetHost *host;
            std::atomic<bool> listening;
            uint16_t connections;
    };

}
}
