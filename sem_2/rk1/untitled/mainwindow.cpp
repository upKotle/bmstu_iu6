#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addGreenhouseBtn, &QPushButton::clicked, this, &MainWindow::addGreenhouse);
    connect(ui->addBedBtn, &QPushButton::clicked, this, &MainWindow::addBed);
    connect(ui->searchBtn, &QPushButton::clicked, this, &MainWindow::searchCrop);
    connect(ui->greenhouseList, &QListWidget::itemClicked, this, &MainWindow::greenhouseSelected);

    updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::greenhouseSelected(QListWidgetItem *item)
{
    Q_UNUSED(item);
    currentGreenhouseIndex = ui->greenhouseList->currentRow();
    updateDisplay();
}

void MainWindow::addGreenhouse()
{
    try {
        garden.addGreenhouse(Greenhouse());
        currentGreenhouseIndex = garden.getGreenhouses().size() - 1;
        updateDisplay();
        ui->greenhouseList->setCurrentRow(currentGreenhouseIndex);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

void MainWindow::addBed()
{
    if (garden.getGreenhouses().isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Сначала добавьте парник");
        return;
    }

    if (currentGreenhouseIndex == -1) {
        currentGreenhouseIndex = 0;
        ui->greenhouseList->setCurrentRow(currentGreenhouseIndex);
    }

    bool ok;
    QString crop = QInputDialog::getText(this, "Добавить грядку",
                                         "Введите культуру:",
                                         QLineEdit::Normal, "", &ok);
    if (!ok || crop.isEmpty()) return;

    int plantCount = QInputDialog::getInt(this, "Добавить грядку",
                                          "Введите количество растений:",
                                          1, -10000, 10000, 1, &ok);
    if (!ok) return;

    try {
        GardenBed bed(crop, plantCount);
        garden.getGreenhouses()[currentGreenhouseIndex].addBed(bed);
        updateDisplay();
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

void MainWindow::searchCrop()
{
    if (garden.getGreenhouses().isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Нет данных для поиска");
        return;
    }

    bool ok;
    QString crop = QInputDialog::getText(this, "Поиск",
                                         "Введите культуру для поиска:",
                                         QLineEdit::Normal, "", &ok);
    if (!ok || crop.isEmpty()) return;

    try {
        QList<int> counts = garden.countPlantsInAllGreenhouses(crop);
        QString result = QString("Количество растений '%1' по парникам:\n").arg(crop);

        for (int i = 0; i < counts.size(); ++i) {
            result += QString("Парник %1: %2 растений\n").arg(i+1).arg(counts[i]);
        }

        QMessageBox::information(this, "Результаты поиска", result);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

void MainWindow::updateDisplay()
{
    ui->greenhouseList->clear();
    ui->bedList->clear();

    const auto& greenhouses = garden.getGreenhouses();
    for (int i = 0; i < greenhouses.size(); ++i) {
        ui->greenhouseList->addItem(QString("Парник %1 (%2 грядок)")
                                        .arg(i+1)
                                        .arg(greenhouses[i].getBeds().size()));
    }

    if (currentGreenhouseIndex >= 0 && currentGreenhouseIndex < greenhouses.size()) {
        const auto& beds = greenhouses[currentGreenhouseIndex].getBeds();
        for (const auto& bed : beds) {
            ui->bedList->addItem(QString("%1 (%2 растений)")
                                     .arg(bed.getCrop())
                                     .arg(bed.getPlantCount()));
        }
    }
}
