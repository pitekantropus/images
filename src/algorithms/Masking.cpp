#include <algorithms/Masking.hpp>
#include <images/utils/RawPixel.hpp>

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
    image->saveAsText(destPath);
}

void Masking::applyMask(std::unique_ptr<Image> &image) const
{
    PixelMatrix extendedMatrix = image->getMatrixWithBorder(width / 2, height / 2);
    // for(auto &line : extendedMatrix)
    // {
    //     for(auto &pixel : line)
    //     {
    //         std::cout<<pixel.toString()<<" ";
    //     }
    //     std::cout<<std::endl;
    // }
    for(size_t i = 0; i < image->getHeight(); i++)
    {
        for(size_t j = 0; j < image->getWidth(); j++)
        {
            RawPixel pixel = {};
            // std::cout<<pixel.toString()<<std::endl;
            for(size_t k = 0; k < height; k++)
            {
                for(size_t l = 0; l < width; l++)
                {
                    pixel = pixel + RawPixel(extendedMatrix[i + k][j + l]) * mask[k][l];
                    // std::cout<<"Current: "<<pixel.toString()<<std::endl;
                    // std::cout<<"Origin: "<<extendedMatrix[i + k][j + l].toString()<<std::endl;
                    // std::cout<<"Mask: "<<mask[k][l]<<std::endl;
                    // std::cout<<pixel.toString()<<std::endl;
                }
            }
            // std::cout<<"Sum: "<<pixel.toString()<<std::endl;
            pixel = pixel / sum;
            // std::cout<<"Sum divided: "<<pixel.toString()<<std::endl;
            pixel.normalize();
            // std::cout<<pixel.getPixel().toString()<<std::endl;
            image->setPixel(j, i, pixel.getPixel());
        }
    }
}