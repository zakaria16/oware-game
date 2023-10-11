//
// Created by Zakaria on 11/05/2023.
//

#ifndef OWARE_HOUSEITEM_HPP
#define OWARE_HOUSEITEM_HPP
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

#include "GameView.hpp"
#include "model/House.hpp"

class HouseItem : public QGraphicsItem, public oware::House {
    static constexpr auto W = 200;
    static constexpr auto H = 200;
    static constexpr auto SEED_W = 10;
    static constexpr auto SEED_H = 10;
    static constexpr auto ROWS = 6;
    static constexpr auto COLS = 2;

public:
    explicit HouseItem(int position) : House(oware::House::getHoleFromIndex(position)) {}
    HouseItem(int row, int col) : oware::House(row, col){};

    void setSeeds(int val)
    {
        seed = val;
    }

    QRectF boundingRect() const override
    {
        return {static_cast<qreal>(this->getCol() * W), static_cast<qreal>(this->getRow() * H), W, H};
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    [[nodiscard]] oware::House getHouse() const
    {
        return oware::House{this->getRow(), this->getCol()};
    }
    static QMarginsF computeMargin()
    {
        return {0.8 * W, 0.6 * H, 0.8 * W, 0.60 * H};
    }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override
    {
        // seed--;
        qDebug() << "index:" << this->getIndex() << "seed:" << seed;
        this->update(this->boundingRect());
    }

    //    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override
    //    {
    //        qDebug()<<"Hover index:"<<this->getIndex()<<"seed:"<<seed;
    //       bgColor = Qt::red;
    //       this->update(this->boundingRect());
    //    }

private:
    int seed = 4;
};

#endif//OWARE_HOUSEITEM_HPP
