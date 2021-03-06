#include "functions.h"

Functions::Functions()
{

}

void Functions::function_load()
{
    QString fileName_load = mydoc->load_file();
    function_delete_circuit();
    mydoc->xml_reader(fileName_load);
    circuit_function=mydoc->mycircuit;
}

void Functions::function_save()
{
    QString fileName_save = mydoc->save_file();

    mydoc->xml_writer(fileName_save);
}

void Functions::function_save_rect(float x0, float y0, float x1, float y1)
{
    Road *myroad = new Road;
    Path *mypath = new Path;

    mypath->path_id.append("straight_line");
    mypath->path_parameters.append("x_start");
    mypath->path_parameters.append("y_start");
    mypath->path_parameters.append("x_end");
    mypath->path_parameters.append("y_end");
    mypath->path_values.append(QString::number(x0));
    mypath->path_values.append(QString::number(y0));
    mypath->path_values.append(QString::number(x1));
    mypath->path_values.append(QString::number(y1));
    mypath->path_types.append("float");
    mypath->path_types.append("float");
    mypath->path_types.append("float");
    mypath->path_types.append("float");

    myroad->road_id.append("straight_line");
    myroad->road_path_list.append(mypath);
    mydoc->mycircuit->circuit_road_list.append(myroad);
}

void Functions::function_save_arc(float x0, float y0, float radius, float angle, float x_center, float y_center, float distance)
{
    Road *myroad = new Road;
    Path *mypath = new Path;

    mypath->path_id.append("arc");
    mypath->path_parameters.append("x_start");
    mypath->path_parameters.append("y_start");
    mypath->path_parameters.append("radius");
    mypath->path_parameters.append("distance");
    mypath->path_parameters.append("x_center");
    mypath->path_parameters.append("y_center");
    mypath->path_parameters.append("angle");

    mypath->path_values.append(QString::number(x0));
    mypath->path_values.append(QString::number(y0));
    mypath->path_values.append(QString::number(radius));
    mypath->path_values.append(QString::number(distance));
    mypath->path_values.append(QString::number(x_center));
    mypath->path_values.append(QString::number(y_center));
    mypath->path_values.append(QString::number(angle));

    mypath->path_types.append("float");
    mypath->path_types.append("float");
    mypath->path_types.append("float");
    mypath->path_types.append("float");
    mypath->path_types.append("float");
    mypath->path_types.append("float");
    mypath->path_types.append("float");

    myroad->road_id.append("arc");
    myroad->road_path_list.append(mypath);
    mydoc->mycircuit->circuit_road_list.append(myroad);
}

void Functions::function_save_intersection()
{
    mydoc->mycircuit->circuit_intersection_list.clear();
    for(int i=0; i<mydoc->mycircuit->circuit_road_list.count(); i++){
        if(mydoc->mycircuit->circuit_road_list.count() > (i+1)){
            Intersection *myintersection = new Intersection;
            myintersection->intersection_id = mydoc->mycircuit->circuit_road_list.at(i)->road_id+"_plus_"+mydoc->mycircuit->circuit_road_list.at(i+1)->road_id;
            myintersection->intersection_parameters.append("from_road");
            myintersection->intersection_parameters.append("to_road");
            myintersection->intersection_parameters.append("type");
            myintersection->intersection_types.append("string");
            myintersection->intersection_types.append("string");
            myintersection->intersection_types.append("string");
            myintersection->intersection_values.append(mydoc->mycircuit->circuit_road_list.at(i)->road_id);
            myintersection->intersection_values.append(mydoc->mycircuit->circuit_road_list.at(i+1)->road_id);
            myintersection->intersection_values.append("direct");

            mydoc->mycircuit->circuit_intersection_list.append(myintersection);
        }
    }
}

