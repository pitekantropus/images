#include "algorithms/Algorithm.hpp"

#include <iostream>

int main()
{
    Algorithm algorithm;
    algorithm.performAndSave("data/photo.ppm", "data/raw.ppm");

    return 0;
}