//
// Created by Zakaria on 11/05/2023.
//

#ifndef OWARE_GAMEVIEW_HPP
#define OWARE_GAMEVIEW_HPP

#include <memory>
#include <vector>

#include <QGraphicsView>
#include <interface/OwareInterface.hpp>

#include "HouseItem.hpp"
#include "Oware.hpp"

class GameView : public QGraphicsView {
    using Player = oware::Player;

    Q_OBJECT
public:
    using QGraphicsView::QGraphicsView;
    void setOware(std::unique_ptr<oware::interface::OwareInterface> owareGame)
    {
        oware = std::move(owareGame);
    }
    explicit GameView(QWidget *parent = nullptr) : GameView(std::make_unique<oware::Oware>(), parent){};

    explicit GameView(std::unique_ptr<oware::interface::OwareInterface> owareGame = nullptr, QWidget *parent = nullptr);

    void start(const std::string &player1Name, const std::string &player2Name);

    void start();

    bool sow(const oware::House &house);

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

    uint8_t getSeeds(const oware::House &hs)
    {
        return oware->getSeedsAt(hs);
    }

signals:
    void status(const QString &status);
    void gameUpdate(const oware::Player &player1);

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void drawForeground(QPainter *painter, const QRectF &rect) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    /// toggle the player
    /// \return the next player
    Player switchPlayerTurn();
    std::unique_ptr<oware::interface::OwareInterface> oware;
    Player player1{oware::Player::ID::PLAYER_A};
    Player player2{oware::Player::ID::PLAYER_B};
    Player *currentPlayer{&player1};

    std::unique_ptr<QGraphicsScene> scene;
    //    std::vector<std::unique_ptr<HouseItem>> houseItems;
    QGraphicsItemGroup *houseGroup;
};

#endif//OWARE_GAMEVIEW_HPP
