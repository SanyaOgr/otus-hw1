cmake_minimum_required(VERSION 3.12)

#Sets PATCH version to GitHub Actions run number 
if(DEFINED ENV{GITHUB_RUN_NUMBER})
    set(BUILD_NUMBER $ENV{GITHUB_RUN_NUMBER})
else()
    set(BUILD_NUMBER 0)
endif()

#Project hellow
project(hellow VERSION 0.0.${BUILD_NUMBER})
message(STATUS "Patch Version: ${PROJECT_VERSION_PATCH}")

#Generating version macro with cmake
message(STATUS "Generating cmake_config.h")
configure_file(
    ${CMAKE_SOURCE_DIR}/src/cmake_config.h.in
    ${CMAKE_BINARY_DIR}/generated/cmake_config.h
)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_BINARY_DIR}/generated)

add_executable(hellow src/main.cpp)
add_executable(version_test test/test.cpp)

set_target_properties(hellow
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}
)

#install(TARGETS hellow)

enable_testing()
add_test(hellow_test version_test)