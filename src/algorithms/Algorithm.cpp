#include "Algorithm.hpp"
#include "../images/ImagePpm.hpp"
#include "../utils/CommonTypes.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

void Algorithm::performAndSave(const std::string &srcPath, const std::string &destPath) const
{
    auto image = getImage(srcPath);
    image->save(destPath);
}

std::unique_ptr<Image> Algorithm::getImage(const std::string &path) const
{
    auto fileExtension = getFileExtension(path);
    if(fileExtension == FileType::UNSUPPORTED)
    {
        throw std::string("Format is not supported.");
    }
    std::ifstream file(path);
    if(!file.is_open())
    {
        throw std::string("Couldn't open file.");
    }
    switch(fileExtension)
    {
        case FileType::PPM:
            return getPpmImage(file);
        default:
            throw std::string("Format if not supported.");
    }
}

FileType Algorithm::getFileExtension(const std::string &path) const
{
    auto pos = path.find_last_of('.');
    const std::string extension = path.substr(pos+1);
    if(extension == "ppm")
    {
        return FileType::PPM;
    }
    else
    {
        return FileType::UNSUPPORTED;
    }
}

std::unique_ptr<Image> Algorithm::getPpmImage(std::ifstream &file) const
{
    std::unique_ptr<ImagePpm> image = std::make_unique<ImagePpm>();
    std::string line;
    uint32_t width, height;

    skipComments(file);
    std::getline(file, line);
    image->imageType = line;

    skipComments(file);
    std::getline(file, line);
    std::stringstream str(line);
    str >> width >> height;
    image->width = width;
    image->height = height;

    skipComments(file);
    std::getline(file, line);
    image->maxValue = std::stoul(line);

    uint32_t numberOfValues = 3 * width * height;
    std::vector<char> pixelsBuffer(numberOfValues);
    file.read((char *)(&pixelsBuffer[0]), numberOfValues);

    image->loadBitmap(pixelsBuffer);

    return image;
}

void Algorithm::skipComments(std::ifstream &stream, char commentSign) const
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