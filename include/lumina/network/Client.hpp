#pragma once

#include "enet/enet.h"
#include <memory>

#include "Address.hpp"

namespace lumina {
   
namespace network {

class Client
{

public:
   Client(ENetPeer * peer);

   uint32_t getHost();
   uint16_t getPort();
   ENetPeer * getPeer();

private:
   ENetPeer * peer;
   Address address;
};

}

}