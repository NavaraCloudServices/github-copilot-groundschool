# Use Conan-provided GTest
find_package(GTest REQUIRED)

enable_testing()

add_executable(test tests.cpp)
target_link_libraries(test GTest::gtest GTest::gtest_main)
add_test(NAME test COMMAND tests)