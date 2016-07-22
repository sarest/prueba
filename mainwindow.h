#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myqgraphicsview.h"
#include "functions.h"
#include "files.h"
#include <QWheelEvent>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bLoad_clicked();
    void on_bSave_clicked();
    void on_bRect_clicked();
    void on_bCurve_clicked();
    void on_bClear_clicked();
    void on_bTest_clicked();
    void on_bConfirm_clicked();
    void on_bUndo_clicked();

    void on_bSignal_clicked();

private:
    Ui::MainWindow *ui;
    Functions *myfunctions = new Functions;
    MyQGraphicsView *view = new MyQGraphicsView;
    void print_circuit();
    QString info_text;
    void set_grid();
};

#endif // MAINWINDOW_H
