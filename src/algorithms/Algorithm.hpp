#pragma once

#include "../images/Image.hpp"

#include <string>
#include <memory>

class Algorithm
{
public:
    Algorithm() = default;
    virtual ~Algorithm() = default;

    virtual void performAndSave(const std::string &srcPath, const std::string &destPath);

protected:
    std::unique_ptr<Image> getImage(const std::string &path);
    bool skipComments(std::fstream &stream, char commentSign = '#');
};
