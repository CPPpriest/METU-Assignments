#include <iomanip>
#include <iostream>
#include "Color.h"

Color::Color() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

Color::Color(double r, double g, double b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

Color::Color(const Color &other)
{
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;
}

std::ostream &operator<<(std::ostream &os, const Color &c)
{
    os << std::fixed << std::setprecision(0) << "rgb(" << c.r << ", " << c.g << ", " << c.b << ")";
    return os;
}


Color Color::operator-(const Color &other) const {
    return Color(
        r - other.r,
        g - other.g,
        b - other.b
    );
}


Color& Color::operator*=(double value) {
    r *= value;
    g *= value;
    b *= value;
    return *this;
}
