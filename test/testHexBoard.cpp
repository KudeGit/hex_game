#include <iostream>
#include <stdexcept>


#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "color.hpp"
#include "rock.hpp"
#include "hexboard.hpp"



TEST_GROUP(HEXBOARDTESTGROUP)
{
};

TEST (HEXBOARDTESTGROUP, HexBoardSimple)
{
    HexBoard<5,7> hexboard;
    CHECK(hexboard.X() == 5);
    CHECK(hexboard.Y() == 7);
    for (int i = 0; i < hexboard.X(); ++i) {
        for (int j = 0; j < hexboard.Y(); ++j) {
            CHECK(hexboard.rock(i,j).color() == Color::GREY);
        }
    }
}

TEST (HEXBOARDTESTGROUP, HexBoardCheckPosition)
{
    HexBoard<5,7> hexboard;
    CHECK(hexboard.X() == 5);
    CHECK(hexboard.Y() == 7);
    CHECK(hexboard.valid_position(-1,0) == false);
    CHECK(hexboard.valid_position(1,-1) == false);
    CHECK(hexboard.valid_position(1,-1) == false);
    CHECK(hexboard.valid_position(5,1) == false);
    CHECK(hexboard.valid_position(1,7) == false);
    CHECK(hexboard.valid_position(0,0) == true);

}
TEST (HEXBOARDTESTGROUP, HexBoardAddRock)
{
    HexBoard<5,7> hexboard;
    for (int i = 0; i < hexboard.X(); ++i) {
        for (int j = 0; j < hexboard.Y(); ++j) {
            hexboard.add_rock(i,j, Rock(Color::WHITE));
            CHECK(hexboard.rock(i,j).color() == Color::WHITE);
        }
    }
    hexboard.reset();
    for (int i = 0; i < hexboard.X(); ++i) {
        for (int j = 0; j < hexboard.Y(); ++j) {
            CHECK(hexboard.rock(i,j).color() == Color::GREY);
        }
    }
    //getting an error when throwing exception.... 
}
