#pragma once

#include "../Lumina.hpp"
#include "../network/Server.hpp"
#include "../engine/Room.hpp"

namespace lumina {
namespace engine {

    class Application
    {

    public:
        Application(Ref<Room> room);
        void run(int argc, char** argv);

    private:
        Ref<Room> room;
    };

}
}
