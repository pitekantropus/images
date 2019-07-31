#include "Negative.hpp"

void Negative::performAndSave(const std::string &srcPath, const std::string &destPath) const
{
    auto image = getImage(srcPath);
    makeNegative(image);
    image->saveBinary(destPath);
}

void Negative::makeNegative(std::unique_ptr<Image> &image) const
{
    image->forEachPixel([](Pixel &pixel){
        pixel.red = 255 - pixel.red;
        pixel.green = 255 - pixel.green;
        pixel.blue = 255 - pixel.blue;
    });
}