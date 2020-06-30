#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "constants.h"
#include <QWidget>
#include "enums.h"

class Controller: public QWidget
{

    Q_OBJECT

public:
    explicit Controller(QWidget *parent = nullptr);
    int getCurrentFloor();
    ~Controller();
     QWidget *GetWidget();
signals:
    void sendTarget(std::size_t floor, directionStatus dir);
    void floorReached(std::size_t floor);
    void unableToGet(std::size_t floor);

public slots:
    void setTarget(std::size_t floor);
    void updateInfo(std::size_t floor, bool isOk);


private:
    controllerStatus state = READYTOGO;

    int maxFloors = MAXFLOORS;
    int currentFloor = 0;
    directionStatus direction = NONE;


};

#endif // CONTROLLER_H
