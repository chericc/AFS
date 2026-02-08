#include "db.hpp"

struct Db::Context {
    
};

Db& Db::get()
{
    static Db s_db;
    return s_db;
}

bool Db::init(Db::Param const& param)
{
    return true;
}