#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
#include <cstdint>

#include "gameloop.hpp"

void gameLoop(World& world, NetworkManager& network) {
  using Clock = std::chrono::steady_clock;
  const double selectedTickRate = 1.0 / 60.0;

  uint32_t currentServerTick = 0; // we increment this every update; 1 tick = 1/60th of a second
  double accumulator = 0.0;

  // If you didn't use auto, we'd use
  // std::chrono::time_point<std::chrono::high_resolution_clock> instead
  auto lastTime = Clock::now(); // timer starts here btw

  while (true) {
    auto currentTime = Clock::now();
    // deltaTime converts the tick values of currentTime - lastTime into a double value in seconds
    std::chrono::duration<double> deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    double frameTime = std::min(deltaTime.count(), 0.25);
    accumulator += frameTime;

    // runs per frame
    while (accumulator >= selectedTickRate) {
      // rest of the logic

      // world.update(world, network, selectedTickRate);

      if (currentServerTick % 2 == 0) {
        // broadcast gamestate to clients
        // runs 30hz instead of 60hz
        // network.broadcastGameState(world);
      }

      //TEST, REMOVE LATER
      if (currentServerTick % 60 == 0){
        std::cout << "tick " << currentServerTick << std::endl;
      }

      accumulator -= selectedTickRate;
      currentServerTick++;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Cool down the CPU
  }
}
