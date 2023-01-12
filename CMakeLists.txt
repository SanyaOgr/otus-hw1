cmake_minimum_required(VERSION 3.12)

project(hellow)

add_executable(hellow src/main.cpp)

install(TARGETS hellow)

enable_testing()
add_test(NAME hellow_test COMMAND hellow)