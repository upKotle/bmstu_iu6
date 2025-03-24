#include "greenhouse.h"

Greenhouse::Greenhouse() {}

void Greenhouse::addBed(const GardenBed& bed) {
    beds.append(bed);
}

QList<GardenBed> Greenhouse::getBeds() const {
    return beds;
}

int Greenhouse::countPlants(const QString& crop) const {
    int total = 0;
    for (const auto& bed : beds) {
        if (bed.getCrop().toLower() == crop.toLower()) {
            total += bed.getPlantCount();
        }
    }
    return total;
}
