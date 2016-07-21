#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QObject>
#include "files.h"
#include "items/road.h"
#include "items/path.h"
#include "items/circuit.h"
#include "items/intersection.h"


class Functions
{
public:
    Functions();
    void function_load();
    void function_save();

    void function_save_rect(float x0,float y0,float x1,float y1);
    void function_save_arc(float x0, float y0, float radius, float angle, float x_center, float y_center, float distance);
    void function_save_intersection();

    void function_rect_calculations(float x0,float y0,float x1,float y1);
    void function_curve_calculations(float x_start, float y_start, float length, float radius);

    void function_delete_circuit();

    Files *mydoc = new Files;
    Circuit *circuit_function = new Circuit;

    float rect_angle,rect_length,spanAngle_degrees,x_displace,y_displace,spanAngle_rads,x_center,y_center,start_angle_degrees;

private:
    const double pi = 3.141592653589793238463;
};

#endif // FUNCTIONS_H
