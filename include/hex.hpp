#ifndef __HEX_HPP__
#define __HEX_HPP__

#include "color.hpp"
#include "hexboard.hpp"
#include "rock.hpp"



//
//template <std::size_t _N, std::size_t _M>
//class Player {
//    private:
//        Color _color;
//        Player();
//    public:
//        explicit Player(Color color):_color(color){}
//        Color color() const {return _color;}
//
//        virtual void add_rock (HexBoard<_N, _M>& hexBoard) = 0;
//};
//
//template <std::size_t _N, std::size_t _M>
//class HumanPlayer : public Player {
//    public:
//        void add_rock (HexBoard<_N, _M>& hexBoard) {
//            auto x, y = 0;
//            do{
//                std::cout << std::endl << "x: ";
//                std::cin >> x;
//                std::cout << std::endl << "y: ";
//                std::cin >> y;
//                std::endl;
//            }while(
//            
//            hexBoard.add_rock(Player::color(), x, y);
//        }
//};
//
//
//
//
//std::ostream& operator<< (std::ostream& out, const Player& p);
//
////template <std::size_t _N, std::size_t _M>
////class HexGame {
////    private:
////        HexBoard<_N, _M> board;
////        std::array<Player, 2> _players;
////    public:
////        HexGame():_players({{Player{Color::WHITE}, Player{Color::BLACK}}}){}
////        bool game_over() {return true;}
////        void play() {}
////        const std::array<Player,2>& players() {return _players;}
////};
////
//
////}
////

#endif //__HEX_HPP__
