#ifndef PATH_H
#define PATH_H

#include <QObject>

class Path
{
public:
    Path();
    QString path_id;
    QStringList path_parameters;
    QStringList path_values;
};

#endif // PATH_H
