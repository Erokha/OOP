#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    layout(new QVBoxLayout),
    elevator(new Elevator) {
    ui->setupUi(this);

    setFixedSize(WINDOWWIDTH, WINDOWHEIGHT);

    ui->centralwidget->setLayout(layout);
    layout->addWidget(elevator->GetWidget());
}

MainWindow::~MainWindow() {
    delete ui;
    delete layout;
    delete elevator;
}
