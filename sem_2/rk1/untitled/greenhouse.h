#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include "gardenbed.h"
#include <QList>

class Greenhouse {
public:
    Greenhouse();

    void addBed(const GardenBed& bed);
    QList<GardenBed> getBeds() const;
    int countPlants(const QString& crop) const;

private:
    QList<GardenBed> beds;
};

#endif // GREENHOUSE_H
