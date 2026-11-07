cmake_minimum_required(VERSION 3.25)
project(game_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# first word is the .exe name, rest of the stuff is all the files included
add_executable(server main.cpp gameloop.cpp world.cpp networkmanager.cpp player.cpp)

# inclusion of websockets
find_package(unofficial-uwebsockets CONFIG REQUIRED)
target_link_libraries(server PRIVATE unofficial::uwebsockets::uwebsockets)