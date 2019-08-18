#include <algorithms/Shading.hpp>
#include <images/Image.hpp>

void Shading::apply(Image &image) const
{
    image.forEachPixel([](Pixel &pixel){
        auto value = (pixel.red + pixel.green + pixel.blue) / 3;
        pixel.red = value;
        pixel.green = value;
        pixel.blue = value;
    });
}