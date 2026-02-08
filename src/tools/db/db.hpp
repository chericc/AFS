#pragma once

#include "stdinc.hpp"

class Db {
public:
    static Db &get();

    struct Param {
        std::string dbPath;
    };
    bool init(Param const& param);

    ~Db();
private:
    explicit Db();

    struct Context;

};