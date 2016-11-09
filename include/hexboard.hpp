#ifndef __HEX_BOARD_HPP__
#define __HEX_BOARD_HPP__

#include <iostream>
#include <array>
#include <stdexcept>
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
        void add_rock (const int x, const int y, const Rock& r) {
            if (valid_position(x,y)) {
                board[x][y] = r;
                return;
            }
            throw std::logic_error("Rock cannot be added to the board");
        }

        friend std::ostream& operator<< <>(std::ostream&, const HexBoard&);

        inline bool valid_position (const size_t x, const size_t y) const {
            return (x >= 0 && x < _N && y >= 0 && y < _M);
        }
        inline int X() const {return _N;}
        inline int Y() const {return _M;}
        const Rock& rock(const int x, const int y) const {
            if (valid_position(x, y)) {
                return board[x][y];
            }
            throw std::logic_error("Position is invalid");
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