void Functions::function_save_rails()
{
    for(int i=0; i<mydoc->mycircuit->circuit_road_list.count(); i++){
        Rail *myrail = new Rail;
        myrail->rail_id = "0";
        myrail->rail_parameters.append("width");
        myrail->rail_parameters.append("direction");
        myrail->rail_types.append("float");
        myrail->rail_types.append("integer");
        myrail->rail_values.append("3.8");
        myrail->rail_values.append("1");
        mydoc->mycircuit->circuit_road_list.at(i)->road_rail_list.append(myrail);
    }
}

void Functions::function_save_signals()
{
    Signal *mysignal = new Signal;
    mysignal->signal_id = mydialog->signal_dialog->signal_id;
    for(int i=0; i<mydialog->signal_dialog->signal_parameters.count(); i++){
        mysignal->signal_parameters.append(mydialog->signal_dialog->signal_parameters.at(i));
        mysignal->signal_values.append(mydialog->signal_dialog->signal_values.at(i));
        mysignal->signal_types.append(mydialog->signal_dialog->signal_types.at(i));
    }
    mydoc->mycircuit->circuit_road_list.last()->road_signal_list.append(mysignal);
}

void Functions::function_rect_calculations(float x0, float y0, float x1, float y1)
{
    float x = abs(x1-x0);
    float y = abs(y1-y0);
    rect_length = sqrt(x*x+y*y);
    bool first=0,second=0,third=0,fourth=0;
    if(((x1-x0)>=0)&&((y1-y0)>=0)){
        first=1;
        rect_angle = atan(y/x)*180/pi;
    }
    if(((x1-x0)<=0)&&((y1-y0)>=0)){
        second=1;
        rect_angle = 180-(atan(y/x)*180/pi);
    }
    if(((x1-x0)<=0)&&((y1-y0)<=0)){
        third=1;
        rect_angle = 180+(atan(y/x)*180/pi);
    }
    if(((x1-x0)>=0)&&((y1-y0)<=0)){
        fourth=1;
        rect_angle = 360-(atan(y/x)*180/pi);
    }
    if(first && fourth)
        rect_angle = 0;
    if(first && second)
        rect_angle = 90;
    if(second && third)
        rect_angle = 180;
    if(third && fourth)
        rect_angle = 270;
}

void Functions::function_curve_calculations(float x_start, float y_start, float length, float radius)
{
    spanAngle_rads = length/radius;
    spanAngle_degrees = -(spanAngle_rads*180)/pi; //negative to move clockwise

    float rect_angle_rads = (rect_angle*pi)/180;
    float x_A_I,y_A_I,angle,x_C,y_C,x_C_I,y_C_I,x_B,y_B,x_B_I,y_B_I,x_D_I,y_D_I,
            vector_CB_x,vector_CB_y,vector_CB_modulus,vector_CB_angle,
            vector_CB_angle_rotated,vector_x_rotated,vector_y_rotated,
            vector_CA_x,vector_CA_y,vector_CA_angle;

    x_A_I = x_start;
    y_A_I = y_start;
    angle = rect_angle_rads;

    //Compute C point (with respect to the inertial system)
    x_C = 0.0;
    y_C = -radius;
    x_C_I = x_A_I + cos(angle)*x_C - sin(angle)*y_C;
    y_C_I = y_A_I + sin(angle)*x_C + cos(angle)*y_C;
    x_center = x_C_I;
    y_center = y_C_I;

    //Compute B point (with respect to the inertial system)
    x_B = -radius;
    y_B = 0;
    x_B_I = x_A_I + cos(angle)*x_B - sin(angle)*y_B;
    y_B_I = y_A_I + sin(angle)*x_B + cos(angle)*y_B;

    //Compute vector CB an rotate it
    vector_CB_x = x_B_I - x_C_I;
    vector_CB_y = y_B_I - y_C_I;
    vector_CB_modulus = sqrt(vector_CB_x*vector_CB_x + vector_CB_y*vector_CB_y);
    vector_CB_angle = atan2(vector_CB_y,vector_CB_x);
    vector_CB_angle_rotated = vector_CB_angle - angle;
    vector_x_rotated = vector_CB_modulus*cos(vector_CB_angle_rotated);
    vector_y_rotated = vector_CB_modulus*sin(vector_CB_angle_rotated);

    //Compute D point (with respect to the inertial system)
    x_D_I = x_C_I + vector_x_rotated;
    y_D_I = y_C_I + vector_y_rotated;
    x_displace = x_D_I;
    y_displace = y_D_I;

    //Compute vector CA
    vector_CA_x = x_A_I - x_C_I;
    vector_CA_y = y_A_I - y_C_I;
    vector_CA_angle = atan2(vector_CA_y,vector_CA_x);
    start_angle_degrees = vector_CA_angle*180/pi;
}

