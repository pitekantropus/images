#include <images/utils/RawPixel.hpp>

#include <sstream>
#include <iomanip>

RawPixel::RawPixel(const Pixel &rhs)
    : red(rhs.red)
    , green(rhs.green)
    , blue(rhs.blue)
{}

RawPixel RawPixel::operator*(int d) const
{
    RawPixel pixel = *this;
    pixel.red *= d;
    pixel.green *= d;
    pixel.blue *= d;
    return pixel;
}

RawPixel RawPixel::operator/(int d) const
{
    RawPixel pixel = *this;
    pixel.red /= d;
    pixel.green /= d;
    pixel.blue /= d;
    return pixel;
}

RawPixel RawPixel::operator+(const RawPixel &rhs) const
{
    RawPixel pixel = *this;
    pixel.red += rhs.red;
    pixel.green += rhs.green;
    pixel.blue += rhs.blue;
    return pixel;
}

void RawPixel::normalize()
{
    normalizeOne(red);
    normalizeOne(green);
    normalizeOne(blue);
}

Pixel RawPixel::getPixel() const
{
    Pixel pixel = {};
    pixel.red = static_cast<uint8_t>(red);
    pixel.green = static_cast<uint8_t>(green);
    pixel.blue = static_cast<uint8_t>(blue);
    return pixel;
}

void RawPixel::normalizeOne(int32_t &color)
{
    if(color < 0) color = 0;
    if(color > 255) color = 255;
}

std::string RawPixel::toString() const
{
    std::stringstream stream;
    stream << std::setw(3) << (unsigned)red << " "
           << std::setw(3) << (unsigned)green << " "
           << std::setw(3) << (unsigned)blue;
    return stream.str();
}
