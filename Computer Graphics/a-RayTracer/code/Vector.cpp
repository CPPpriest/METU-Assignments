#include "Vector.h"


// Points to Vector Constructor 
Vector::Vector(Point a, Point b)
{
    x = a.x - b.x;
    y = a.y - b.y;
    z = a.z - b.z;
}



// Auto-cast Vec3f to Vector
Vector::Vector(const struct parser::Vec3f& vec)
{   
    x = vec.x;
    y = vec.y;
    z = vec.z;
}



Vector Vector::operator*(double scalar) const 
{
    return Vector(x * scalar, y * scalar, z * scalar);
}




Vector Vector::operator+(Vector other) const
{
    return Vector(this->x+other.x , this->y+other.y ,this->z+other.z );
}



Vector::operator Point() const {
    return Point(this->x, this->y, this->z);
}



void Vector::normalize()
{
    double mag = sqrt( x*x + y*y + z*z );
    x /= mag;
    y /= mag;
    z /= mag;

}


double Vector::magnitude(){
    double retValue = dotProduct(*this,*this);
    return sqrt(retValue);
}



Vector crossProduct( Vector A , Vector B )
{
    Vector result(  A.y * B.z  - A.z * B.y,
                    -(A.x * B.z - A.z * B.x) ,
                    A.x * B.y  - A.y * B.x    );
    return result;
};



double dotProduct( Vector A , Vector B )
{
    return A.x * B.x + A.y * B.y + A.z * B.z ; 
}

