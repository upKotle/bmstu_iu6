#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "garden.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Garden garden;
    int currentGreenhouseIndex = -1;

private slots:
    void addGreenhouse();
    void addBed();
    void searchCrop();
    void greenhouseSelected(QListWidgetItem *item);
    void updateDisplay();
};

#endif // MAINWINDOW_H
