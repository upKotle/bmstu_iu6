#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addElement);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::removeElement);
    connect(ui->checkButton, &QPushButton::clicked, this, &MainWindow::checkElement);

    updateDisplay();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addElement() {
    QChar element = ui->inputField->text().trimmed().at(0);
    try {
        set.addElement(element);
        updateDisplay();
    } catch (const ElementAlreadyExistsException &e) {
        QMessageBox::warning(this, "Ошибка", e.what());
    }
}

void MainWindow::removeElement() {
    QChar element = ui->inputField->text().trimmed().at(0);
    try {
        set.removeElement(element);
        updateDisplay();
    } catch (const ElementNotFoundException &e) {
        QMessageBox::warning(this, "Ошибка", e.what());
    }
}

void MainWindow::checkElement() {
    QChar element = ui->inputField->text().trimmed().at(0);
    bool exists = set.contains(element);
    QMessageBox::information(this, "Проверка", exists ? "Элемент найден." : "Элемент отсутствует.");
}

void MainWindow::updateDisplay() {
    ui->setDisplay->setText(set.toString());
    ui->sizeLabel->setText(QString("Размер множества: %1").arg(set.getSize()));
}
