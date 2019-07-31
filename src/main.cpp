#include "algorithms/Algorithm.hpp"
#include "algorithms/Negative.hpp"

#include <iostream>

int main()
{
    // Algorithm algorithm;
    Negative algorithm;
    algorithm.performAndSave("../src/data/rebus.ppm", "../src/data/binary.ppm");

    return 0;
}