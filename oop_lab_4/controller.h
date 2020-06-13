#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <iostream>
#include <QTextEdit>
#include <QLabel>
#include "constants.h"
#include <button.h>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <cabin.h>


class Controller: public QWidget
{

    Q_OBJECT
    enum StateOfController
    {
        FREE,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller();
     QWidget *GetWidget();
signals:
    void sendTarget(std::size_t floor);

public slots:
    void setTarget(std::size_t floor);
    void showInfo(QString msg);
    void visit(std::size_t floor, Direction direction, bool isOk);

private:
    StateOfController state = BUSY;
    int getTarget();
    int goToNext(int next);

    std::size_t maxFloors = MAXFLOORS;
    int currenFloor = 0;
    Direction direction = staying;

    bool *allFloors = nullptr;
    Button **allButtons = nullptr;

    Cabin cabin;
    QHBoxLayout LayoutMain;

    QVBoxLayout LayoutOut;
    QLabel LabelOut;

    QGridLayout LayoutInside;//QVBoxLayout LayoutInside;
    QLabel LabelIn;

    QVBoxLayout LayoutInfo;
    QLCDNumber display;
    QTextEdit text;

    void layoutGUI();
};

#endif // CONTROLLER_H
