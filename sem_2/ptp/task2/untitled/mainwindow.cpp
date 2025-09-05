#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

Vector2D Vector2D::operator+(const Vector2D &other) const {
    return {x + other.x, y + other.y};
}

Vector2D Vector2D::operator-(const Vector2D &other) const {
    return {x - other.x, y - other.y};
}

Vector2D Vector2D::operator*(double scalar) const {
    return {x * scalar, y * scalar};
}

bool Vector2D::operator==(const Vector2D &other) const {
    return x == other.x && y == other.y;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->sumButton, &QPushButton::clicked, this, &MainWindow::sumVectors);
    connect(ui->subtractButton, &QPushButton::clicked, this, &MainWindow::subtractVectors);
    connect(ui->multiplyButton, &QPushButton::clicked, this, &MainWindow::multiplyByScalar);
    connect(ui->equalButton, &QPushButton::clicked, this, &MainWindow::checkEquality);
}


MainWindow::~MainWindow() {
    delete ui;
}

Vector2D MainWindow::getVector1() const {
    return {ui->x1Edit->text().toDouble(), ui->y1Edit->text().toDouble()};
}

Vector2D MainWindow::getVector2() const {
    return {ui->x2Edit->text().toDouble(), ui->y2Edit->text().toDouble()};
}

void MainWindow::sumVectors() {
    auto v1 = getVector1();
    auto v2 = getVector2();
    auto result = v1 + v2;
    QMessageBox::information(this, "Сумма", QString("(%1, %2)").arg(result.x).arg(result.y));
}

void MainWindow::subtractVectors() {
    auto v1 = getVector1();
    auto v2 = getVector2();
    auto result = v1 - v2;
    QMessageBox::information(this, "Разность", QString("(%1, %2)").arg(result.x).arg(result.y));
}

void MainWindow::multiplyByScalar() {
    auto v1 = getVector1();
    bool ok;
    double scalar = ui->scalarEdit->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Неверный скаляр");
        return;
    }
    auto result = v1 * scalar;
    QMessageBox::information(this, "Произведение", QString("(%1, %2)").arg(result.x).arg(result.y));
}

void MainWindow::checkEquality() {
    auto v1 = getVector1();
    auto v2 = getVector2();
    bool equal = v1 == v2;
    QMessageBox::information(this, "Результат", equal ? "Векторы равны" : "Векторы не равны");
}
