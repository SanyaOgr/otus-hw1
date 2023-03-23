#include <iostream>
#include "generated/version.h"

int main()
{
    auto hi = "Hello";

    std::cout << hi << " World " << std::endl;
    std::cout << "Build " << PROJECT_VERSION_PATCH << std::endl;

    return 0;
}