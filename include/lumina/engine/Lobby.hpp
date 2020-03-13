#pragma once

#include <map>

#include "../Lumina.hpp"

#include "../network/ConnectionMessage.hpp"
#include "../network/DataMessage.hpp"
#include "../network/DisconnectionMessage.hpp"

#include "Room.hpp"
#include "Input.hpp"

namespace lumina {
namespace engine {

    enum LobbyInputType
    {
        CREATE_ROOM,
        ENTER_ROOM,
        MATCHMAKING,
        ROOM_INPUT,
    };

    class Lobby
    {
        public:
            Lobby();
            void connect(Ref<net::ConnectionMessage> message);
            void process(Ref<net::DataMessage> message);
            void disconnect(Ref<net::DisconnectionMessage> message);

        private:
            // @TODO: move this to a RoomPool or something like that
            std::map<uint16_t, Ref<Room>> rooms;
            size_t roomIndex = 0;
    };

} // namespace engine
} // namespace lumina
