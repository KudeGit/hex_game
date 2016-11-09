#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "color.hpp"



TEST_GROUP(HEXBOARDTESTGROUP)
{
};

TEST (HEXBOARDTESTGROUP, SimpleTest)
{
    auto str = get_color_str(Color::WHITE);
    CHECK(str == "White");
}


