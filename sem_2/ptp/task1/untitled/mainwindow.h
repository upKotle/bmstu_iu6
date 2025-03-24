#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "computermanager.h"
#include "graphwindow.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();
    void on_btnRemove_clicked();
    void on_btnShowAll_clicked();
    void on_btnSave_clicked();
    void on_btnLoad_clicked();
    void on_btnFilter_clicked();
    void showGraph();



private:
    Ui::MainWindow *ui;
    ComputerManager manager;

    void updateTable();
};

#endif // MAINWINDOW_H
