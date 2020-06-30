#include "elevator.h"

Elevator::Elevator(QWidget *parent) : QWidget(parent) {
    allButtons = new FloorButton*[MAXFLOORS];


    for (size_t i = 0; i < MAXFLOORS; i++)
    {
        allButtons[i] = new FloorButton;
        allButtons[i]->setFloorNum(i);
        allButtons[i]->setFixedSize(BUTTONWIDTH, BUTTONHEIGHT);
        allButtons[i]->setText(QString::number(i+1));
        buttonLayout.addWidget(allButtons[i], (MAXFLOORS - i + 1) / 2, i % 2);
        connect(allButtons[i], &FloorButton::requestFloor, &controller, &Controller::setTarget);
    }

    doorsToOpenButton = new DoorsOpeneningButton;

    connect(doorsToOpenButton, &DoorsOpeneningButton::callOpenDoors , &cabin, &Cabin::staying);


    doorsToCloseButton = new DoorsClosingButton;

    connect(doorsToCloseButton, &DoorsClosingButton::callCloseDoors, &cabin, &Cabin::staying);

    CreateUI();

    connect(&cabin, &Cabin::errorOpening, doorsToOpenButton, &DoorsOpeneningButton::reset);
    connect(&cabin, &Cabin::errorClosing, doorsToCloseButton, &DoorsClosingButton::reset);

    connect(&cabin,  &Cabin::update, &controller, &Controller::updateInfo);
    connect(&controller, &Controller::sendTarget, &cabin,  &Cabin::starting);
    connect(&cabin, &Cabin::logUpdate, this, &Elevator::info);

    connect(&controller, &Controller::floorReached, this, &Elevator::buttonInfo);
    connect(&controller, &Controller::unableToGet, this, &Elevator::buttonInfo);
    connect(&cabin, &Cabin::unableToReach, this, &Elevator::buttonInfo);
}

Elevator::~Elevator() {
    for (int i = 0; i < MAXFLOORS; ++i) {
        delete allButtons[i];
    }

    delete []allButtons;

    delete doorsToOpenButton;
    delete doorsToCloseButton;
}

QWidget *Elevator::GetWidget() {
    return this;
}

void Elevator::CreateUI() {

    setLayout(&LayoutMain);

    display.setMaximumSize(BUTTONWIDTH, BUTTONHEIGHT);
    display.setSegmentStyle(QLCDNumber::Flat);
    display.display(controller.getCurrentFloor() + 1);

    logLayout.addWidget(&display);
    text.setFont(FONT);
    text.setFixedSize(WIDTHINFO, HEIGHTINFO);
    text.setReadOnly(true);
    logLayout.addWidget(&text);


    doorsToCloseButton->setFixedSize(BUTTONWIDTH, BUTTONHEIGHT);
    doorsToCloseButton->setText(QString("><"));
    buttonLayout.addWidget(doorsToCloseButton);

    doorsToOpenButton->setFixedSize(BUTTONWIDTH, BUTTONHEIGHT);
    doorsToOpenButton->setText(QString("<>"));
    buttonLayout.addWidget(doorsToOpenButton);


    LayoutMain.addLayout(&buttonLayout);
    LayoutMain.addLayout(&logLayout);

}

void Elevator::info(QString message) {
    display.display(controller.getCurrentFloor() + 1);
    text.append(message);
}

void Elevator::buttonInfo(int i) {
    allButtons[i]->reset();
}


