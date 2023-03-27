# Test targets
add_executable(
    test_version
    test_version.cpp
)

target_compile_features(test_version PUBLIC cxx_std_17)

target_include_directories(
    test_version PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(
    test_version PRIVATE
    GTest::gtest
    GTest::gtest_main
)

add_test(test_version test_version)