#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QMainWindow>
#include "ui_mainwindow.h"
#include "constants.h"
#include "elevator.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    QVBoxLayout *layout;

    Elevator* elevator;
};

#endif // MAINWINDOW_H
