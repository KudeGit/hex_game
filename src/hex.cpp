#include <iostream>
#include "color.hpp"
#include "hex.hpp"
#include "rock.hpp"


int main (void)
{
    Rock r{Color::BLACK};
    HexBoard<5, 5> hexBoard;
    std::cout << r << std::endl;
    std::cout << hexBoard << std::endl;
    hexBoard.reset();
    //HexBoard<5> hexBoard;
    return 0;
}



