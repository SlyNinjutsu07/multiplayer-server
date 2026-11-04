#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>

void loop() {
  using Clock = std::chrono::high_resolution_clock;
  const double selectedTickRate = 1.0 / 60.0;

  uint32_t currentServerTick =
      0; // we increment this every update; 1 tick = 1/60th of a second
  double accumulator = 0.0;

  // If you didn't use auto, we'd use
  // std::chrono::time_point<std::chrono::high_resolution_clock> instead
  auto lastTime = Clock::now(); // timer starts here btw

  while (true) {
    auto currentTime = Clock::now();
    // deltaTime converts the tick values of currentTime - lastTime into a
    // double value in seconds
    std::chrono::duration<double> deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    accumulator += deltaTime.count();

    // runs per frame
    while (accumulator >= selectedTickRate) {
      // update(selectedTickRate);
      // rest of the logic

      //TODO: Add Clamp
      currentServerTick++;

      if (currentServerTick % 2 == 0) {
        // broadcast gamestate to clients
        // runs 30hz instead of 60hz
      }

      accumulator -= selectedTickRate;
    }

    // render(state);
    std::this_thread::sleep_for(
        std::chrono::milliseconds(1)); // Cool down the CPU
  }
}
