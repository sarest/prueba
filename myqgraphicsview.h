#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class MyQGraphicsView: public QGraphicsView
{
public:
    explicit MyQGraphicsView(QWidget *parent = 0);
    QGraphicsScene *scene;
private:
    void mousePressEvent(QMouseEvent *e);
};

#endif // MYQGRAPHICSVIEW_H
