//
// Created by Zakaria on 11/05/2023.
//

#include "HouseItem.hpp"
void HouseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    // auto startp = widget->rect().center();
    QRectF houseRec{static_cast<qreal>(this->getCol() * W), static_cast<qreal>(this->getRow() * H), W, H};

    painter->setBrush(QBrush{Qt::white});
    painter->setPen(QPen{QColor::fromRgb(88, 39, 39), 5});

    painter->drawEllipse(houseRec);

    painter->setPen(QPen{Qt::black, 2});
    painter->setBrush(Qt::black);
    // painter->drawText(houseRec.center(),QString::number(seed));
    const auto startPoint = houseRec.center().toPoint();
    for (auto i = 1; i <= seed; i++)
    {
        const auto x = (i % 2) * SEED_W;
        const auto y = (i / 2) * SEED_H;

        // painter->drawEllipse((startPoint.x()-5)+x,(startPoint.y()-5)+y,8,8);

        painter->drawPixmap((startPoint.x() - 20) + x, (startPoint.y() - 20) + y,
                            QPixmap(QString::fromUtf8(":/images/seed.png")).scaled(SEED_W, SEED_H));
    }
}
