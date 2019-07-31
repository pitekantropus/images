#include "Image.hpp"

void Image::forEachPixel(std::function<void(Pixel&)> function)
{
    for(auto &row : pixelMatrix)
    {
        for(auto &pixel : row)
        {
            function(pixel);
        }
    }
}