#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <QMap>
#include <QVector>
#include <numeric>

GraphWindow::GraphWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::GraphWindow), scene(new QGraphicsScene(this)) {
    ui->setupUi(this);

    if (!ui->graphicsView) {
        qDebug() << "ОШИБКА: graphicsView не создан!";
    } else {
        ui->graphicsView->setScene(scene);
        qDebug() << "GraphWindow успешно инициализирован!";
    }
}

GraphWindow::~GraphWindow() {
    delete ui;
}

void GraphWindow::drawGraph(const QList<Computer> &computers) {
    qDebug() << "Функция drawGraph вызвана!";
    if (!scene) {
        qDebug() << "ОШИБКА: scene = nullptr!";
        return;
    }

    scene->clear();

    if (computers.isEmpty()) {
        qDebug() << "Нет данных для построения графика!";
        return;
    }

    QMap<int, QVector<double>> priceMap;
    for (const auto &comp : computers) {
        priceMap[comp.getRam()].append(comp.getPrice());
    }

    if (priceMap.isEmpty()) {
        qDebug() << "Данные не сгруппировались!";
        return;
    }

    QVector<QPointF> points;
    for (auto it = priceMap.begin(); it != priceMap.end(); ++it) {
        int ram = it.key();
        double avgPrice = std::accumulate(it.value().begin(), it.value().end(), 0.0) / it.value().size();
        points.append(QPointF(ram, avgPrice));
    }

    if (points.isEmpty()) {
        qDebug() << "Точек для графика нет!";
        return;
    }

    qDebug() << "Количество точек на графике:" << points.size();

    for (int i = 0; i < points.size() - 1; i++) {
        scene->addLine(points[i].x(), -points[i].y(), points[i + 1].x(), -points[i + 1].y());
    }

    for (const auto &point : points) {
        scene->addEllipse(point.x() - 2, -point.y() - 2, 4, 4, QPen(Qt::red), QBrush(Qt::red));
    }

    this->show();
}

