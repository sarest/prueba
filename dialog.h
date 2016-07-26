#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "items/signal.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    Signal *signal_dialog = new Signal;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
    QString type_of(QString value);
};

#endif // DIALOG_H
