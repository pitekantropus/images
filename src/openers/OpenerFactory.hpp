#include <string>
#include <memory>

class ImageOpener;
enum class FileType;

class OpenerFactory
{
public:
    OpenerFactory(const std::string &path);

    std::unique_ptr<ImageOpener> getOpener() const;

private:
    FileType getFileExtension() const;

    std::string _path;
};