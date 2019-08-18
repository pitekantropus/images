#include <openers/ImageOpener.hpp>
#include <utils/CommonTypes.hpp>

#include <fstream>

ImageOpener::ImageOpener(const std::string &path)
    : _path(path)
{}

std::ifstream ImageOpener::getImageFile() const
{
    std::ifstream file(_path);
    if(!file.is_open())
    {
        throw std::string("Couldn't open file.");
    }
    return file;
}
