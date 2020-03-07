#include "gtest/gtest.h"
#include "lumina/network/Server.hpp"

using lumina::network::Server;

TEST(ServerTest, CanBuild) {
    Server server = Server::Builder()
        .setChannels(2)
        .setConnections(10)
        .setPort(8883)
        .setTickRate(10)
        .build();

    EXPECT_EQ(server.getChannels(), 2);
    EXPECT_EQ(server.getConnections(), 10);
    EXPECT_EQ(server.getAddress().port, 8883);
    EXPECT_EQ(server.getTickRate(), 10);
}

TEST(ServerTest, CanBuildPointer) {
    Server * server = Server::Builder()
        .setChannels(2)
        .setConnections(10)
        .setPort(12312)
        .setTickRate(10)
        .buildPtr();

    EXPECT_TRUE(server != nullptr);

    EXPECT_EQ(server->getChannels(), 2);
    EXPECT_EQ(server->getConnections(), 10);
    EXPECT_EQ(server->getAddress().port, 12312);
    EXPECT_EQ(server->getTickRate(), 10);

    delete server;
}


