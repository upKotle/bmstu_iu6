#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "computer.h"
#include "graphwidget.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем кнопку
    QPushButton *btnShowGraph = new QPushButton("Показать график", this);
    btnShowGraph->setObjectName("btnShowGraph");

    // Добавляем кнопку в layout (например, вертикальный layout)
    ui->verticalLayout->addWidget(btnShowGraph); // Замените verticalLayout на ваш layout

    // Соединяем сигнал и слот
    connect(btnShowGraph, &QPushButton::clicked, this, &MainWindow::showGraph);

    updateTable();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateTable() {
    ui->tableComputers->setRowCount(manager.getComputers().size());
    ui->tableComputers->setColumnCount(4);

    // Устанавливаем заголовки столбцов
    ui->tableComputers->setHorizontalHeaderLabels({"CPU", "RAM (GB)", "HDD (GB)", "Price (RUB)"});

    // Заполняем таблицу данными
    int row = 0;
    for (const auto &comp : manager.getComputers()) {
        ui->tableComputers->setItem(row, 0, new QTableWidgetItem(comp.getCpu()));
        ui->tableComputers->setItem(row, 1, new QTableWidgetItem(QString::number(comp.getRam())));
        ui->tableComputers->setItem(row, 2, new QTableWidgetItem(QString::number(comp.getHdd())));
        ui->tableComputers->setItem(row, 3, new QTableWidgetItem(QString::number(comp.getPrice())));
        row++;
    }

    // Растягиваем столбцы по ширине окна
    ui->tableComputers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_btnAdd_clicked() {
    QString cpu = QInputDialog::getText(this, "Добавить компьютер", "Процессор:");
    if (cpu.isEmpty()) return;

    int ram = QInputDialog::getInt(this, "Добавить компьютер", "ОЗУ (GB):", 1, 1, 128);
    int hdd = QInputDialog::getInt(this, "Добавить компьютер", "HDD (GB):", 1, 1, 8192);
    double price = QInputDialog::getDouble(this, "Добавить компьютер", "Цена (RUB):", 0, 0, 1000000, 2);

    manager.addComputer(Computer(cpu, ram, hdd, price));
    updateTable();
}

void MainWindow::on_btnRemove_clicked() {
    int row = ui->tableComputers->currentRow();
    if (row >= 0) {
        manager.removeComputer(row);
        updateTable();
    } else {
        QMessageBox::warning(this, "Удаление", "Выберите строку для удаления!");
    }
}

void MainWindow::on_btnSave_clicked() {
    QString filename = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "CSV файлы (*.csv)");
    if (!filename.isEmpty()) {
        if (manager.saveToFile(filename)) {
            QMessageBox::information(this, "Сохранение", "Данные сохранены!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл!");
        }
    }
}

void MainWindow::on_btnLoad_clicked() {
    QString filename = QFileDialog::getOpenFileName(this, "Открыть файл", "", "CSV файлы (*.csv)");
    if (!filename.isEmpty()) {
        if (manager.loadFromFile(filename)) {
            updateTable();
            QMessageBox::information(this, "Загрузка", "Данные загружены!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось загрузить файл!");
        }
    }
}

void MainWindow::on_btnShowAll_clicked() {
    updateTable();
}

void MainWindow::on_btnFilter_clicked() {
    QString cpuFilter = ui->lineCPU->text();
    double maxPrice = ui->lineMaxPrice->text().toDouble();
    int minRam = ui->spinMinRam->value();
    int minHdd = ui->spinMinHdd->value();

    ui->tableComputers->setRowCount(0);

    int row = 0;
    for (const auto &comp : manager.getComputers()) {
        if ((!cpuFilter.isEmpty() && !comp.getCpu().contains(cpuFilter, Qt::CaseInsensitive)) ||
            (maxPrice > 0 && comp.getPrice() > maxPrice) ||
            (comp.getRam() < minRam) ||
            (comp.getHdd() < minHdd)) {
            continue;
        }

        ui->tableComputers->insertRow(row);
        ui->tableComputers->setItem(row, 0, new QTableWidgetItem(comp.getCpu()));
        ui->tableComputers->setItem(row, 1, new QTableWidgetItem(QString::number(comp.getRam())));
        ui->tableComputers->setItem(row, 2, new QTableWidgetItem(QString::number(comp.getHdd())));
        ui->tableComputers->setItem(row, 3, new QTableWidgetItem(QString::number(comp.getPrice())));
        row++;
    }
}

void MainWindow::showGraph()
{
    // Собираем данные
    QMap<int, QVector<double>> ramGroups;

    for(const auto &comp : manager.getComputers()) {
        ramGroups[comp.getRam()].append(comp.getPrice());
    }

    // Вычисляем средние значения
    QMap<int, double> averages;
    for(auto it = ramGroups.begin(); it != ramGroups.end(); ++it) {
        double sum = std::accumulate(it->begin(), it->end(), 0.0);
        averages[it.key()] = sum / it->size();
    }

    // Создаем и настраиваем окно с графиком
    QDialog *graphDialog = new QDialog(this);
    graphDialog->setWindowTitle("График зависимости цены от ОЗУ");
    graphDialog->resize(800, 600);

    GraphWidget *graphWidget = new GraphWidget(graphDialog);
    graphWidget->setData(averages);

    QVBoxLayout *layout = new QVBoxLayout(graphDialog);
    layout->addWidget(graphWidget);
    graphDialog->setLayout(layout);

    graphDialog->exec();
}




