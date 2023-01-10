#define BOOST_TEST_MODULE test
#include <boost/test/unit_test.hpp>
#include "version.h"

BOOST_AUTO_TEST_CASE(test_version)
{
    BOOST_CHECK(version() == 1);
}