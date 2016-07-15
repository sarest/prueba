#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <QObject>
#include "items/road.h"
#include "items/intersection.h"

class Circuit
{
public:
    Circuit();
    QString circuit_id;
    QList<Road*> circuit_road_list;
    QList<Intersection*> circuit_intersection_list;
};

#endif // CIRCUIT_H
