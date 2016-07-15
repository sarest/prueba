#ifndef ROAD_H
#define ROAD_H

#include <QObject>
#include <items/path.h>
#include <items/rail.h>
#include <items/signal.h>

class Road
{
public:
    Road();
    QString road_id;
    QList<Path*> road_path_list;
    QList<Signal*> road_signal_list;
    QList<Rail*> road_rail_list;
};

#endif // ROAD_H
