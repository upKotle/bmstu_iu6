#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include "computermanager.h"

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog {
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

    void drawGraph(const QVector<Computer> &computers);

private:
    Ui::GraphWindow *ui;
    QGraphicsScene *scene;
};

#endif // GRAPHWINDOW_H
