#include <lumina/Lumina.hpp>

#include <lumina/network/Server.hpp>

#include <lumina/engine/Lobby.hpp>
#include <lumina/protocol/Message.hpp>


int main ()
{   
    using namespace lumina;

    net::Server * server = new net::Server(256);
    engine::Lobby * lobby = new engine::Lobby();

    server->bind(7777);

    std::vector<Ref<protocol::Message>> messages;

    while (true) {
        messages = server->poll();
        
        for (auto &&message : messages) {
            switch (message->type) {
                case net::ServerMessageType::CONNECT:
                    lobby->connect(refCast<net::ConnectionMessage>(message));
                    break;
                
                case net::ServerMessageType::DATA:
                    lobby->process(refCast<net::DataMessage>(message));
                    break;
                
                case net::ServerMessageType::DISCONNECT:
                    lobby->disconnect(refCast<net::DisconnectionMessage>(message));
                default:
                    throw "Invalid Message Type!";
                    break;
            }
        }    
    }

}