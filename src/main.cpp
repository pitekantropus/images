#include <algorithms/Negative.hpp>
#include <algorithms/Shading.hpp>
#include <algorithms/Masking.hpp>

#include <iostream>

int main()
{
    PixelMask mask = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Masking algorithm(std::move(mask));
    algorithm.performAndSave("../src/data/rebus.ppm", "../src/data/binary.ppm");

    return 0;
}