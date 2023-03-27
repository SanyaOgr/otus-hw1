cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Sets PATCH version to GitHub Actions run number if builds on it
if(DEFINED ENV{GITHUB_RUN_NUMBER})
    set(BUILD_NUMBER $ENV{GITHUB_RUN_NUMBER})
else()
    set(BUILD_NUMBER 0)
endif()

# Project with patch version
project(
        hw1
        VERSION 0.0.${BUILD_NUMBER}
)
message(STATUS "Patch Version: ${PROJECT_VERSION_PATCH}")

# Generating version macro with CMake
configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in
        ${CMAKE_CURRENT_SOURCE_DIR}/src/generated/version.h
)

# find_package(...)

# Project targets
add_executable(
        hw1
        src/main.cpp
)
add_executable(
        test_version
        test/test_version.cpp
)

target_include_directories(
        hw1 PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_include_directories(
        test_version PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# target_link_libraries(...)

# Compiler options
if(MSVC)
    target_compile_options(
            hw1 PRIVATE
            /W4
    )
    target_compile_options(
            test_version PRIVATE
            /W4
    )
else()
    target_compile_options(
            hw1 PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
            test_version PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
endif()

# Binaries folder by default: build/<bin|lib>/<build_type>
set_target_properties(
        hw1
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/$<CONFIG>"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/$<CONFIG>"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
)

set_target_properties(
        test_version
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
)

include(CTest)
enable_testing()

add_test(hw1_tests test/test_version)

#install(TARGETS hw1 RUNTIME DESTINATION bin)

#set(CPACK_GENERATOR DEB)

#set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
#set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

#set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

#include(CPack)