#include "Pixel.hpp"

#include <sstream>
#include <iomanip>

std::string Pixel::toString() const
{
    std::stringstream stream;
    stream << std::setw(3) << (unsigned)red << " "
           << std::setw(3) << (unsigned)green << " "
           << std::setw(3) << (unsigned)blue;
    return stream.str();
}