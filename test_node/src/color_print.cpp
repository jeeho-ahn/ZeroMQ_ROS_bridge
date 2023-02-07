#include <color_print.h>

namespace color {
    void print(std::string msg, Code color, Code bg_color)
    {
        color::Modifier c(color);
        color::Modifier d(DEFAULT);
        color::Modifier bg(bg_color);
        color::Modifier bgd(BG_DEFAULT);
        std::cout << c << bg << msg << d << bgd;
    }

    void println(std::string msg, Code color, Code bg_color)
    {
        print(msg, color, bg_color);
        std::cout << std::endl;
    }
}