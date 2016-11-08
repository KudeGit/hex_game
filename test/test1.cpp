#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "hex.hpp"


TEST_GROUP(HEXBOARDTESTGROUP)
{
};

TEST (HEXBOARDTESTGROUP, SimpleTest)
{
    HexBoard<5> hexBoard;
    CHECK(0 == 1);
}


