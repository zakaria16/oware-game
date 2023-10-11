//
// Created by Zakaria on 11/05/2023.
//

#include <QMouseEvent>

#include "GameView.hpp"
#include "HouseItem.hpp"

using oware::House;
using oware::Player;
constexpr auto W = 100;
constexpr auto H = 100;
constexpr auto ROWS = 6;
constexpr auto COLS = 2;
GameView::GameView(std::unique_ptr<oware::interface::OwareInterface> owareGame, QWidget *parent)
    : oware(std::move(owareGame)), player1(Player::ID::PLAYER_A),
      player2(Player::ID::PLAYER_B), scene(std::make_unique<QGraphicsScene>())
{

    QList<QGraphicsItem *> hs;
    for (auto i = 0; i < 12; i++)
    {
        //  houseItems.push_back(std::make_unique<HouseItem>(i));
        // scene->addItem();
        hs.push_back(new HouseItem{i});
    }

    houseGroup = scene->createItemGroup(hs);
    //    const auto rect =houseGroup->boundingRect().marginsAdded(QMarginsF(10,10,10,10));
    //    scene->addRect(rect);
    //    auto elp = new QGraphicsEllipseItem(rect.top()-100,rect.topLeft().y()-100,100,100);
    //
    //    scene->addItem(elp);
}

void GameView::start(const std::string &player1Name, const std::string &player2Name)
{
    player1.setName(player1Name);
    player2.setName(player2Name);
    start();
}

void GameView::start()
{
    currentPlayer = &player1;
    this->setScene(scene.get());
    std::stringstream ss;
    ss << player1;
    status(QString("Current player: %1").arg(QString::fromStdString(ss.str())));
}

bool GameView::sow(const oware::House &house)
{
    if ((uint8_t) currentPlayer->getId() != house.getRow())
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

Player GameView::checkWinner()
{
    if (player1.getWonSeeds() == player2.getWonSeeds())
    {
        return Player{Player::ID::PLAYER_NONE, "GameView DRAW"};
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

Player GameView::switchPlayerTurn()
{
    currentPlayer = (*currentPlayer == player1) ? &player2 : &player1;
    return *currentPlayer;
}
bool GameView::canEndGame()
{
    return player1.getWonSeeds() >= 24 || player2.getWonSeeds() >= 24;
}
Player GameView::whoIsNext()
{
    return *currentPlayer;
}
std::string GameView::display()
{
    return oware->toString();
}

void GameView::paintEvent(QPaintEvent *event)
{
    QGraphicsView::paintEvent(event);

    for (const auto &item: houseGroup->childItems())
    {
        auto *it = (HouseItem *) item;
        it->setSeeds(oware->getSeedsAt(it->getHouse()));
        it->update(it->boundingRect());
    }
}

void GameView::mousePressEvent(QMouseEvent *event)
{
    auto *it = (HouseItem *) itemAt(event->pos());
    if (it)
    {
        if (canEndGame())
        {
            const auto player = checkWinner();

            if (player.getId() == oware::Player::ID::PLAYER_NONE)
            {
                status("GAME DRAW");
            }
            else
            {
                status(QString("Winner: %1, WON with %2 seeds").arg(QString::fromStdString(player.getName()), QString::number(player.getWonSeeds())));
            }
            return;
        }
        sow(it->getHouse());
        update();
        oware::Player player = whoIsNext();
        std::stringstream ss;
        ss << player;
        status(QString("Current player: %1").arg(QString::fromStdString(ss.str())));
        gameUpdate(player);
    }
}

void GameView::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->setPen(QPen(Qt::black, 8));
    painter->setBrush(Qt::BrushStyle::Dense3Pattern);
    painter->drawEllipse(houseGroup->boundingRect().marginsAdded(HouseItem::computeMargin()));
}

void GameView::drawForeground(QPainter *painter, const QRectF &rect)
{
    QGraphicsView::drawForeground(painter, rect);
}
