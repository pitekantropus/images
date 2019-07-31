#pragma once

#include "Image.hpp"

#include <string>

class ImagePpm : public Image
{
public:
    ~ImagePpm() = default;
    void save(const std::string &path) const;
    void loadBitmap(const std::vector<char> &pixels);

    std::string imageType;
    uint16_t maxValue;
};
