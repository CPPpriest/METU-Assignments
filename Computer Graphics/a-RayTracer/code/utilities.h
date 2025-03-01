#ifndef __UTILITIES__
#define __UTILITIES__


#include "Vector.h"





// Ray
struct Ray
{
    Point origin;  
    Vector direction;
    int depth;

    Ray(Point o, Vector v);
};











struct Matrix
{
    Vector col1, col2, col3;

    Matrix(Vector c1, Vector c2, Vector c3): col1(c1),col2(c2),col3(c3){};

    double det();
};














struct Pixel {
    double r, g, b;

    Pixel(double red = 0, double green = 0, double blue = 0) : r(red), g(green), b(blue) {}
    Pixel(parser::Vec3i pVal) : r(pVal.x), g(pVal.y), b(pVal.z) {}
    void add(Pixel other);
    void set(parser::Vec3i pVal);
    operator Vector() const;
    void operator=(const struct parser::Vec3f& vec);
    Pixel operator*(Pixel other);

};









unsigned char clamp(double value);










struct hitRecord
{
    // Index of the OBJECT in scene_objects
    int ObjID;

    // isHit
    bool isHit;

    // hit properties
    Point hitPoint;
    Vector hitNormal; 


    // Material
    Pixel ambient;
    Pixel diffuse;
    Pixel specular;
    Pixel mirror;
    double phong;
};























#endif