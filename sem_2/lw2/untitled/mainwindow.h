#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "setcontainer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addElement();
    void removeElement();
    void checkElement();
    void updateDisplay();

private:
    Ui::MainWindow *ui;
    ExtendedSetContainer<QChar> set; // Теперь это поле класса
};

#endif // MAINWINDOW_H
