cmake_minimum_required(VERSION 3.12)

#Sets PATCH version to GitHub Actions run number 
if(DEFINED ENV{GITHUB_RUN_NUMBER})
    set(BUILD_NUMBER $ENV{GITHUB_RUN_NUMBER})
else()
    set(BUILD_NUMBER 0)
endif()

#Project with patch version
project(hw1 VERSION 0.0.${BUILD_NUMBER})
message(STATUS "Patch Version: ${PROJECT_VERSION_PATCH}")

#Generating version macro with cmake
message(STATUS "Generating version.h")
configure_file(
        ${PROJECT_SOURCE_DIR}/src/version.h.in
        ${PROJECT_SOURCE_DIR}/src/generated/version.h)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(hw1 src/main.cpp)
add_executable(test_version test/test.cpp)

install(TARGETS hw1 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(hw1_tests test_version)