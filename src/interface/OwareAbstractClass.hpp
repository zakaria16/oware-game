//
// Created by Zakaria on 25/12/2022.
//

#ifndef OWARE_OWAREABSTRACTCLASS_HPP
#define OWARE_OWAREABSTRACTCLASS_HPP
//
// Created by Zakaria on 24/12/2022.
//

#include "Oware.hpp"
#include "model/House.hpp"
#include "model/Player.hpp"
#include <array>
#include <vector>

namespace oware::interface {

    class OwareAbstractClass : public OwareInterface {
    public:
        void addSeedsAt(const House &house, int val) override = 0;

        std::vector<House> sow(const House &house) override = 0;

        uint8_t getSeedsAt(const House &house) override;

        void setSeedsAt(const House &house, uint8_t val) override;

        void printBoard() const override;

        [[nodiscard]] std::string toString() const override;

        BoardType getBoard() override;

        std::pair<uint8_t, std::vector<House>> wonSeeds(const Player &player, const std::vector<House> &affectedHouses) override = 0;

        friend std::ostream &operator<<(std::ostream &os, const OwareInterface &oware) {
            os << oware.toString();
            return os;
        }

        ~OwareAbstractClass() override = default;

    private:
        BoardType board = {{{4, 4, 4, 4, 4, 4},
                            {4, 4, 4, 4, 4, 4}}};
    };
}// namespace oware::interface

#endif//OWARE_OWAREABSTRACTCLASS_HPP
