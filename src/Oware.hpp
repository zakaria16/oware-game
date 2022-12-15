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
        using House = oware::House;

    public:
        using BoardType = std::array<std::array<uint8_t, 6>, 2>;

        void addSeedsAt(const House &house, int val);

        /// select the seed in a given house and sow them one by anti-clockwise till seeds finish
        /// \param house the house to select from and start moving
        /// \return  the vector of holes affected during the sow
        std::vector<House> sow(House house);

        /// Get the seeds at given house
        /// \param house
        /// \return
        uint8_t getSeedsAt(const House &house);

        void setSeedsAt(const House &house, uint8_t val);

        void printBoard() const;


        [[nodiscard]] std::string toString() const;

        BoardType getBoard();

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