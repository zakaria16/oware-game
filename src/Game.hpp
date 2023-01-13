//
// Created by Zakaria on 15/12/2022.
//

#ifndef OWARE_GAME_HPP
#define OWARE_GAME_HPP

#include <memory>
#include <ostream>
#include <string>
#include <utility>

#include "Oware.hpp"

namespace oware {

    class Game {
        using OwareInterface = interface::OwareInterface;

    public:
        explicit Game(std::unique_ptr<OwareInterface> owareGame);

        void start(const std::string &player1Name, const std::string &player2Name);

        void start();

        bool sow(House house);

        /// check the winner of the Game
        ///
        /// A player has won he has more than half of the total seeds
        /// which is 24
        /// \return the player who has won
        Player checkWinner();

        /// can the game be stopped
        /// A game can be stopped if a player has more than 24 seeds
        /// \return true if it can be stop, false otherwise
        bool canEndGame();

        /// whic player is next to play
        /// \return the player
        Player whoIsNext();

        /// Display the board
        /// \return the string representation of the board
        std::string display();

    private:
        /// toggle the player
        /// \return the next player
        Player switchPlayerTurn();
        std::unique_ptr<OwareInterface> oware;
        Player player1;
        Player player2;
        Player *currentPlayer{&player1};
    };

}// namespace oware

#endif//OWARE_GAME_HPP
