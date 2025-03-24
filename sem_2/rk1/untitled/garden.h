#ifndef GARDEN_H
#define GARDEN_H

#include "greenhouse.h"
#include <QList>

class Garden {
public:
    Garden();

    void addGreenhouse(const Greenhouse& greenhouse);
    QList<Greenhouse>& getGreenhouses();  // Изменено на возврат по ссылке
    const QList<Greenhouse>& getGreenhouses() const;
    QList<int> countPlantsInAllGreenhouses(const QString& crop) const;

private:
    QList<Greenhouse> greenhouses;
};

#endif // GARDEN_H
