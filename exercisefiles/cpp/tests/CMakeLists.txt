# Use Conan-provided GTest
find_package(GTest REQUIRED)

enable_testing()

add_executable(tests tests.cpp)
target_link_libraries(tests GTest::gtest GTest::gtest_main)
add_test(NAME tests COMMAND tests)