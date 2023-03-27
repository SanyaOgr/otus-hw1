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

# Finding dependencies
# find_package(...)

# Sources subdirectory
add_subdirectory(src)

enable_testing()

# Tests subdirectory
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

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

# Output paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

#install(TARGETS hw1 RUNTIME DESTINATION bin)

#set(CPACK_GENERATOR DEB)

#set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
#set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

#set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

#include(CPack)