cmake_minimum_required(VERSION 3.10)
project(Oware)
set(CMAKE_CXX_STANDARD 17)

option(BUILD_TEST "Build TEST" ON)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
add_executable(oware src/main.cpp
        src/Game.cpp
        src/Oware.cpp
        src/model/House.cpp
        src/model/Player.cpp
        src/interface/OwareAbstractClass.cpp
)

if(BUILD_TEST)
        add_subdirectory(test)
endif()
