#pragma once
#include <vector>

#include "player.hpp"

class NetworkManager;

class World{
    public:
    void update(World& world, NetworkManager& network, double deltaTime);
    private:
    std::vector<Player> players;
};
