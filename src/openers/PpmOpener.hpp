#include <openers/ImageOpener.hpp>

class PpmOpener : ImageOpener
{
public:
    PpmOpener(const std::string &path);
    ~PpmOpener() = default;

    std::unique_ptr<Image> getImage() const;

private:
    void skipComments(std::ifstream &stream) const;
};