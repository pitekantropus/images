#include "Algorithm.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

Image Algorithm::getImage(const std::string &path)
{
    std::fstream file(path);
    if(file.is_open())
    {
        std::cout<<"Start"<<std::endl;
        Image image;
        std::string line;
        std::string dimensions;
        if(skipComments(file))
        {
            std::getline(file, line);
            std::cout<<"line: "<<line<<std::endl;
        }
        if(skipComments(file))
        {
            std::getline(file, line);
            std::cout<<"line: "<<line<<std::endl;
        }
        std::stringstream str(line);
        str >> image.width >> image.height;
        if(skipComments(file))
        {
            std::getline(file, line);
            std::cout<<"line: "<<line<<std::endl;
        }

        uint32_t numberOfValues = 3*image.width*image.height;
        std::vector<uint8_t> pixelsBuffer(numberOfValues);
        file.read((char*)(&pixelsBuffer[0]), numberOfValues);

        auto &pixels = image.pixelMatrix;
        pixels.reserve(image.height);

        for(size_t i = 0; i < image.height; i++)
        {
            pixels.push_back({});
            pixels[i].reserve(image.width);
            for(size_t j = 0; j < 3*image.width; j+=3)
            {
                Pixel pixel;
                pixel.xPos = j/3;
                pixel.yPos = i;
                pixel.red = pixelsBuffer[j*3*image.width + j];
                pixel.green = pixelsBuffer[j*3*image.width + j + 1];
                pixel.blue = pixelsBuffer[j*3*image.width + j + 2];
                pixels[i].push_back(pixel);
            }
        }

        return image;
    }
    std::cout<<"Couldn't open file."<<std::endl;
    throw std::string("Couldn't open file.");
}

bool Algorithm::skipComments(std::fstream &stream, char commentSign)
{
    while(stream.peek() != std::char_traits<char>::eof())
    {
        if(stream.peek() == commentSign)
        {
            std::string s;
            std::getline(stream, s);
            std::cout<<"skipped: "<<s<<std::endl;
        }
        else
        {
            return true;
        }
    }
    std::cout<<"EOF: "<<std::endl;
    return false;
}