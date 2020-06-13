#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    layout(new QVBoxLayout),
    controller(new Controller) {
    ui->setupUi(this);

    setFixedSize(WINDOWWIDTH, WINDOWHEIGHT);

    ui->centralwidget->setLayout(layout);
    layout->addWidget(controller->GetWidget());
}

MainWindow::~MainWindow() {
    delete ui;
    delete layout;
    delete controller;
}
