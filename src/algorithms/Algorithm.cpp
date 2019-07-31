#include "Algorithm.hpp"
#include "../images/ImagePpm.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

void Algorithm::performAndSave(const std::string &srcPath, const std::string &destPath)
{
    auto image = getImage(srcPath);
    image->save(destPath);
}

std::unique_ptr<Image> Algorithm::getPpmImage(const std::string &path)
{
    std::fstream file(path);
    if(!file.is_open())
    {
        throw std::string("Couldn't open file.");
    }
        std::unique_ptr<ImagePpm> image = std::make_unique<ImagePpm>();
        std::string line;
        std::string dimensions;
        uint32_t width, height;

        skipComments(file)
        std::getline(file, line);
        image->imageType = line;

        skipComments(file)
            std::getline(file, line);
            std::stringstream str(line);
            str >> width >> height;
            image->width = width;
            image->height = height;

        skipComments(file)
            std::getline(file, line);
            image->maxValue = std::stoul(line);

        uint32_t numberOfValues = 3*width*height;
        std::vector<char> pixelsBuffer(numberOfValues);
        file.read((char*)(&pixelsBuffer[0]), numberOfValues);

        auto &pixels = image->pixelMatrix;


        return image;
}

void Algorithm::skipComments(std::fstream &stream, char commentSign)
{
    while(stream.peek() != std::char_traits<char>::eof())
    {
        if(stream.peek() == commentSign)
        {
            std::string s;
            std::getline(stream, s);
        }
        else
        {
            return;
        }
    }
    throw std::string("Unexpected end of file");
}