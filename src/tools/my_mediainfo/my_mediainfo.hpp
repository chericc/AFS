#pragma once

#include "stdinc.hpp"

struct MyMediaInfoAttr {
    std::optional<int> width;
    std::optional<int> height;
};

class MyMediaInfo {
public:
    MyMediaInfo(std::string const& file);
    ~MyMediaInfo() = default;

    bool parse();

    MyMediaInfoAttr const& attr() const;
private:
    struct Context;
    std::shared_ptr<Context> ctx_;
};
