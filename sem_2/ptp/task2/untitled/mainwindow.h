#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Vector2D {
    double x;
    double y;

    Vector2D operator+(const Vector2D &other) const;
    Vector2D operator-(const Vector2D &other) const;
    Vector2D operator*(double scalar) const;
    bool operator==(const Vector2D &other) const;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sumVectors();
    void subtractVectors();
    void multiplyByScalar();
    void checkEquality();

private:
    Ui::MainWindow *ui;
    Vector2D getVector1() const;
    Vector2D getVector2() const;
};

#endif // MAINWINDOW_H
