#include "utilities.h"






Ray::Ray(Point o, Vector v):origin(o),direction(v),depth(0){
    (this->direction).normalize();
}


void Pixel::add(Pixel other) {
    this->r += other.r;
    this->g += other.g;
    this->b += other.b;
}



void Pixel::set(parser::Vec3i pVal)
{
    this->r = pVal.x;
    this->g = pVal.y;
    this->b = pVal.z;
}

Pixel Pixel::operator*(Pixel other){
    this->r *= other.r;
    this->g *= other.g;
    this->b *= other.b;

    return *this;
}




unsigned char clamp(double value){
    return (unsigned char) (value > 255 ? 255 : (value < 0 ? 0 : value));
}





double Matrix::det()
{
        return  col1.x * ( col2.y * col3.z - col2.z * col3.y ) 
                -
                col2.x * ( col1.y * col3.z - col1.z * col3.y ) 
                + 
                col3.x * ( col1.y * col2.z - col1.z * col2.y ) ;

}





Pixel::operator Vector() const{
    return Vector(this->r,this->g,this->b);
}



void Pixel::operator=(const struct parser::Vec3f& vec){
    this->r=vec.x;
    this->g=vec.y;
    this->b=vec.z;
}

