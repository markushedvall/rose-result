project(rose-result CXX)
cmake_minimum_required(VERSION 3.3)
add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(rose_result_test test/result_test.cpp)

target_link_libraries(rose_result_test ${CONAN_LIBS})
include_directories(include)

enable_testing()
include(GoogleTest)
gtest_add_tests(TARGET rose_result_test)
