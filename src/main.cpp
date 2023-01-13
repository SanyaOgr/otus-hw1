#include <iostream>
#include "cmake_config.h"

int main()
{
    auto hi = "Hello";

    std::cout << hi << " World " << std::endl;
    std::cout << "Git commit " << GIT_COMMIT_HASH << " " << GIT_BRANCH << std::endl;
    std::cout << "Build " << PROJECT_VERSIO_PATCH << std::endl;

    return 0;
}