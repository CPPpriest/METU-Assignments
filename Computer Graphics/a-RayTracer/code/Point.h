
#ifndef __POINT__
#define __POINT__


#include <iostream>
#include "parser.h"
#include "ppm.h"
#include <cmath>
#include <cfloat>




// 3D Point
struct Point
{
    double x, y, z;

    Point(double a = 0.0f, double b = 0.0f, double c = 0.0f):x(a),y(b),z(c){};

    // Auto-cast Vec3f to Vector
    Point(const struct parser::Vec3f& vec):x(vec.x),y(vec.y),z(vec.z){};

    Point operator+(const Point& other) const;
    
    Point operator=(const struct parser::Vec3f& vec);

};



#endif