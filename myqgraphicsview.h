#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QWheelEvent>

class MyQGraphicsView: public QGraphicsView
{
public:
    explicit MyQGraphicsView(QWidget *parent = 0);
    QGraphicsScene *scene;  
    int start_x = 0,start_y = 0,final_x = 0,final_y = 0;
private:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent *e);
    QPointF start_point, final_point;
    void round_point_values();
    void zoomToFit();
};

#endif // MYQGRAPHICSVIEW_H
