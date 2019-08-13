#include <algorithms/Negative.hpp>
#include <algorithms/Shading.hpp>
#include <algorithms/Masking.hpp>

#include <iostream>

int main()
{
    PixelMask mask = {{-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1}};
    Masking algorithm(std::move(mask));
    algorithm.performAndSave("../src/data/rebus.ppm", "../src/data/binary.ppm");

    return 0;
}