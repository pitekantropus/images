#include "Pixel.hpp"

#include <sstream>
#include <iomanip>
#include <iostream>

std::string Pixel::toString() const
{
    std::stringstream stream;
    stream << std::setw(3) << (unsigned)red << " "
           << std::setw(3) << (unsigned)green << " "
           << std::setw(3) << (unsigned)blue;
    return stream.str();
}

Pixel Pixel::operator*(int d) const
{
    Pixel pixel = *this;
    pixel.red *= d;
    pixel.green *= d;
    pixel.blue *= d;
    return pixel;
}

Pixel Pixel::operator/(int d) const
{
    Pixel pixel = *this;
    pixel.red /= d;
    pixel.green /= d;
    pixel.blue /= d;
    return pixel;
}

Pixel Pixel::operator+(const Pixel &rhs)
{
    Pixel pixel = *this;
    pixel.red += rhs.red;
    pixel.green += rhs.green;
    pixel.blue += rhs.blue;
    return pixel;
}
