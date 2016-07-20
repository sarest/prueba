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
    int start_x,start_y,final_x,final_y;
private:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    QPointF start_point, final_point;
};

#endif // MYQGRAPHICSVIEW_H
