#ifndef __VECTOR__
#define __VECTOR__


#include "Point.h"


// 3D Vector
struct Vector
{
    double x, y, z;

    // Default Constructor
    Vector(double a = 0.0f, double b = 0.0f, double c = 0.0f):x(a),y(b),z(c){};

    // Points to Vector Constructor 
    Vector(Point a, Point b);

    // Auto-cast Vec3f to Vector
    Vector(const struct parser::Vec3f& vec);

    Vector operator*(double scalar) const;

    Vector operator+(Vector other) const;

    operator Point() const;

    void normalize();

    double magnitude();
};






Vector crossProduct( Vector A , Vector B );

double dotProduct( Vector A , Vector B );






#endif