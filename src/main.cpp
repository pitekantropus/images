#include "algorithms/Algorithm.hpp"

#include <iostream>

int main()
{
    Algorithm algorithm;
    auto image = algorithm.getImage("images/photo.ppm");

    std::cout<<"Width: "<<image.width<<std::endl;

    return 0;
}