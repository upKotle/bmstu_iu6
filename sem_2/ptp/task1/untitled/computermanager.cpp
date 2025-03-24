#include "computermanager.h"
#include <QFile>
#include <QTextStream>

void ComputerManager::addComputer(const Computer &comp) {
    computers.push_back(comp);
}

void ComputerManager::removeComputer(int index) {
    if (index >= 0 && index < computers.size()) {
        computers.erase(computers.begin() + index);
    }
}

std::vector<Computer> ComputerManager::getComputers() const {
    return computers;
}

bool ComputerManager::saveToFile(const QString &filename) const {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    for (const auto &comp : computers) {
        out << comp.getCpu() << ","
            << comp.getRam() << ","
            << comp.getHdd() << ","
            << comp.getPrice() << "\n";
    }

    file.close();
    return true;
}

bool ComputerManager::loadFromFile(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    computers.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 4) {
            QString cpu = parts[0];
            int ram = parts[1].toInt();
            int hdd = parts[2].toInt();
            double price = parts[3].toDouble();
            computers.emplace_back(cpu, ram, hdd, price);
        }
    }

    file.close();
    return true;
}
