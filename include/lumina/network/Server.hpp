#pragma once

#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <atomic>

#include "../Lumina.hpp"
#include "../protocol/Message.hpp"
#include "ServerMessageFactory.hpp"
#include "Client.hpp"

namespace lumina {
namespace net {

    class Server
    {

        public:
            Server(uint16_t connections);
            ~Server();

            void bind(uint16_t port);
            void close();

            std::vector<Ref<protocol::Message>> poll();
            void stop();

            void send(protocol::Message * message, Client * destination);

            size_t clientCount() const;

        protected:
            std::map<uint16_t, Ref<Client>> clients;

        private:
            ENetAddress address;
            ENetHost *host;
            std::atomic<bool> listening;
            uint16_t connections;
            Scope<protocol::MessageFactory> messageFactory;
    };

}
}
