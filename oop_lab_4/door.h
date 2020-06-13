#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include "constants.h"
#include <QTimer>

class Door : public QObject {
    Q_OBJECT
    enum StateOfDoor {
        OPENING,
        OPENED,
        CLOSING,
        CLOSED
    };
public:
    explicit Door(QObject *parent = nullptr);
    ~Door() = default;

signals:
    void info(QString message);

    void doorsClosed();

public slots:
    void opening();

private slots:
    void opened();
    void closing();
    void closed();

private:
    QTimer timeToOpen;
    QTimer timeToClose;
    QTimer timeToWait;
    StateOfDoor state;
};

#endif // DOOR_H
