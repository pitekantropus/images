#include <openers/ImageOpener.hpp>
#include <utils/CommonTypes.hpp>

ImageOpener::ImageOpener(const std::string &path)
    : _path(path)
{}

FileType ImageOpener::getFileExtension() const
{
    auto pos = _path.find_last_of('.');
    const std::string extension = _path.substr(pos+1);
    if(extension == "ppm")
    {
        return FileType::PPM;
    }
    else
    {
        return FileType::UNSUPPORTED;
    }
}