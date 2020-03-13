#include "lumina/network/ServerMessageFactory.hpp"


namespace lumina {
namespace net {

    Ref<protocol::Message> ServerMessageFactory::create(uint8_t type)
    {
        switch (type) {
            case ServerMessageType::CONNECT:
                return makeRef<ConnectionMessage>();
                break;

            case ServerMessageType::DATA:
                return makeRef<DataMessage>();
                break;

            default:
                return nullptr;
                break;
        }
    }

} // namespace net
} // namespace lumina
