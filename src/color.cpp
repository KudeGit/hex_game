#include <iostream>
#include "color.hpp"


static const char *color_str[] = {"Black", "White", "Grey"};
const char* get_color_str (const Color& c)
{
    return color_str[static_cast<typename std::underlying_type<Color>::type>(c)];
}

