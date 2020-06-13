#include "controller.h"

Controller::Controller(QWidget *parent) :
    QWidget(parent)
{
    allFloors = new bool[maxFloors];
    allButtons = new Button*[maxFloors];;
    layoutGUI();
    //

    for (int i = 0; i < MAXFLOORS; i++)
    //for (int i = MAXFLOORS - 1; i >= 0; i--)
    {
        std::cout << i << std::endl;
        allButtons[i] = new Button;
        allButtons[i]->setFloorNum(i);
        allButtons[i]->setFixedSize(WIDTH, HEIGHT);
        allButtons[i]->setText(QString::number(i + 1));
        LayoutInside.addWidget(allButtons[i], (MAXFLOORS - i - 1) / 2, (MAXFLOORS - i) % 2);
        allFloors[i] = false;
        connect(allButtons[i], &Button::requestFloor, this, &Controller::setTarget);
    }
    connect(&cabin, &Cabin::update, this, &Controller::visit);

    connect(this, &Controller::sendTarget, &cabin,  &Cabin::starting);

    connect(&cabin, &Cabin::info, this, &Controller::showInfo);

}


Controller::~Controller() {
    for (int i = 0; i < MAXFLOORS; ++i) {
        delete allButtons[i];
    }

    delete [] allFloors;
    delete [] allButtons;
}

void Controller::setTarget(std::size_t floor) {
    allFloors[floor] = true;

    if (state == BUSY || currenFloor == floor) {
        int target = getTarget();
        if (target >= 0)
        {
            emit sendTarget(target);
        }
    }
}



void Controller::visit(std::size_t floor, Direction ndirection, bool reached)
{
    if (state == FREE) {
        state = BUSY;
        allFloors[currenFloor] = false;

        emit allButtons[currenFloor]->reset();

        int target = getTarget();

        if (target == -1) {
            if (currenFloor == 0) {
                direction = staying; //
            } else {
                direction = down;
                emit sendTarget(0);
            }
        } else {
            emit sendTarget(target);
        }
    } else {
        currenFloor = floor;
        direction = ndirection;

        if (reached) {
            state = FREE;
        }
    }
}


int Controller::goToNext(int next) {
    int i = currenFloor;
    while(i <= maxFloors)
    {
       i += next;
       if (i <= maxFloors)
       {
           if (allFloors[i])
           {
               return i;
           }
       }
    }
    return -1;
}

int Controller::getTarget() {
    int step = 1;
    if (direction == down)
    {
        step = -1;
    }

    int target = goToNext(step);
    if (target == -1) {
        target = goToNext(-step);
    }

    return target;
}



void Controller::showInfo(QString message) {
    display.display(currenFloor + 1);
    text.append(message);
}

QWidget *Controller::GetWidget() {
    return this;
}


void Controller::layoutGUI()
{

    setLayout(&LayoutMain);

//    LabelIn.setText(CABINSHEADER);
//    LabelIn.setFont(FONT);
//    LabelIn.setFixedSize(WIDTH, HEIGHT);
//    LayoutInside.addWidget(&LabelIn);

    display.setMaximumSize(WIDTH, HEIGHT);
    display.setSegmentStyle(QLCDNumber::Filled);
    display.display(currenFloor + 1);

    LayoutInfo.addWidget(&display);
    text.setFont(FONT);
    text.setFixedSize(WIDTHINFO, HEIGHTINFO);
    text.setReadOnly(true);
    LayoutInfo.addWidget(&text);

    LayoutMain.addLayout(&LayoutOut);
    LayoutMain.addLayout(&LayoutInfo);
    LayoutMain.addLayout(&LayoutInside);
}
