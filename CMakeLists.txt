cmake_minimum_required(VERSION 3.12)

project(hellow VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})

if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
    execute_process(
        COMMAND git rev-parse --abbrev-ref HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_BRANCH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
        COMMAND git log -1 --format=%h
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_COMMIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
else(EXISTS "${CMAKE_SOURCE_DIR}/.git")
    set(GIT_BRANCH "")
    set(GIT_COMMIT_HASH "")
endif(EXISTS "${CMAKE_SOURCE_DIR}/.git")

message(STATUS "Git current branch: ${GIT_BRANCH}")
message(STATUS "Git commit hash: ${GIT_COMMIT_HASH}")
message(STATUS "Version patch: ${PROJECT_VERSION_PATCH}")

message(STATUS "Generating cmake_config.h")

configure_file(
    ${CMAKE_SOURCE_DIR}/src/cmake_config.h.in
    ${CMAKE_BINARY_DIR}/generated/cmake_config.h
)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_BINARY_DIR}/generated)

add_executable(hellow src/main.cpp)

install(TARGETS hellow)

enable_testing()
add_test(NAME hellow_test COMMAND hellow)