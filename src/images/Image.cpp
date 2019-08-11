#include <images/Image.hpp>

#include <iostream>

uint32_t Image::getWidth() const
{
    return width;
}

void Image::setWidth(uint32_t width)
{
    this->width = width;
}

uint32_t Image::getHeight() const
{
    return height;
}

void Image::setHeight(uint32_t height)
{
    this->height = height;
}

PixelMatrix& Image::getPixelMatrix()
{
    return pixelMatrix;
}

void Image::setPixel(uint32_t posX, uint32_t posY, Pixel pixel)
{
    if(posX >= width || posY >= height)
    {
        std::cout<<"Pixel out of range"<<std::endl;
        return;
    }
    pixelMatrix[posY][posX] = std::move(pixel);
}

void Image::forEachPixel(std::function<void(Pixel&)> function)
{
    for(auto &row : pixelMatrix)
    {
        for(auto &pixel : row)
        {
            function(pixel);
        }
    }
}

PixelMatrix Image::getMatrixWithBorder(uint16_t borderWidth, uint16_t borderHeight) const
{
    PixelMatrix newMatrix;
    newMatrix.reserve(height + 2*borderHeight);
    for(size_t i = 0; i < borderHeight; i++)
    {
        newMatrix.push_back(getExtendedLine(borderWidth, 0));
    }
    for(size_t i = 0; i < height; i++)
    {
        newMatrix.push_back(getExtendedLine(borderWidth, i));
    }
    for(size_t i = 0; i < borderHeight; i++)
    {
        newMatrix.push_back(getExtendedLine(borderWidth, height - 1));
    }

    return newMatrix;
}

std::vector<Pixel> Image::getExtendedLine(uint16_t borderWidth, uint32_t lineIndex) const
{
    std::vector<Pixel> borderLine;
    const auto &imageLine = pixelMatrix[lineIndex];

    borderLine.reserve(width + 2*borderWidth);
    for(size_t j = 0; j < borderWidth; j++)
    {
        borderLine.push_back(imageLine.front());
    }
    borderLine.insert(borderLine.begin() + borderWidth, imageLine.begin(), imageLine.end());
    for(size_t j = 0; j < borderWidth; j++)
    {
        borderLine.push_back(imageLine.back());
    }
    return borderLine;
}
