
#include "Point.h"


Point Point::operator+(const Point& other) const{
    return Point(x + other.x, y + other.y, z + other.z);
}

Point Point::operator=(const struct parser::Vec3f& vec){
    this->x=vec.x;
    this->y=vec.y;
    this->z=vec.z;

    return *this;
}