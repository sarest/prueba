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

    round_point_values();

    scene->addLine(start_x,start_y,final_x,final_y,pen);
}

void MyQGraphicsView::wheelEvent(QWheelEvent *e)
{
    if (e->delta() > 0) {
        if (e->orientation() == Qt::Vertical)
            this->scale(1.05,1.05);
    }
    else if (e->delta() < 0) {
        if (e->orientation() == Qt::Vertical)
            this->scale(0.95,0.95);
    }
}

void MyQGraphicsView::round_point_values()
{
    if(abs(start_x%10) < 5){
        start_x = start_x-(start_x%10);
    }
    else{
        if(start_x < 0)
            start_x = start_x-(start_x%10)-10;
        else
            start_x = start_x-(start_x%10)+10;
    }

    if(abs(start_y%10) < 5){
        start_y = start_y-(start_y%10);
    }
    else{
        if(start_y < 0)
            start_y = start_y-(start_y%10)-10;
        else
            start_y = start_y-(start_y%10)+10;
    }

    if(abs(final_x%10) < 5){
        final_x = final_x-(final_x%10);
    }
    else{
        if(final_x < 0)
            final_x = final_x-(final_x%10)-10;
        else
            final_x = final_x-(final_x%10)+10;
    }

    if(abs(final_y%10) < 5){
        final_y = final_y-(final_y%10);
    }
    else{
        if(final_y < 0)
            final_y = final_y-(final_y%10)-10;
        else
            final_y = final_y-(final_y%10)+10;
    }
}

void MyQGraphicsView::zoomToFit()
{
    fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}
