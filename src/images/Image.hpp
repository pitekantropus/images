#pragma once

#include <images/utils/Pixel.hpp>

#include <vector>
#include <functional>

using PixelLine = std::vector<Pixel>;
using PixelMatrix = std::vector<PixelLine>;

class Image
{
public:
    Image() = default;
    virtual ~Image() = default;
    virtual void saveAsText(const std::string &path) const = 0;
    virtual void saveBinary(const std::string &path) const = 0;
    virtual void loadBitmap(const std::vector<char> &pixels) = 0;

    uint32_t getWidth() const;
    void setWidth(uint32_t width);
    uint32_t getHeight() const;
    void setHeight(uint32_t height);
    PixelMatrix& getPixelMatrix();
    void setPixel(uint32_t posX, uint32_t posY, Pixel pixel);

    void forEachPixel(std::function<void(Pixel&)> function);
    PixelMatrix getMatrixWithBorder(uint16_t borderWidth, uint16_t borderHeight) const;

protected:
    PixelMatrix pixelMatrix;
    uint32_t width;
    uint32_t height;

    std::vector<Pixel> getExtendedLine(uint16_t borderWidth, uint32_t lineIndex) const;
};
