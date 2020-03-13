#include "enet/enet.h"

#include <iostream>
#include <string>

#include <scratchy/InputBitStream.hpp>

int main()
{
    if (enet_initialize () != 0) {
        return EXIT_FAILURE;
    }

    ENetHost * client;

    client = enet_host_create (NULL, 1, 2, 0, 0);

    if (client == NULL) {
        exit (EXIT_FAILURE);
    }

    ENetAddress address;
    ENetEvent event;
    ENetPeer *peer;
    /* Connect to some.server.net:1234. */

    std::string hostAddress;
    uint16_t port;

    std::puts("Enter the server address:");
    getline(std::cin, hostAddress);

    enet_address_set_host (& address, "127.0.0.1");

    std::puts("Enter the server port:");
    std::cin >> port;

    std::cin.ignore();

    address.port = port;
    /* Initiate the connection, allocating the two channels 0 and 1. */
    peer = enet_host_connect (client, &address, 2, 0);

    if (peer == NULL) {
        exit(EXIT_FAILURE);
    }

    /* Wait up to 5 seconds for the connection attempt to succeed. */
    if (enet_host_service (client, & event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
        std::cout << "Connection to " << hostAddress << ":" << port << " made successfully." << std::endl;
    }

    while (enet_host_service (client, & event, 500) > 0) {
        std::cout << "Received from server: " << event.type << std::endl;
        InputBitStream stream = InputBitStream(event.packet->data, event.packet->dataLength);

        std::cout << "Message Type is: " << stream.read<uint16_t>() << std::endl;
        std::cout << "My ID is: " << stream.read<uint16_t>() << std::endl;
        std::cout << "My Room ID is: " << stream.read<uint16_t>() << std::endl;
    }

    std::string buffer;

    while (getline(std::cin, buffer)) {
        ENetPacket * packet = enet_packet_create (buffer.c_str(),
                                          buffer.size(),
                                          ENET_PACKET_FLAG_RELIABLE);

        enet_peer_send(peer, 0, packet);
        enet_host_flush(client);

        std::cout << "Sent: " << buffer << std::endl;


        while (enet_host_service (client, & event, 0) > 0) {
            std::cout << "Received from server: " << event.type << std::endl;
        }
    }
}
