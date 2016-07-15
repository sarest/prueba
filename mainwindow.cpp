#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view->setBackgroundBrush(QBrush(QPixmap(":/imgs/grid.png")));
    QPen penpoint(Qt::red,1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    view->scene->addLine(0,0,10,0,penpoint);
    view->scene->addLine(0,0,0,10,penpoint);
    view->scene->addLine(0,0,-10,0,penpoint);
    view->scene->addLine(0,0,0,-10,penpoint);
    ui->main_layout->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bLoad_clicked()
{
    myfunctions->function_load();
    print_circuit();
}

void MainWindow::on_bSave_clicked()
{
    myfunctions->function_save();
}

void MainWindow::on_bRect_clicked()
{
    float x0,y0,y1,x1;
    x0 = ui->x0_value->text().toFloat();
    y0 = ui->y0_value->text().toFloat();
    x1 = ui->x1_value->text().toFloat();
    y1 = ui->y1_value->text().toFloat();

    QPen pen(Qt::black,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    view->scene->addLine(x0,-y0,x1,-y1,pen);
    myfunctions->function_save_rect(x0,y0,x1,y1);
    myfunctions->function_rect_calculations(x0,y0,x1,y1);

    QString status_text;
    status_text.append("Final point: (");
    status_text.append(QString::number(x1));
    status_text.append(",");
    status_text.append(QString::number(y1));
    status_text.append(")");
    ui->statusBar->showMessage(status_text);

    ui->start_x->setText(ui->x1_value->text());
    ui->start_y->setText(ui->y1_value->text());
}

void MainWindow::on_bCurve_clicked()
{
    myfunctions->function_curve_calculations(ui->start_x->text().toFloat(),ui->start_y->text().toFloat()
                                             ,ui->length->text().toFloat(),ui->radius->text().toFloat());

    float radius = ui->radius->text().toFloat();
    QPen pen(Qt::black,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    QPainterPath arc_path;
    arc_path.moveTo(ui->start_x->text().toFloat(),-ui->start_y->text().toFloat());
    arc_path.arcTo(myfunctions->x_displace,-myfunctions->y_displace,radius*2,radius*2,
                   myfunctions->start_angle_degrees,myfunctions->spanAngle_degrees);
    view->scene->addPath(arc_path,pen);

    QPointF final_point;
    final_point = arc_path.pointAtPercent(1);
    QString status_text;
    status_text.append("Final point: (");
    status_text.append(QString::number(final_point.rx()));
    status_text.append(",");
    status_text.append(QString::number(-final_point.ry()));
    status_text.append(")");
    ui->statusBar->showMessage(status_text);
    ui->x0_value->setText(QString::number(final_point.rx()));
    ui->y0_value->setText(QString::number(-final_point.ry()));

    myfunctions->function_save_arc(ui->start_x->text().toFloat(),ui->start_y->text().toFloat()
                                   ,ui->radius->text().toFloat()
                                   ,myfunctions->spanAngle_rads
                                   ,myfunctions->x_center,myfunctions->y_center
                                   ,ui->length->text().toFloat());
}

void MainWindow::print_circuit()
{
    QPen pen(Qt::black,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    qDebug()<<"print circuit";
    qDebug()<<myfunctions->circuit_function->circuit_id;
    for(int i=0;i<myfunctions->circuit_function->circuit_road_list.count();i++){
        if(myfunctions->circuit_function->circuit_road_list.at(i)->road_id=="straight_line"){
            qDebug()<<"there is a rect";
            float x0 = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(0).toFloat();
            float y0 = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(1).toFloat();
            float x1 = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(2).toFloat();
            float y1 = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(3).toFloat();
            myfunctions->function_rect_calculations(x0,y0,x1,y1);
            view->scene->addLine(x0,-y0,x1,-y1,pen);
        }
        if(myfunctions->circuit_function->circuit_road_list.at(i)->road_id=="arc"){
            qDebug()<<"there is an arc";
            float start_x,start_y,length,radius;
            start_x = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(0).toFloat();
            start_y = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(1).toFloat();
            radius = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(2).toFloat();
            length = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(3).toFloat();

            myfunctions->function_curve_calculations(start_x,start_y,length,radius);

            QPainterPath arc_path;
            arc_path.moveTo(start_x,-start_y);
            arc_path.arcTo(myfunctions->x_displace,-myfunctions->y_displace,radius*2,radius*2,
                           myfunctions->start_angle_degrees,myfunctions->spanAngle_degrees);
            view->scene->addPath(arc_path,pen);
        }
    }
}

void MainWindow::on_bClear_clicked()
{
    view->scene->clear();
    QPen penpoint(Qt::red,1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    view->scene->addLine(0,0,10,0,penpoint);
    view->scene->addLine(0,0,0,10,penpoint);
    view->scene->addLine(0,0,-10,0,penpoint);
    view->scene->addLine(0,0,0,-10,penpoint);
    myfunctions->function_delete_circuit();
    ui->start_x->clear();
    ui->start_y->clear();
    ui->radius->clear();
    ui->length->clear();
    ui->x0_value->clear();
    ui->x1_value->clear();
    ui->y0_value->clear();
    ui->y1_value->clear();
    ui->statusBar->showMessage("");
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0) {
        if (event->orientation() == Qt::Vertical)
            view->scale(1.05,1.05);
    }
    else if (event->delta() < 0) {
        if (event->orientation() == Qt::Vertical)
            view->scale(0.95,0.95);
    }
}

void MainWindow::on_bTest_clicked()
{
    qDebug()<<"test out";
}

/*float radius = ui->radius->text().toFloat();
float length = ui->length->text().toFloat();
float x0 = ui->start_x->text().toFloat();
float y0 = ui->start_y->text().toFloat();

float spanAngle_rads = length/radius;
float startAngle_rads = atan(y0/x0);
float finalAngle_rads = startAngle_rads - spanAngle_rads;
float startAngle_degrees = startAngle_rads*180/pi;
float spanAngle_degrees = spanAngle_rads*180/pi;
float finalAngle_degrees = finalAngle_rads*180/pi;

qDebug()<<"start_angle"<<startAngle_rads<<"("<<startAngle_degrees<<")";
qDebug()<<"span_angle"<<spanAngle_rads<<"("<<spanAngle_degrees<<")";
qDebug()<<"final_angle"<<finalAngle_rads<<"("<<finalAngle_degrees<<")";

float x1 = radius * cos(finalAngle_rads);
float y1 = radius * sin(finalAngle_rads);

QPainterPath arc_path;
arc_path.moveTo(x0,-y0);
arc_path.lineTo(x1,-y1);
view->scene->addPath(arc_path);

float x_center,y_center;



qDebug()<<"x0:"<<x0<<"y0:"<<y0;
qDebug()<<"x1:"<<x1<<"y1:"<<y1;*/

/*QPainterPath bezier_path;
double k = 0.55191502449; // aproximate arc with bezier curves

bezier_path.moveTo(x0,-y0);
bezier_path.cubicTo(k*radius,-radius,radius,-k*radius,radius,0);
bezier_path.cubicTo(radius,k*radius,k*radius,radius,0,radius);
bezier_path.cubicTo(-k*radius,radius,-radius,k*radius,-radius,0);
bezier_path.cubicTo(-radius,-k*radius,-k*radius,-radius,0,-radius);

view->scene->addPath(bezier_path);*/

/*QPainterPath arc_path;
arc_path.moveTo(x0,-y0);
float mediumAngle_rads,xm,ym;
for(float i=startAngle_rads; i>=finalAngle_rads; i=i-0.1){
        mediumAngle_rads = startAngle_rads - i;
        xm = radius * cos(mediumAngle_rads);
        ym = radius * sin(mediumAngle_rads);
        arc_path.lineTo(xm,-ym);
}
view->scene->addPath(arc_path);*/


/*QRectF rectangle(0,0,100,100);
//QTransform rotation_transform;
//rotation_transform.rotate(90);
//rotation_transform.translate(rectangle.width(),-rectangle.height());
//QRectF rotated = rotation_transform.mapRect(rectangle);
QMatrix rotation_matrix;
rotation_matrix.rotate(45);
QRectF rotated = rotation_matrix.mapRect(rectangle);
//view->scene->addRect(rectangle);
view->scene->addRect(rotated);*/
