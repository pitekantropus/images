#include <algorithms/Shading.hpp>

void Shading::performAndSave(const std::string &srcPath, const std::string &destPath) const
{
    auto image = getImage(srcPath);
    makeShadeScale(image);
    image->saveBinary(destPath);
}

void Shading::makeShadeScale(std::unique_ptr<Image> &image) const
{
    image->forEachPixel([](Pixel &pixel){
        auto value = (pixel.red + pixel.green + pixel.blue) / 3;
        pixel.red = value;
        pixel.green = value;
        pixel.blue = value;
    });
}