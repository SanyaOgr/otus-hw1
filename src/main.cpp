#include <iostream>
#include "cmake_config.h"

int main()
{
    auto hi = "Hello";

    std::cout << hi << " World " << GIT_COMMIT_HASH << " " << GIT_BRANCH << std::endl;

    return 0;
}