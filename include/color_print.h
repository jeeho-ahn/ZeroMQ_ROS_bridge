#ifndef COLOR_PRINT_H
#define COLOR_PRINT_H

#include <ostream>
#include <string>
#include <iostream>
namespace color {
    enum Code {
        RED = 31,
        GREEN = 32,
        BLUE = 34,
        CYAN = 96,
        YELLOW = 33,
        BLACK = 30,
        MAGENTA = 35,
        HEADER = 95,
        WARNING = 93,
        FAIL = 91,
        LBLUE = 94,
        UNDERLINE = 4,
        BOLD = 1,
        DEFAULT = 39,
        LIGHT_GRAY = 37,
        DARK_GRAY = 90,
        LIGHT_RED = 91,
        LIGHT_GREEN = 92,
        LIGHT_YELLOW = 93,
        LIGHT_BLUE = 94,
        LIGHT_MAGENTA = 95,
        LIGHT_CYAN = 96,
        WHITE = 97,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_YELLOW = 43,
        BG_BLACK = 40,
        BG_BLUE = 44,
        BG_MAGENTA = 45,
        BG_DEFAULT = 49,
        BG_DARK_GRAY = 100,
        BG_LIGHT_RED = 101,
        BG_LIGHT_GREEN = 102,
        BG_LIGHT_YELLOW = 103,
        BG_LIGHT_BLUE = 104,
        BG_LIGHT_CYAN = 106,
        BG_WHITE = 107
    };

    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
            operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };

    void print(std::string msg, Code color, Code bg_color = BG_DEFAULT);
    void println(std::string msg, Code color, Code bg_color = BG_DEFAULT);
}


#endif // COLOR_PRINT_H