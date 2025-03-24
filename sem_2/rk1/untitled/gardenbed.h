#ifndef GARDENBED_H
#define GARDENBED_H

#include <QString>

class GardenBed {
public:
    GardenBed(const QString& crop, int plantCount);

    QString getCrop() const;
    int getPlantCount() const;

private:
    QString crop;
    int plantCount;
};

#endif // GARDENBED_H
