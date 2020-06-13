#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include "constants.h"
#include "controller.h"
#include "cabin.h"

class Elevator : public QObject {
    Q_OBJECT

 public:
    explicit Elevator(QObject *parent = nullptr);
    ~Elevator() = default;

    QWidget *GetWidget();

 private:
    Controller controller;
    Cabin cabin;
};


#endif // LIFT_H
