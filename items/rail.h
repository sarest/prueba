#ifndef RAIL_H
#define RAIL_H

#include <QObject>


class Rail
{
public:
    Rail();
    QString rail_id;
    QStringList rail_parameters;
    QStringList rail_values;
    float rail_width = 3.0;
    int rail_direction = 1;
};

#endif // RAIL_H
