cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
project(Oware)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
)
add_executable(oware src/main.cpp src/Oware.cpp src/House.cpp src/House.hpp)

add_subdirectory(test)