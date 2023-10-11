//
// Created by Zakaria on 18/02/2023.
//

#include "MainWindow.hpp"
#include "GameView.hpp"
#include "HouseItem.hpp"
#include <Oware.hpp>
#include <memory>

//class Seed:public QGraphicsItem{
//public:
//    Seed(int row,int col,int seeds):house(row,col),seeds(seeds){}
//    QRectF boundingRect() const override
//    {
//        return QRectF();
//    }
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
//    {
//        painter->setPen(QPen{Qt::blue});
//        painter->drawText(house.getCol()*100,house.getRow()*100,QString::number(seeds));
//    }
//private:
//    int seeds;
//    oware::House house;
//};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->player1Label->setWordWrap(true);
    ui->player2Label->setWordWrap(true);
    connect(ui->graphicsView, &GameView::status, [this](const QString &status) {
        ui->statusbar->showMessage(status);
    });
    connect(ui->graphicsView, &GameView::gameUpdate, [this](const oware::Player &player) {
        constexpr auto PLAYER_STYLE = "background-color: rgb(0, 170, 127);color: rgb(255, 255, 255);";
        std::stringstream ss;
        ss << player;
        switch (player.getId())
        {
            case oware::Player::ID::PLAYER_A:
                ui->player1Label->setText(QString::fromStdString(ss.str()));
                ui->player1Label->setStyleSheet(QString::fromUtf8(PLAYER_STYLE));
                ui->player2Label->setStyleSheet("");
                break;
            case oware::Player::ID::PLAYER_B:
                ui->player2Label->setText(QString::fromStdString(ss.str()));
                ui->player2Label->setStyleSheet(QString::fromUtf8(PLAYER_STYLE));
                ui->player1Label->setStyleSheet("");
                break;
            case oware::Player::ID::PLAYER_NONE:
                ui->player1Label->setText("DRAW");
                ui->player2Label->setText("DRAW");
                ui->player1Label->setStyleSheet("");
                ui->player2Label->setStyleSheet("");
                break;
        }
    });

    ui->graphicsView->setInteractive(true);
    ui->graphicsView->start();

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

MainWindow::~MainWindow() { delete ui; }
