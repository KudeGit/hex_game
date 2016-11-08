#ifndef __HEX_BOARD_HPP__
#define __HEX_BOARD_HPP__

#include <iostream>
#include <array>
#include "color.hpp"
#include "rock.hpp"


template <std::size_t _N, std::size_t _M>
class HexBoard;

template <std::size_t _N, std::size_t _M>
std::ostream& operator<< (std::ostream&, const HexBoard<_N, _M>&);



template <std::size_t _N, std::size_t _M>
class HexBoard {
    public:
        void reset();
        HexBoard() {
            reset();
        }
        void add_rock (const int x, const int y, Color& c) {
            if (valid_position(x,y)) {
                if (board[x][y].color() != Color::GREY) {
                    board[x][y].color(c);
                }
            }
        }
        friend std::ostream& operator<< <>(std::ostream&, const HexBoard&);

        inline bool valid_position (const int x, const int y) {
            return (x >= 0 && x <_N && y >= 0 && y <=_M);
        }
    private:
        std::array<std::array<Rock, _M>, _N> board;
};

template <std::size_t _N, std::size_t _M>
std::ostream& operator<< (std::ostream& out, const HexBoard<_N, _M>& hexBoard)
{
    for (auto& rocks: hexBoard.board) {
        for (auto& rock: rocks) {
            out << rock << "; ";
        }
        out << std::endl;
    }
    return out;
}

template <std::size_t _N, std::size_t _M>
void HexBoard<_N,_M>::reset()
{
    for (auto& rocks: board) {
        for (auto& rock: rocks) {
            rock.color(Color::GREY);
        }
    }
}


#endif
