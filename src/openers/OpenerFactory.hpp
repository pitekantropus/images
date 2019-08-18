#include <string>
#include <memory>

class Image;
enum class FileType;

class OpenerFactory
{
public:
    OpenerFactory(const std::string &path);

    std::unique_ptr<Image> getOpener() const;

private:
    FileType getFileExtension() const;

    std::string _path;
};