#include "lumina/engine/Application.hpp"

namespace lumina {
namespace engine {

    Application::Application(Ref<Room> room) : room(room) {}

    void Application::run(int argc, char** argv)
    {

        uint16_t port = std::stoi(argv[0]);
        uint16_t connections = std::stoi(argv[1]);
        uint8_t tickRate = std::stoi(argv[2]);

        auto server = makeScope<net::Server>(connections);

        server->bind(port);

        while (true) {
            std::vector<Ref<net::Message>> messages = server->poll();

            for (auto &&message : messages) {
                switch (message->type) {
                    case net::ServerMessages::CONNECT:
                        this->room->connect(refCast<net::ConnectionMessage>(message));
                        break;

                    case net::ServerMessages::DATA:
                        this->room->receive(refCast<net::DataMessage>(message));
                        break;

                    case net::ServerMessages::DISCONNECT:
                        this->room->disconnect(refCast<net::DisconnectionMessage>(message));
                        break;

                    default:
                        throw "Invalid Message Type!";
                        break;
                }
            }
        }
    }


}
}
