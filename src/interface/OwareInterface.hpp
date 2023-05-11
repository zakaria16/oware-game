//
// Created by Zakaria on 24/12/2022.
//

#ifndef OWARE_OWAREINTERFACE_HPP
#define OWARE_OWAREINTERFACE_HPP

#include <array>
#include <vector>

#include "model/House.hpp"
#include "model/Player.hpp"

namespace oware::interface {

/// alias for type of Board
using BoardType = std::array<std::array<uint8_t, 6>, 2>;

class OwareInterface {
public:
    virtual void addSeedsAt(const House &house, int val) = 0;

    /// select the seed in a given house and sow them one by anti-clockwise till seeds finish
    /// \param house the house to select from and start moving
    /// \return  the vector of holes affected during the sow
    virtual std::vector<House> sow(const House &house) = 0;

    /// Get the seeds at given house
    /// \param house
    /// \return
    virtual uint8_t getSeedsAt(const House &house) = 0;

    /// set seeds at a given house
    /// \param house the given house
    /// \param val amount of seeds to set
    virtual void setSeedsAt(const House &house, uint8_t val) = 0;

    /// Print the board
    virtual void printBoard() const = 0;

    /// get the board in string format
    /// \return string
    [[nodiscard]] virtual std::string toString() const = 0;

    /// Get the board
    /// \return BoardType
    virtual BoardType getBoard() = 0;

    /// check whether the affected houses are won
    /// \param playerID the player won played
    /// \param affectedHouses the affected house the sow touches
    /// \return
    virtual std::pair<uint8_t, std::vector<House>> wonSeeds(const Player &player, const std::vector<House> &affectedHouses) = 0;

    virtual ~OwareInterface() = default;
};
}// namespace oware::interface

#endif//OWARE_OWAREINTERFACE_HPP
