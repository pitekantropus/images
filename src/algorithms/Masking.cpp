#include <algorithms/Masking.hpp>

#include <iostream>

Masking::Masking(PixelMask mask)
    : mask(mask)
{
    height = mask.size();
    width = height > 0 ? mask[0].size() : 0;
    sum = 0;
    for(auto line : mask)
    {
        for(auto factor : line)
        {
            sum += factor;
        }
    }
    if(sum == 0) sum = 1;
}

void Masking::performAndSave(const std::string &srcPath, const std::string &destPath) const
{
    auto image = getImage(srcPath);
    applyMask(image);
    image->saveBinary(destPath);
}

void Masking::applyMask(std::unique_ptr<Image> &image) const
{
    PixelMatrix extendedMatrix = image->getMatrixWithBorder(width / 2, height / 2);
    for(size_t i = 0; i < 1/* image->getHeight() */; i++)
    {
        for(size_t j = 0; j < 1/* image->getWidth() */; j++)
        {
            Pixel pixel = {};
            std::cout<<pixel.toString()<<std::endl;
            for(size_t k = 0; k < height; k++)
            {
                for(size_t l = 0; l < width; l++)
                {
                    pixel = pixel + extendedMatrix[i + k][j + l] * mask[k][l];
                    std::cout<<extendedMatrix[i + k][j + l].toString()<<std::endl;
                    std::cout<<pixel.toString()<<std::endl;
                }
            }
            pixel = pixel / sum;
            std::cout<<pixel.toString()<<std::endl;
            pixel.normalize();
            std::cout<<pixel.toString()<<std::endl;
            image->setPixel(j, i, std::move(pixel));
        }
    }
}