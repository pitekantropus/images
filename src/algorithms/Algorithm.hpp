#pragma once

#include "../images/Image.hpp"

#include <string>
#include <memory>

enum class FileType;

class Algorithm
{
public:
    Algorithm() = default;
    virtual ~Algorithm() = default;

    virtual void performAndSave(const std::string &srcPath, const std::string &destPath) const;

protected:
    std::unique_ptr<Image> getImage(const std::string &path) const;
    FileType getFileExtension(const std::string &path) const;
    std::unique_ptr<Image> getPpmImage(std::ifstream &file) const;
    void skipComments(std::ifstream &stream, char commentSign = '#') const;
};
