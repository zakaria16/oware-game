cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
project(Oware)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
add_executable(oware src/main.cpp
        src/Oware.cpp
        src/model/House.cpp
        src/Game.cpp src/model/Player.cpp src/model/Player.hpp src/interface/OwareAbstractClass.cpp)

add_subdirectory(test)
