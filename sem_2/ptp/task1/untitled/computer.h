#ifndef COMPUTER_H
#define COMPUTER_H

#include <QString>

class Computer {
public:
    Computer(QString cpu, int ram, int hdd, double price);

    QString getCpu() const;
    int getRam() const;
    int getHdd() const;
    double getPrice() const;

private:
    QString cpu;
    int ram;
    int hdd;
    double price;
};

#endif // COMPUTER_H
