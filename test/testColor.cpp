#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"



TEST_GROUP(HEXBOARDTESTGROUP)
{
};

TEST (HEXBOARDTESTGROUP, SimpleTest)
{
    CHECK(0 == 1);
}


