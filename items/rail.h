#ifndef RAIL_H
#define RAIL_H

#include <QObject>


class Rail
{
public:
    Rail();
    QString rail_id;
    QStringList rail_parameters;
    QStringList rail_types;
    QStringList rail_values;
};

#endif // RAIL_H
