#pragma once
#include <cstdint>

enum PacketType : uint8_t {
    WORLD_STATE = 1,
    PLAYER_DATA = 2,
};

class InputRequest{
    int seq;
    bool up, down, left, right;
};

class PlayerData{
    uint8_t type = PLAYER_DATA;
    float x, y;
    float dx, dy;
};

class WorldStateData{
    uint8_t type = WORLD_STATE;
};