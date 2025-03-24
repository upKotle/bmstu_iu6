#include "computer.h"

Computer::Computer(QString cpu, int ram, int hdd, double price)
    : cpu(cpu), ram(ram), hdd(hdd), price(price) {}

QString Computer::getCpu() const { return cpu; }
int Computer::getRam() const { return ram; }
int Computer::getHdd() const { return hdd; }
double Computer::getPrice() const { return price; }
