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

   uint32_t getHost() const;
   uint16_t getPort() const;
   ENetPeer * getPeer() const;

private:
   ENetPeer * peer;
   Address address;
};

}

}