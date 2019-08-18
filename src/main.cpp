#include <algorithms/Negative.hpp>
#include <algorithms/Shading.hpp>
#include <algorithms/Masking.hpp>
#include <openers/OpenerFactory.hpp>
#include <openers/PpmOpener.hpp>

#include <images/Image.hpp>

#include <iostream>

int main(int argc, char **argv)
{
    // if(argc == 1 || commands.count(argv[1]) == 0)
    // {
    //     std::cout<<"Unsupported command"<<std::endl;
    //     return 0;
    // }

    // tokenize(std::vector<std::string>(argv[1], argv[argc-1]));

    if(argc != 3)
    {
        std::cout<<"Wrong number of parameters";
        return 1;
    }
    std::string source = argv[1];
    std::string destination = argv[2];

    PixelMask mask = {{-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1}};
    Masking algorithm(std::move(mask));

    // PpmOpener opener(source);
    // ImageOpener *opener = new PpmOpener(source);
    // auto image = opener->getImage();

    OpenerFactory factory(source);
    auto opener = factory.getOpener();
    auto image = opener->getImage();

    algorithm.apply(*image);
    image->saveBinary(destination);

    return 0;
}