#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->view_layout->addWidget(view);

    set_grid();

    ui->rRight->click();

    QPixmap logo(":/imgs/ctag_logo.png");
    logo=logo.scaled(100,100);
    ui->title_label->setPixmap(logo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bLoad_clicked()
{
    myfunctions->function_load();
    print_circuit();
    ui->statusBar->showMessage("Circuit " + myfunctions->circuit_function->circuit_id + " loaded");
}

void MainWindow::on_bSave_clicked()
{
    myfunctions->function_save_intersection();
    myfunctions->function_save_rails();
    myfunctions->function_save();
}

void MainWindow::on_bRect_clicked()
{
    float x0,y0,y1,x1;
    x0 = ui->x0_value->text().toFloat();
    y0 = ui->y0_value->text().toFloat();
    x1 = ui->x1_value->text().toFloat();
    y1 = ui->y1_value->text().toFloat();

    if(x0!=0 || y0!=0 || x1!=0 || y1!=0){
        QPen pen(Qt::black,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
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

        info_text.append("| Rect length = " + QString::number(myfunctions->rect_length) + " m. | ");
        ui->info_label->setText(info_text);

        ui->start_x->setText(ui->x1_value->text());
        ui->start_y->setText(ui->y1_value->text());

        myfunctions->function_signal();
    }
    else{
        ui->statusBar->showMessage("Invalid parameters");
    }
}

void MainWindow::on_bCurve_clicked()
{
    if(ui->length->text().toFloat() !=0 && ui->radius->text().toFloat() != 0){
        if(ui->rRight->isChecked())
            myfunctions->function_curve_calculations(ui->start_x->text().toFloat(),ui->start_y->text().toFloat()
                                             ,ui->length->text().toFloat(),ui->radius->text().toFloat());
        else if(ui->rLeft->isChecked())
            myfunctions->function_curve_calculations_left(ui->start_x->text().toFloat(),ui->start_y->text().toFloat()
                                             ,ui->length->text().toFloat(),ui->radius->text().toFloat());
        float radius = ui->radius->text().toFloat();
        QPen pen(Qt::black,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
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

        myfunctions->function_signal();
    }
    else{
        ui->statusBar->showMessage("Invalid parameters");
    }
}

void MainWindow::print_circuit()
{
    QPen pen(Qt::black,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    for(int i=0;i<myfunctions->circuit_function->circuit_road_list.count();i++){
        if(myfunctions->circuit_function->circuit_road_list.at(i)->road_id=="straight_line"){
            float x0 = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(0).toFloat();
            float y0 = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(1).toFloat();
            float x1 = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(2).toFloat();
            float y1 = myfunctions->circuit_function->circuit_road_list.at(i)->road_path_list.first()->path_values.at(3).toFloat();
            myfunctions->function_rect_calculations(x0,y0,x1,y1);
            view->scene->addLine(x0,-y0,x1,-y1,pen);
        }
        if(myfunctions->circuit_function->circuit_road_list.at(i)->road_id=="arc"){
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

void MainWindow::set_grid()
{
    //view->scene->setBackgroundBrush(QBrush(QPixmap(":/imgs/grid.png")));

    for (int x=-9000; x<=9000; x+=10)
        view->scene->addLine(x,-9000,x,9000, QPen(Qt::green,0.5,Qt::DashLine));
    for (int y=-9000; y<=9000; y+=10)
        view->scene->addLine(-9000,y,9000,y, QPen(Qt::green,0.5,Qt::DashLine));

    view->scene->addLine(-9000,0,9000,0,QPen(Qt::green,1.5));
    view->scene->addLine(0,-9000,0,9000,QPen(Qt::green,1.5));


    for (int x=-1000; x<=1000; x+=100){
        QGraphicsTextItem *meters = new QGraphicsTextItem;
        meters->setPos(x,0);
        meters->setPlainText(QString::number(x)+"m");
        view->scene->addItem(meters);
        view->scene->addLine(x,0,x,0);
    }
    for (int y=-1000; y<=1000; y+=100){
        QGraphicsTextItem *meters = new QGraphicsTextItem;
        meters->setPos(0,y);
        meters->setPlainText(QString::number(-y)+"m");
        view->scene->addItem(meters);
        view->scene->addLine(0,y,0,y);
    }
}

void MainWindow::on_bClear_clicked()
{
    view->scene->clear();
    set_grid();
    myfunctions->function_delete_circuit();
    ui->start_x->clear();
    ui->start_y->clear();
    ui->radius->clear();
    ui->length->clear();
    ui->x0_value->clear();
    ui->x1_value->clear();
    ui->y0_value->clear();
    ui->y1_value->clear();
    ui->info_label->clear();
    info_text.clear();
    ui->statusBar->showMessage("");
}

void MainWindow::on_bTest_clicked()
{
    //view->scene->addRect(view->sceneRect());
    //myfunctions->function_signal();
    /*QWebView *webview;
    webview->resize(1000,500);
    webview->move(10,10);
    QString gMapURL = "England"; // this is where you want to point
    gMapURL = "http://maps.google.com.sg/maps?q="+gMapURL+"&oe=utf-8&rls=org.mozilla:en-US:official&client=firefox-a&um=1&ie=UTF-8&hl=en&sa=N&tab=wl";
    webview->setUrl(QUrl(gMapURL));*/
}

void MainWindow::on_bConfirm_clicked()
{
    if((view->start_x == view->final_x) && (view->start_y == view->final_y)){
        ui->statusBar->showMessage("Invalid draw");
    }
    else{
        ui->x0_value->setText(QString::number(view->start_x));
        ui->y0_value->setText(QString::number(-view->start_y));
        ui->x1_value->setText(QString::number(view->final_x));
        ui->y1_value->setText(QString::number(-view->final_y));
        on_bRect_clicked();
    }
}

void MainWindow::on_bUndo_clicked()
{
    view->scene->items().first()->hide();
}
