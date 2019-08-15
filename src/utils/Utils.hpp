#pragma once

#include <unordered_set>
#include <string>
#include <vector>

const std::unordered_set<std::string> commands = {"negative",
                                                  "shade_scale",
                                                  "mask"};

struct Item
{
    std::string key;
    std::string value;

    bool operator==(Item rhs) const
    {
        return key == rhs.key && value == rhs.value;
    }
};

Item split(const std::string &str, char delimiter)
{
    size_t pos = str.find(delimiter);
    return {str.substr(0, pos), str.substr(++pos)};
}

std::vector<Item> tokenize(std::vector<std::string> args)
{
    std::vector<Item> result;
    for(const auto &arg : std::move(args))
    {
        result.push_back(split(arg, '='));
    }
    return result;
}
