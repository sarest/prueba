#ifndef SIGNAL_H
#define SIGNAL_H

#include <QObject>


class Signal
{
public:
    Signal();
    QString signal_id;
    QStringList signal_parameters;
    QStringList signal_values;
};

#endif // SIGNAL_H
