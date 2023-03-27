# Project targets

add_executable(
    hw1
    main.cpp
)

target_compile_features(hw1 PUBLIC cxx_std_17)

# target_link_libraries(...)