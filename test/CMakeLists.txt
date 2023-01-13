

include_directories(
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
)
find_package(GTest CONFIG REQUIRED)
add_executable(test test.cpp OwareTest.cpp ../src/Oware.cpp ../src/model/House.cpp)
target_link_libraries(test GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)