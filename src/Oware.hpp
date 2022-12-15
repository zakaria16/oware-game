#ifndef OWARE_OWARE_HPP
#define OWARE_OWARE_HPP

#include <array>
#include <cstdint>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

#include "Hole.hpp"

namespace oware {

    class Oware {
    public:
        using BoardType = std::array<std::array<uint8_t, 6>, 2>;

        void addSeedsAt(const Hole &hole, const int val) {
            auto &seed = board[hole.getX()][hole.getY()];
            seed += val;
        }

        /// select the seed in a given hole and move them one by clockwise till seeds finish
        /// \param hole the hole to select from and start moving
        /// \return  the vector of holes affected during the move
        std::vector<Hole> move(Hole hole) {
            auto curSeed = getSeedsAt(hole);
            if (curSeed<=0 || !hole.isValid()) { return {}; }

            setSeedsAt(hole, 0);
            std::vector<Hole> affectedHoles;
            for (uint8_t n = 1; n <= curSeed; n++) {
                hole++;
                addSeedsAt(hole, 1);
                affectedHoles.push_back(hole);
            }
            return affectedHoles;
        }

        /// Get the seeds at given hole
        /// \param hole
        /// \return
        uint8_t getSeedsAt(const Hole &hole) {
            return board[hole.getX()][hole.getY()];
        }

        void setSeedsAt(const Hole &hole, const uint8_t val) {
            board[hole.getX()][hole.getY()] = val;
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