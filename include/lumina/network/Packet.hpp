#pragma once

#include "Client.hpp"

namespace lumina {
namespace net {

struct Packet
{
    std::shared_ptr<Client> source;
    uint8_t * data;
    size_t length;
};


}
}

