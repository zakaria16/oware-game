//
// Created by Zakaria on 14/12/2022.
//

#ifndef OWARE_HOLE_HPP
#define OWARE_HOLE_HPP

#include <cstdint>
#include <ostream>

namespace oware {
    /// A hole class for oware
    /// There are 12 holes in a given oware game
    ///  Arranged in 2 rows and 6 columns
    class Hole {

    public:
        static constexpr uint8_t COL_COUNT = 6;
        static constexpr uint8_t ROW_COUNT = 2;

        Hole() = default;

        /// Create a hole object
        /// \param x the row number
        /// \param y the column number
        Hole(uint8_t x, uint8_t y) : x(x), y(y) {}

        /// Get the index of the hole
        /// \return the index
        [[nodiscard]] uint8_t getIndex() const;

        /// generate a hole from a given index
        /// \param index the index
        /// \return
        static Hole getHoleFromIndex(uint8_t index);

        /// ouput the hole cordinate in string
        /// \param os
        /// \param hole
        /// \return
        friend std::ostream &operator<<(std::ostream &os, const Hole &hole) {
            os << "{" << static_cast<int>(hole.x) << "," << static_cast<int>(hole.y) << "}";
            return os;
        }

        bool operator==(const Hole &rhs) const {
            return x == rhs.x &&
                   y == rhs.y;
        }

        bool operator!=(const Hole &rhs) const {
            return !(rhs == *this);
        }

        [[nodiscard]] bool isValid() const {
            return x >= 0 && y >= 0 && x < ROW_COUNT && y < COL_COUNT;
        }

        [[nodiscard]] uint8_t getX() const {
            return x;
        }

        [[nodiscard]] uint8_t getY() const {
            return y;
        }

        Hole operator++(int) {
            operator++();
            return *this;
        }

        Hole &operator++() {
            const auto nextIndex = getIndex();
            if (nextIndex == 0) {
                x = 1;
                y = 0;
            } else if (nextIndex == (ROW_COUNT * COL_COUNT - 1)) {
                x = 0;
                y = 5;
            } else {
                y = (x == 1) ? y + 1 : y - 1;
            }
            return *this;
        }

    private:
        uint8_t x = -1;
        uint8_t y = -1;
    };
}// namespace oware

#endif//OWARE_HOLE_HPP
