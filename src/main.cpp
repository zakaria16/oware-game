#include "Oware.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {

    uint8_t x = 0;
    uint8_t y = 0;

    oware::Oware oware;

    while (x < 6) {
        oware.printBoard();
        std::cout << "hole: ";
        std::cin >> x >> y;
        x = x - '0';
        y = y - '0';
        std::cout << "moving pt {" << (int) x << ":" << (int) y << "}\n";
        oware.move({x, y});
    }

    return 0;
}
