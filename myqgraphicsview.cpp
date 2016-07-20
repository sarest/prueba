#include "myqgraphicsview.h"

#include <QDebug>

MyQGraphicsView::MyQGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    this->setScene(scene);
}

void MyQGraphicsView::mousePressEvent(QMouseEvent * e)
{
    start_point = mapToScene(e->pos());
}

void MyQGraphicsView::mouseReleaseEvent(QMouseEvent *e)
{
    final_point = mapToScene(e->pos());

    QPen pen(Qt::black,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    start_x = (int)start_point.x();
    start_y = (int)start_point.y();
    final_x = (int)final_point.x();
    final_y = (int)final_point.y();
    scene->addLine(start_x,start_y,final_x,final_y,pen);
}
