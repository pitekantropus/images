#pragma once

#include "Image.hpp"

#include <string>

class ImagePpm : public Image
{
public:
    ~ImagePpm() = default;
    void save(const std::string &path) const;
    void loadBitmap(std::vector<char> pixels, uint32_t width, uint32_t height);

    std::string imageType;
    uint16_t maxValue;
};