void Functions::function_curve_calculations_left(float x_start, float y_start, float length, float radius)
{
        spanAngle_rads = length/radius;
        spanAngle_degrees = spanAngle_rads*180/pi; //move counter-clockwise

        float rect_angle_rads = (rect_angle*pi)/180;
        float x_A_I,y_A_I,angle,x_C,y_C,x_C_I,y_C_I,x_B,y_B,x_B_I,y_B_I,x_D_I,y_D_I,
                vector_CB_x,vector_CB_y,vector_CB_modulus,vector_CB_angle,
                vector_CB_angle_rotated,vector_x_rotated,vector_y_rotated,
                vector_CA_x,vector_CA_y,vector_CA_angle;

        x_A_I = x_start;
        y_A_I = y_start;
        angle = rect_angle_rads;

        //Compute C point (with respect to the inertial system)
        x_C = 0.0;
        y_C = radius;
        x_C_I = x_A_I + cos(angle)*x_C - sin(angle)*y_C;
        y_C_I = y_A_I + sin(angle)*x_C + cos(angle)*y_C;
        x_center = x_C_I;
        y_center = y_C_I;

        //Compute B point (with respect to the inertial system)
        x_B = -radius;
        y_B = radius*2;
        x_B_I = x_A_I + cos(angle)*x_B - sin(angle)*y_B;
        y_B_I = y_A_I + sin(angle)*x_B + cos(angle)*y_B;

        //Compute vector CB an rotate it
        vector_CB_x = x_B_I - x_C_I;
        vector_CB_y = y_B_I - y_C_I;
        vector_CB_modulus = sqrt(vector_CB_x*vector_CB_x + vector_CB_y*vector_CB_y);
        vector_CB_angle = atan2(vector_CB_y,vector_CB_x);
        vector_CB_angle_rotated = vector_CB_angle - angle;
        vector_x_rotated = vector_CB_modulus*cos(vector_CB_angle_rotated);
        vector_y_rotated = vector_CB_modulus*sin(vector_CB_angle_rotated);

        //Compute D point (with respect to the inertial system)
        x_D_I = x_C_I + vector_x_rotated;
        y_D_I = y_C_I + vector_y_rotated;
        x_displace = x_D_I;
        y_displace = y_D_I;

        //Compute vector CA
        vector_CA_x = x_A_I - x_C_I;
        vector_CA_y = y_A_I - y_C_I;
        vector_CA_angle = atan2(vector_CA_y,vector_CA_x);
        start_angle_degrees = vector_CA_angle*180/pi;

}

void Functions::function_delete_circuit()
{
    mydoc->mycircuit->circuit_id.clear();
    mydoc->mycircuit->circuit_road_list.clear();
    mydoc->mycircuit->circuit_intersection_list.clear();
    mydoc->intersection_list.clear();
    mydoc->path_list.clear();
    mydoc->rail_list.clear();
    mydoc->road_list.clear();
    mydoc->signal_list.clear();
    circuit_function=mydoc->mycircuit;
}

void Functions::function_signal()
{
    if(mydialog->exec()==QDialog::Accepted){
        qDebug()<<"dialogo aceptado";
        function_save_signals();
    }
    else{
        qDebug()<<"dialogo rechazado";
    }
}
