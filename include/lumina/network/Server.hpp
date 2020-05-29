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

    enum ServerMessages : uint8_t
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

            void send(void * data, uint32_t length, Ref<Client> destination);
            void send(void * data, uint32_t length, uint16_t clientId);
            void broadcast(void * data, uint32_t length);

            void sendReliable(void * data, uint32_t length, Ref<Client> destination);
            void sendReliable(void * data, uint32_t length, uint16_t clientId);
            void broadcastReliable(void * data, uint32_t length);

            size_t clientCount() const;

        protected:
            std::map<uint16_t, Ref<Client>> clients;
            Ref<Message> handleConnect(ENetEvent event);
            Ref<Message> handleReceive(ENetEvent event);
            Ref<Message> handleDisconnect(ENetEvent event);

        private:
            ENetAddress address;
            ENetHost *host;
            std::atomic<bool> listening;
            uint16_t connections;
    };

}
}
