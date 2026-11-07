#pragma once

class World;

class NetworkManager{
    public:
    void broadcastGameState(World& world);
};