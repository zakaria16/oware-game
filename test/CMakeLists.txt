

include_directories(
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
)
find_package(GTest CONFIG REQUIRED)
message("${GTest_INCLUDEDIR}")
add_executable(test test.cpp OwareTest.cpp ../src/Oware.cpp ../src/Hole.cpp)
target_link_libraries(test GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)