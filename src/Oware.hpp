#ifndef OWARE_OWARE_HPP
#define OWARE_OWARE_HPP

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>

#include "interface/OwareInterface.hpp"
#include "model/House.hpp"

namespace oware {

class Oware : public oware::interface::OwareInterface {
    using BoardType = oware::interface::BoardType;

public:
    /// Add the given to a house
    /// \param house the house to add the seed
    /// \param val quantity of seeds to add
    void addSeedsAt(const House &house, int val) override;

    /// select the seed in a given house and sow them one by anti-clockwise till seeds finish
    /// \param house the house to select from and start moving
    /// \return  the vector of holes affected during the sow
    std::vector<House> sow(const House &house) override;

    /// Get the seeds at given house
    /// \param house
    /// \return
    uint8_t getSeedsAt(const House &house) override;

    /// set seeds at a given house
    /// \param house the given house
    /// \param val amount of seeds to set
    void setSeedsAt(const House &house, uint8_t val) override;

    /// Print the board
    void printBoard() const;

    /// get the board in string format
    /// \return string
    [[nodiscard]] std::string toString() const override;

    /// Get the board
    /// \return BoardType
    BoardType getBoard() override;

    /// check whether the affected houses are won
    /// \param playerID the player won played
    /// \param affectedHouses the affected house the sow touches
    /// \return
    std::pair<uint8_t, std::vector<House>> wonSeeds(const Player &player, const std::vector<House> &affectedHouses) override;

    friend std::ostream &operator<<(std::ostream &os, const Oware &oware)
    {
        os << oware.toString();
        return os;
    }

private:
    BoardType board = {{{4, 4, 4, 4, 4, 4},
                        {4, 4, 4, 4, 4, 4}}};
};
}// namespace oware

#endif