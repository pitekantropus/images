#include "Negative.hpp"

bool Negative::performAndSave(const std::string &srcPath, const std::string &destPath)
{
    auto image = getImage(srcPath);
    makeNegative(image);
    if(image.saveAsFile(destPath))
    {
        return false;
    }
    return true;
}