#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <iostream>

class Button: public QPushButton
{
    Q_OBJECT
    enum StateOfButtom
    {
        PRESSED,
        RELEASED
    };

public:
    explicit Button(QWidget *widjet = nullptr);
    ~Button() = default;

    void setFloorNum(std::size_t floor);


signals:
    void reset();
    void requestFloor(std::size_t floor);

private slots:
    void pressed();
    void released();

private:
    StateOfButtom state;
    std::size_t floor;
};

#endif // BUTTON_H
