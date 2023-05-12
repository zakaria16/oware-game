//
// Created by Zakaria on 15/12/2022.
//

#include "Game.hpp"

namespace oware {

Game::Game(std::unique_ptr<OwareInterface> owareGame) : oware(std::move(owareGame)), player1(Player::ID::PLAYER_A), player2(Player::ID::PLAYER_B)
{
}

void Game::start(const std::string &player1Name, const std::string &player2Name)
{
    player1.setName(player1Name);
    player2.setName(player2Name);
    start();
}

void Game::start()
{
    currentPlayer = &player1;
    oware->printBoard();
}

bool Game::sow(const House& house)
{
    if ((uint8_t) currentPlayer->getId() != house.getX())
    {
        return false;
    }
    auto affectedHouse = oware->sow(house);
    if (affectedHouse.empty()) { return false; }
    auto wonList = oware->wonSeeds(*currentPlayer, affectedHouse);
    /// @todo 15/12/2022 use wonList.second to do animation
    currentPlayer->addWonSeeds(wonList.first);
    switchPlayerTurn();
    return true;
}

Player Game::checkWinner()
{
    if (player1.getWonSeeds() == player2.getWonSeeds())
    {
        return Player{Player::ID::PLAYER_NONE, "GAME DRAW"};
    }
    else if (player1.getWonSeeds() > player2.getWonSeeds())
    {
        return player1;
    }
    else
    {
        return player2;
    }
}
Player Game::switchPlayerTurn()
{
    currentPlayer = (*currentPlayer == player1) ? &player2 : &player1;
    return *currentPlayer;
}
bool Game::canEndGame()
{
    return player1.getWonSeeds() > 24 || player2.getWonSeeds() > 24;
}
Player Game::whoIsNext()
{
    return *currentPlayer;
}
std::string Game::display()
{
    return oware->toString();
}

}// namespace oware