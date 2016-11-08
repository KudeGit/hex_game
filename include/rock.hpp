#ifndef __ROCK_HPP__
#define __ROCK_HPP__
#include <iostream>
#include "color.hpp"

class Rock {
    private:
        Color _color;
    public:
        Rock ();
        explicit Rock (Color color);
        Color color() const;
        void color(Color c);
};


std::ostream& operator<< (std::ostream& out, const Rock& r);

#endif //__ROCK_HPP__
