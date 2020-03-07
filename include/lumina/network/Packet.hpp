#pragma once

#include "Client.hpp"

namespace lumina {

namespace network {

struct Packet
{
    std::shared_ptr<Client> source;
    uint8_t * data;
    size_t length;
};


}

}

