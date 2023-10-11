//
// Created by Zakaria on 18/02/2023.
//

#ifndef OWARE_MAINWINDOW_HPP
#define OWARE_MAINWINDOW_HPP

#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};

#endif// OWARE_MAINWINDOW_HPP
