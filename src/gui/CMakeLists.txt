cmake_minimum_required(VERSION 3.1)
project(oware-gui)

include_directories(
        ${CMAKE_SOURCE_DIR}/src
)

if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    if (WIN32)
        set(CMAKE_WIN32_EXECUTABLE ON)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
    endif ()
endif ()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS Core Network Widgets REQUIRED)

add_executable(oware-gui main.cpp MainWindow.cpp HouseItem.cpp HouseItem.hpp GameView.cpp GameView.hpp resources.qrc
        ../Oware.cpp
        ../model/House.cpp
        ../Game.cpp ../model/Player.cpp ../model/Player.hpp ../interface/OwareAbstractClass.cpp
        )
target_link_libraries(oware-gui Qt5::Core Qt5::Widgets)
