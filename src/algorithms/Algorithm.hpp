#pragma once

#include "../Image.hpp"

#include <string>

class Algorithm
{
public:
    Algorithm() = default;
    virtual ~Algorithm() = default;

    // virtual bool performAndSave(const std::string &srcPath, const std::string &destPath) = 0;

// protected:
    Image getImage(const std::string &path);
    bool skipComments(std::fstream &stream, char commentSign = '#');
};
