#pragma once

#include "Algorithm.hpp"

#include <string>

class Negative : public Algorithm
{
public:
    Negative();
    ~Negative();

    bool performAndSave(const std::string &srcPath, const std::string &destPath) override;
};
