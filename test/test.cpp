#include "generated/version.h"

int main()
{
    if(PROJECT_VERSION_PATCH < 0)
        return -1;

    return 0;        
}