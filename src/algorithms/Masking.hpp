#pragma once

#include <algorithms/Algorithm.hpp>

#include <string>

using PixelMask = std::vector<std::vector<int>>;

class Masking : public Algorithm
{
public:
    Masking(PixelMask mask);
    ~Masking() = default;

    void performAndSave(const std::string &srcPath, const std::string &destPath) const override;

private:
    PixelMask _mask;
    uint32_t _width;
    uint32_t _height;
    int _sum;

    void applyMask(std::unique_ptr<Image> &image) const;
};
