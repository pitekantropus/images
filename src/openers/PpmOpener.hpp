#include <openers/ImageOpener.hpp>

class Image;
class ifstream;

class PpmOpener : public ImageOpener
{
public:
    PpmOpener(const std::string &path);
    ~PpmOpener() = default;

    std::unique_ptr<Image> getImage() const override;

private:
    void skipComments(std::ifstream &stream) const;
};