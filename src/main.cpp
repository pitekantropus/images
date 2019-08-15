#include <algorithms/Negative.hpp>
#include <algorithms/Shading.hpp>
#include <algorithms/Masking.hpp>

#include <iostream>
#include <unordered_set>

int main(int argc, char **argv)
{
    // if(argc == 1 || commands.count(argv[1]) == 0)
    // {
    //     std::cout<<"Unsupported command"<<std::endl;
    //     return 0;
    // }

    // tokenize(std::vector<std::string>(argv[1], argv[argc-1]));

    PixelMask mask = {{-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1}};
    Masking algorithm(std::move(mask));
    algorithm.performAndSave("../src/data/rebus.ppm", "../src/data/binary.ppm");

    return 0;
}