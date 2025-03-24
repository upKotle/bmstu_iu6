#include "garden.h"

Garden::Garden() {}

void Garden::addGreenhouse(const Greenhouse& greenhouse) {
    greenhouses.append(greenhouse);
}

QList<Greenhouse>& Garden::getGreenhouses() {
    return greenhouses;
}

const QList<Greenhouse>& Garden::getGreenhouses() const {
    return greenhouses;
}

QList<int> Garden::countPlantsInAllGreenhouses(const QString& crop) const {
    QList<int> counts;
    for (const auto& greenhouse : greenhouses) {
        counts.append(greenhouse.countPlants(crop));
    }
    return counts;
}
