#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "controller.h"
#include "cabin.h"

#include <QWidget>
#include <iostream>
#include <QTextEdit>
#include "button.h"
#include <QLabel>
#include "enums.h"
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QLCDNumber>

class Elevator : public QWidget {
    Q_OBJECT

public:
    explicit Elevator(QWidget *parent = nullptr);
    ~Elevator();
    QWidget *GetWidget();

public slots:
    void info(QString s);
    void buttonInfo(int i);


 private:

    directionStatus direction = NONE;
    Controller controller;
    Cabin cabin;

    DoorsOpeneningButton *doorsToOpenButton;
    DoorsClosingButton *doorsToCloseButton;

    FloorButton **allButtons = nullptr;

    QHBoxLayout LayoutMain;


    QGridLayout buttonLayout;
    QLabel LabelIn;

    QVBoxLayout logLayout;
    QLCDNumber display;
    QTextEdit text;

    void CreateUI();
};


#endif // ELEVATOR_H
