#include <openers/PpmOpener.hpp>
#include <images/ImagePpm.hpp>

#include <fstream>
#include <sstream>

PpmOpener::PpmOpener(const std::string &path)
    : ImageOpener(path)
{}

std::unique_ptr<Image> PpmOpener::getImage() const
{
    std::ifstream file = getImageFile();
    std::unique_ptr<ImagePpm> image = std::make_unique<ImagePpm>();
    std::string line;
    uint32_t width, height;

    skipComments(file);
    std::getline(file, line);
    image->imageType = line;

    skipComments(file);
    std::getline(file, line);
    std::stringstream str(line);
    str >> width >> height;
    image->setWidth(width);
    image->setHeight(height);

    skipComments(file);
    std::getline(file, line);
    image->maxValue = std::stoul(line);

    uint32_t numberOfValues = 3 * width * height;

    if(image->imageType == "P3")
    {
        std::vector<int> pixelsBuffer;
        pixelsBuffer.reserve(numberOfValues);
        int k;
        for(size_t i = 0; i < numberOfValues; i++)
        {
            file >> k;
            pixelsBuffer.push_back(k);
        }
        image->loadBitmap(pixelsBuffer);
    }
    else
    {
        std::vector<char> pixelsBuffer(numberOfValues);
        file.read((char *)(&pixelsBuffer[0]), numberOfValues);
        image->loadBitmap(pixelsBuffer);
    }

    return image;
}

void PpmOpener::skipComments(std::ifstream &stream) const
{
    while(stream.peek() != std::char_traits<char>::eof())
    {
        if(stream.peek() == '#')
        {
            std::string s;
            std::getline(stream, s);
        }
        else
        {
            return;
        }
    }
    throw std::string("Unexpected end of file");
}