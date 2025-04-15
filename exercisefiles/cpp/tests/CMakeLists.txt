enable_testing()

add_executable(tests tests.cpp)
find_package(GTest REQUIRED)
target_link_libraries(tests GTest::Main)
add_test(NAME tests COMMAND tests)