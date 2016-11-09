
#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "rock.hpp"



TEST_GROUP(HEXBOARDTESTGROUP)
{
};

TEST (HEXBOARDTESTGROUP, RockSimpleTest)
{
    Rock r;
    CHECK(r.color() == Color::GREY);
    r.color(Color::WHITE);
    CHECK(r.color() == Color::WHITE);
    Rock r1(Color::BLACK);
    CHECK(r1.color() == Color::BLACK);
}


