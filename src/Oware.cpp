#include "Oware.hpp"
void oware::Oware::addSeedsAt(const oware::House &house, const int val) {
    auto &seed = board[house.getX()][house.getY()];
    seed += val;
}
std::vector<oware::House> oware::Oware::sow(oware::House house) {
    auto curSeed = getSeedsAt(house);
    if (curSeed<=0 || !house.isValid()) { return {}; }

    setSeedsAt(house, 0);
    std::vector<House> affectedHoles;
    for (uint8_t n = 1; n <= curSeed; n++) {
        house++;
        addSeedsAt(house, 1);
        affectedHoles.push_back(house);
    }
    return affectedHoles;
}
uint8_t oware::Oware::getSeedsAt(const oware::House &house) {
    return board[house.getX()][house.getY()];
}
void oware::Oware::setSeedsAt(const oware::House &house, const uint8_t val) {
    board[house.getX()][house.getY()] = val;
}
void oware::Oware::printBoard() const {
    std::cout << *this;
}
std::string oware::Oware::toString() const {
    std::stringstream ss;
    ss << std::endl << std::endl;
    for (const auto &b: board) {
        for (const uint8_t seeds: b) {
            ss << " | " << (int) seeds;
        }
        ss << " |" << std::endl;
        ss << " -------------------------\n";
    }
    return ss.str();
}
oware::Oware::BoardType oware::Oware::getBoard() {
    return board;
}
