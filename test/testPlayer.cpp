#include <iostream>
#include <stdexcept>


#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "color.hpp"
#include "rock.hpp"
#include "hexboard.hpp"
#include "player.hpp"



TEST_GROUP(HEXBOARDTESTGROUP)
{
};

TEST(HEXBOARDTESTGROUP, PlayerSimpleTest)
{
    HexBoard<5,6> hexboard;
    HumanPlayer<decltype(hexboard)> p(Color::WHITE);
    CHECK(0 == 1);
}
