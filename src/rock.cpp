#include <iostream>
#include "color.hpp"
#include "rock.hpp"



Rock::Rock():_color(Color::GREY) {}
Rock::Rock(const Color c):_color(c) {}
void Rock::color(Color c)
{
    _color = c;
}
Color Rock::color() const
{
    return _color;
}

std::ostream& operator<< (std::ostream& out, const Rock& r)
{
    out << "r(" << get_color_str(r.color()) << ")";
    return out;
}
