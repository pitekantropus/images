#pragma once

#include <string>
#include <memory>

class ifstream;
class Image;
enum class FileType;

class ImageOpener
{
public:
    ImageOpener(const std::string &path);
    virtual ~ImageOpener() = default;

    virtual std::unique_ptr<Image> getImage() const = 0;

protected:
    virtual std::ifstream getImageFile() const;

    std::string _path;
};
