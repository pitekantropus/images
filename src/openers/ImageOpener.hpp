#pragma once

#include <images/Image.hpp>

#include <string>
#include <memory>

enum class FileType;

class ImageOpener
{
public:
    ImageOpener(const std::string &path);
    virtual ~ImageOpener() = default;

    virtual std::unique_ptr<Image> getImage() const = 0;

protected:
    std::string _path;
};
