#include <iostream>
#include "cmake_config.h"

int main()
{
    auto hi = "Hello";

    std::cout << hi << " World " << PROJECT_VERSION_PATCH << std::endl;

    return 0;
}