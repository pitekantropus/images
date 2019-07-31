#include "ImagePpm.hpp"

#include <fstream>

void ImagePpm::save(const std::string &path) const
{
    std::ofstream file(path);
    if(!file.is_open())
    {
        throw std::string("Couldn't open file.");
    }
    file << "P3" << std::endl
         << width << " " << height << std::endl
         << maxValue << std::endl;

    uint8_t counter = 0;
    for(const auto &row : pixelMatrix)
    {
        for(const auto &pixel : row)
        {
            ++counter;
            std::string separator = counter % 6 ? " " : "\n";
            file << pixel.toString() << separator;
        }
    }
}

void ImagePpm::loadBitmap(const std::vector<char> &pixels)
{
    pixelMatrix.reserve(height);

    for(size_t i = 0; i < height; i++)
    {
        pixelMatrix.push_back({});
        pixelMatrix[i].reserve(width);
        for(size_t j = 0; j < 3*width; j+=3)
        {
            Pixel pixel;
            pixel.xPos = j/3;
            pixel.yPos = i;
            pixel.red = pixels[i*3*width + j];
            pixel.green = pixels[i*3*width + j + 1];
            pixel.blue = pixels[i*3*width + j + 2];
            pixelMatrix[i].push_back(pixel);
        }
    }
}
