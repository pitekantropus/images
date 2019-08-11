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
    PixelMask mask;
    uint32_t width;
    uint32_t height;
    int sum;

    void applyMask(std::unique_ptr<Image> &image) const;
};
