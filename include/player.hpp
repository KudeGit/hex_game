#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
#include <iostream>
#include <memory>
#include "color.hpp"
#include "hexBoard.hpp"

template <class Board>
class Player {
    protected:
        Color _color;
        std::shared_ptr<Board> _board_ptr;
        Player();
    public:
        Player(const Color c):_color(c), _board_ptr(nullptr) {}
        Player(const Color c, const std::shared_ptr<Board> board):
            _color(c),_board_ptr(board) {}
        virtual void play() = 0;
};

template <class Board>
class HumanPlayer : Player<Board> {
    using Player<Board>::_color;
    using Player<Board>::_board_ptr;
    public:
        HumanPlayer(const Color c):Player<Board>(c) {}
        HumanPlayer(const Color c, std::shared_ptr<Board> board):Player<Board>(c, board) {}
        virtual void play() {
            auto x = -1, y = -1;
            auto rock = Rock(Color::GREY);
            do {
                do {
                    std::cout << "X: "; std::cin >> x;
                    std::cout << "Y: "; std::cin >> y;
                } while (!_board_ptr->valid_position(x, y));
                rock = _board_ptr->rock(x, y);
            } while(rock.color() == Color::GREY);
            _board_ptr->add_rock(x,y,Rock(_color));
        }
};


#endif //__PLAYER_HPP__
