#include <algorithms/Negative.hpp>
#include <images/Image.hpp>

void Negative::apply(Image &image) const
{
    image.forEachPixel([](Pixel &pixel){
        pixel.red = 255 - pixel.red;
        pixel.green = 255 - pixel.green;
        pixel.blue = 255 - pixel.blue;
    });
}