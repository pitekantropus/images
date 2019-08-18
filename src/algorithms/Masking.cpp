#include <algorithms/Masking.hpp>
#include <images/utils/RawPixel.hpp>
#include <images/Image.hpp>

#include <iostream>

Masking::Masking(PixelMask mask)
    : _mask(std::move(mask))
{
    _height = _mask.size();
    _width = _height > 0 ? _mask[0].size() : 0;
    _sum = 0;
    for(auto line : _mask)
    {
        for(auto factor : line)
        {
            _sum += factor;
        }
    }
    if(_sum == 0) _sum = 1;
    std::cout<<"Height: "<<_height<<" Width: "<<_width<<std::endl;
}

void Masking::apply(Image &image) const
{
    PixelMatrix extendedMatrix = image.getMatrixWithBorder(_width / 2, _height / 2);
    for(size_t i = 0; i < image.getHeight(); i++)
    {
        for(size_t j = 0; j < image.getWidth(); j++)
        {
            RawPixel pixel = {};
            for(size_t k = 0; k < _height; k++)
            {
                for(size_t l = 0; l < _width; l++)
                {
                    pixel = pixel + RawPixel(extendedMatrix[i + k][j + l]) * _mask[k][l];
                }
            }
            pixel = pixel / _sum;
            pixel.normalize();
            image.setPixel(j, i, pixel.getPixel());
        }
    }
}