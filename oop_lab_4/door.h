#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include "constants.h"
#include <QTimer>
#include "enums.h"

class Door : public QObject {
    Q_OBJECT

public:
    explicit Door(QObject *parent = nullptr);
    ~Door() = default;

signals:
    void info(QString message);
    void errorClosing();
    void errorOpening();
    void doorsClosed(selectStatus);
    void doorsOpened();

public slots:
    void opening();
    void closing();

private slots:
    void opened();
    void closed();

private:
    QTimer timeToOpen;
    QTimer timeToClose;
    QTimer timeToWait;
    doorStatus state;
};

#endif // DOOR_H
