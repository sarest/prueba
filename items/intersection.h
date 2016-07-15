#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <QObject>

class Intersection
{
public:
    Intersection();
    QString intersection_id;
    QStringList intersection_parameters;
    QStringList intersection_values;
};

#endif // INTERSECTION_H
