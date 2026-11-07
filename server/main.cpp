#include <iostream>

#include "world.hpp"
#include "networkmanager.hpp"
#include "gameloop.hpp"

int main(){
    World world;
    NetworkManager network;
    gameLoop(world, network);
    return 0;
}