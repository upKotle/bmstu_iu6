#include "gardenbed.h"

GardenBed::GardenBed(const QString& crop, int plantCount)
    : crop(crop), plantCount(plantCount) {
    if (plantCount <= 0) {
        throw std::invalid_argument("Количество растений должно быть положительным");
    }
    if (crop.isEmpty()) {
        throw std::invalid_argument("Название культуры не может быть пустым");
    }
}

QString GardenBed::getCrop() const {
    return crop;
}

int GardenBed::getPlantCount() const {
    return plantCount;
}
