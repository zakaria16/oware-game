//
// Created by Zakaria on 25/12/2022.
//
#include "OwareAbstractClass.hpp"
using oware::interface::OwareAbstractClass;

void OwareAbstractClass::printBoard() const {
    std::cout << *this;
}

std::string OwareAbstractClass::toString() const {
    std::stringstream ss;
    ss << std::endl
       << std::endl;
    for (const auto &b: board) {
        for (const uint8_t seeds: b) {
            ss << " | " << (int) seeds;
        }
        ss << " |" << std::endl;
        ss << " -------------------------\n";
    }
    return ss.str();
}

oware::interface::BoardType OwareAbstractClass::getBoard() {
    return board;
}

uint8_t OwareAbstractClass::getSeedsAt(const oware::House &house) {
    return board[house.getX()][house.getY()];
}

void OwareAbstractClass::setSeedsAt(const oware::House &house, const uint8_t val) {
    board[house.getX()][house.getY()] = val;
}