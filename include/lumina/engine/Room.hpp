#pragma once

#include <map>
#include <scratchy/scratchy.h>

#include "ActionFactory.hpp"
#include "../Lumina.hpp"
#include "../network/Client.hpp"
#include "../network/ConnectionMessage.hpp"
#include "../network/DisconnectionMessage.hpp"
#include "../network/DataMessage.hpp"


#include "Player.hpp"

namespace lumina {
namespace engine {

    enum RoomMessages : uint8_t {
        INPUT,
        ACTION
    };

    class Room
    {
        public:
            Room(Ref<ActionFactory> actionFactory);

            void connect(Ref<net::ConnectionMessage> message);
            void receive(Ref<net::DataMessage> message);
            void disconnect(Ref<net::DisconnectionMessage> message);

            virtual void onAction(Ref<Action> action, Ref<Player> owner) = 0;
            virtual void update() = 0;
            virtual void start() = 0;

        protected:
            virtual void onPlayerConnect(Ref<Player> player) = 0;
            virtual void onPlayerDisconnect(Ref<Player> player) = 0;

        private:
            size_t capacity;
            std::map<uint16_t, Ref<Player>> players;
            Ref<ActionFactory> actionFactory;
            // physics context
            // game world
    };

} // namespace engine
} // namespace lumina
