#pragma once

#include "Algorithm.hpp"

#include <string>

class Negative : public Algorithm
{
public:
    Negative() = default;
    ~Negative() = default;

    void performAndSave(const std::string &srcPath, const std::string &destPath) const override;

private:
    void makeNegative(std::unique_ptr<Image> &image) const;
};
