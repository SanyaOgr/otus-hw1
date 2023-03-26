#include <gtest/gtest.h>
#include "generated/version.h"

TEST(VersionTests, PatchVersionTest)
{
    ASSERT_GE(PROJECT_VERSION_PATCH, 0);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}