
#include <lumina/engine/LuminaServer.hpp>

int main ()
{
    lumina::LuminaServer * server = new lumina::LuminaServer(7777);

    while (true)
    {
        server->poll();
    }
    

}