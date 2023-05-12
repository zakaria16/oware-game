//
// Created by Zakaria on 14/12/2022.
//

#ifndef OWARE_HOUSE_HPP
#define OWARE_HOUSE_HPP

#include <cstdint>
#include <ostream>

namespace oware {
/// A hole class for oware
/// There are 12 holes in a given oware game
///  Arranged in 2 rows and 6 columns
class House {

public:
    static constexpr uint8_t COL_COUNT = 6;
    static constexpr uint8_t ROW_COUNT = 2;

    House() = default;

    /// Create a hole object
    /// \param row the row number
    /// \param col the column number
    House(uint8_t row, uint8_t col) : row(row), col(col) {}

    /// Get the index of the hole
    /// \return the index
    [[nodiscard]] uint8_t getIndex() const;

    /// generate a hole from a given index
    /// \param index the index
    /// \return
    static House getHoleFromIndex(uint8_t index);

    /// ouput the hole cordinate in string
    /// \param os
    /// \param hole
    /// \return
    friend std::ostream &operator<<(std::ostream &os, const House &hole)
    {
        os << "{" << static_cast<int>(hole.row) << "," << static_cast<int>(hole.col) << "}";
        return os;
    }

    bool operator==(const House &rhs) const
    {
        return row == rhs.row &&
               col == rhs.col;
    }

    bool operator!=(const House &rhs) const
    {
        return !(rhs == *this);
    }

    [[nodiscard]] bool isValid() const
    {
        return row >= 0 && col >= 0 && row < ROW_COUNT && col < COL_COUNT;
    }

    [[nodiscard]] uint8_t getRow() const
    {
        return row;
    }

    [[nodiscard]] uint8_t getCol() const
    {
        return col;
    }

    House operator++(int)
    {
        operator++();
        return *this;
    }

    House &operator++()
    {
        const auto nextIndex = getIndex();
        if (nextIndex == 0)
        {
            row = 1;
            col = 0;
        }
        else if (nextIndex == (ROW_COUNT * COL_COUNT - 1))
        {
            row = 0;
            col = 5;
        }
        else
        {
            col = (row == 1) ? col + 1 : col - 1;
        }
        return *this;
    }

private:
    uint8_t row = -1;
    uint8_t col = -1;
};
}// namespace oware

#endif//OWARE_HOUSE_HPP
