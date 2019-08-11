#include <images/ImagePpm.hpp>

#include <fstream>

void ImagePpm::saveAsText(const std::string &path) const
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

void ImagePpm::saveBinary(const std::string &path) const
{
    std::ofstream file(path);
    if(!file.is_open())
    {
        throw std::string("Couldn't open file.");
    }
    file << "P6" << std::endl
         << width << " " << height << std::endl
         << maxValue << std::endl;

    for(const auto &row : pixelMatrix)
    {
        for(const auto &pixel : row)
        {
            file.write((char*)&pixel.red, 1);
            file.write((char*)&pixel.green, 1);
            file.write((char*)&pixel.blue, 1);
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
            pixel.red = pixels[i*3*width + j];
            pixel.green = pixels[i*3*width + j + 1];
            pixel.blue = pixels[i*3*width + j + 2];
            pixelMatrix[i].push_back(pixel);
        }
    }
}
