#ifndef COMPUTERMANAGER_H
#define COMPUTERMANAGER_H

#include "computer.h"
#include <vector>
#include <QString>

class ComputerManager {
public:
    void addComputer(const Computer &comp);
    void removeComputer(int index);
    std::vector<Computer> getComputers() const;

    bool saveToFile(const QString &filename) const;
    bool loadFromFile(const QString &filename);

private:
    std::vector<Computer> computers;
};

#endif // COMPUTERMANAGER_H
