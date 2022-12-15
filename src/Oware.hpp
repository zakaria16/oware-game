#ifndef OWARE_OWARE_HPP
#define OWARE_OWARE_HPP

#include <array>
#include <cstdint>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

#include "House.hpp"

namespace oware {

    class Oware {
    public:
        using BoardType = std::array<std::array<uint8_t, 6>, 2>;

        void addSeedsAt(const House &house, const int val) {
            auto &seed = board[house.getX()][house.getY()];
            seed += val;
        }

        /// select the seed in a given house and sow them one by anti-clockwise till seeds finish
        /// \param house the house to select from and start moving
        /// \return  the vector of holes affected during the sow
        std::vector<House> sow(House house) {
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

        /// Get the seeds at given house
        /// \param house
        /// \return
        uint8_t getSeedsAt(const House &house) {
            return board[house.getX()][house.getY()];
        }

        void setSeedsAt(const House &house, const uint8_t val) {
            board[house.getX()][house.getY()] = val;
        }

        void printBoard() const {
            std::cout << *this;
        }


        [[nodiscard]] std::string toString() const {
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

        BoardType getBoard() {
            return board;
        }

        friend std::ostream &operator<<(std::ostream &os, const Oware &oware) {
            os << oware.toString();
            return os;
        }

    private:

        BoardType board = {{{4, 4, 4, 4, 4, 4},
                            {4, 4, 4, 4, 4, 4}}};

    };
}

#endif