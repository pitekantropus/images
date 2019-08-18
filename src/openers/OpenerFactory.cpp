#include <openers/OpenerFactory.hpp>
#include <openers/PpmOpener.hpp>
#include <utils/CommonTypes.hpp>

OpenerFactory::OpenerFactory(const std::string &path)
    : _path(path)
{}

std::unique_ptr<ImageOpener> OpenerFactory::getOpener() const
{
    switch(getFileExtension())
    {
        case FileType::PPM:
        {
            return std::make_unique<PpmOpener>(_path);
        }
        case FileType::UNSUPPORTED:
        default:
        {
            throw std::string("Format if not supported.");
        }
    }
}

FileType OpenerFactory::getFileExtension() const
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
