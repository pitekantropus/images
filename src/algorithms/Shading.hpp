#pragma once

#include <algorithms/Algorithm.hpp>

#include <string>

class Shading : public Algorithm
{
public:
    Shading() = default;
    ~Shading() = default;

    void performAndSave(const std::string &srcPath, const std::string &destPath) const override;

private:
    void makeShadeScale(std::unique_ptr<Image> &image) const;
};
