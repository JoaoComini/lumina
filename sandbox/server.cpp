#include <lumina/Lumina.hpp>

#include <lumina/network/Server.hpp>
#include <lumina/protocol/Message.hpp>


int main ()
{   
    using namespace lumina;

    net::Server * server = new net::Server(256);

    server->bind(7777);

    std::vector<Ref<protocol::Message>> messages;

    while (true) {
        messages = server->poll();

        if (messages.size() > 0) {
            std::cout
            << "---------------------------------" << std:: endl
            << "Received " << messages.size() << " message(s)." << std::endl
            << "---------------------------------" << std:: endl;
        }
    }

}