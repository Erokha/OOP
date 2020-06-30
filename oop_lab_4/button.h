#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <iostream>
#include "constants.h"
#include "enums.h"

class BaseButton: public QPushButton
{
    Q_OBJECT

public:
    virtual ~BaseButton() = 0;
    explicit BaseButton(QWidget *widget = nullptr);

protected:
    buttonStatus status;
};

class DoorsOpeneningButton: public BaseButton
{
   Q_OBJECT
public:
    explicit DoorsOpeneningButton(QWidget *widget = nullptr);
signals:
    void reset();
    void callOpenDoors(selectStatus);
private slots:
    void pressed();
    void released();
};

class DoorsClosingButton: public BaseButton
{
    Q_OBJECT
 public:
     explicit DoorsClosingButton(QWidget *widget = nullptr);
 signals:
     void reset();
     void callCloseDoors(selectStatus);
 private slots:
     void pressed();
     void released();
};


class FloorButton: public BaseButton
{
    Q_OBJECT

public:
    explicit FloorButton(QWidget *widget = nullptr);

    void setFloorNum(std::size_t floor);

signals:
    void reset();
    void requestFloor(std::size_t floor);

private slots:
    void pressed();
    void released();

private:

    std::size_t floor;
};

#endif // BUTTON_H
