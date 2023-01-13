#include "Oware.hpp"
#include <iostream>

#include "Game.hpp"
int main(int argc, char const *argv[]) {

    uint8_t x = 0;
    uint8_t y = 0;

    oware::Game game{std::make_unique<oware::Oware>()};
    game.start("Zak", "Kwaku");

    auto canEnd = false;
    while (!canEnd) {

        oware::Player player = game.whoIsNext();

        std::cout << "Current player: " << player << "\nhole: ";
        std::cin >> x >> y;
        x = x - '0';
        y = y - '0';

        if (game.sow({x, y})) {
            std::cout << "moving pt {" << (int) x << ":" << (int) y << "}\n";
        } else {
            std::cout << player.getName() << " you cant sow: {" << (int) x << ":" << (int) y << "} try again\n";
        }
        std::cout << game.display();

        canEnd = game.canEndGame();
    }

    const auto player = game.checkWinner();

    if(player.getId()==oware::Player::ID::PLAYER_NONE){
        std::cout<<"GAME DRAW\n";
    }
    else {
        std::cout << "Winner: " << player.getName() << ", WON with " << (int) player.getWonSeeds() << " seeds\n";
    }
    return 0;
}
