#ifndef FILES_H
#define FILES_H

#include <QObject>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <QtXml/QDomDocument>
#include <QXmlStreamWriter>
#include <QtXml/QDomElement>
#include <QtXml/qdom.h>

#include "items/signal.h"
#include "items/rail.h"
#include "items/intersection.h"
#include "items/path.h"
#include "items/road.h"
#include "items/circuit.h"

class Files
{
public:
    Files();
    QString load_file();
    QString save_file();

    Circuit *mycircuit = new Circuit;
    QList<Road*> road_list;
    QList<Path*> path_list;
    QList<Signal*> signal_list;
    QList<Rail*> rail_list;
    QList<Intersection*> intersection_list;

    void xml_reader(QString xml_file);
    void xml_writer(QString fileName);

private:
    void parse_roads(QDomElement docElem);
    void parse_paths(QDomNode node);
    void parse_rails(QDomNode node);
    void parse_signals(QDomNode node);
    void parse_intersections(QDomElement docElem);
};

#endif // FILES_H
