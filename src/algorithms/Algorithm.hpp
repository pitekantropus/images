#pragma once

class Image;
enum class FileType;

class Algorithm
{
public:
    Algorithm() = default;
    virtual ~Algorithm() = default;

    virtual void apply(Image &image) const = 0;
};
