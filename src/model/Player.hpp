//
// Created by Zakaria on 24/12/2022.
//

#ifndef OWARE_PLAYER_HPP
#define OWARE_PLAYER_HPP

#include <cstdint>
#include <ostream>
#include <string>

namespace oware {
    class Player {
    public:
        enum class ID : uint8_t {
            PLAYER_A = 0,
            PLAYER_B = 1,
            PLAYER_NONE =0xff
        };

        explicit Player(ID id) : id(id), name("Player" + std::to_string(toInt())) {}
        Player(ID id, std::string name) : id(id), name(std::move(name)), wonSeeds(0) {}

        [[nodiscard]] ID getId() const {
            return id;
        }
        [[nodiscard]] const std::string &getName() const {
            return name;
        }

        [[nodiscard]] uint8_t getWonSeeds() const {
            return wonSeeds;
        }

        void addWonSeeds(uint8_t val) {
            wonSeeds += val;
        }

        void setWonSeeds(uint8_t val) {
            wonSeeds = val;
        }

        bool operator==(const Player &rhs) const {
            return id == rhs.id;
        }
        bool operator!=(const Player &rhs) const {
            return id != rhs.id;
        }

        bool operator==(const uint8_t idVal) const {
            return toInt() == idVal;
        }
        bool operator!=(const uint8_t idVal) const {
            return toInt() != idVal;
        }

        [[nodiscard]] uint8_t toInt() const { return static_cast<uint8_t>(id); }



        friend std::ostream &operator<<(std::ostream &os, const Player &player) {
            os << "id: " << (int) player.id << " name: " << player.name << " wonSeeds: " << (int) player.wonSeeds;
            return os;
        }

        void setName(const std::string &playerName) {
            name = playerName;
        }

    private:
        ID id;
        std::string name;
        uint8_t wonSeeds{0};
    };
}// namespace oware

#endif//OWARE_PLAYER_HPP
