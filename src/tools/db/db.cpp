#include "db.hpp"
#include "sqlpp11/sqlpp11.h"
#include "sqlpp11/sqlite3/sqlite3.h"

#include "db_connection.h"

namespace {

sqlpp::sqlite3::connection_pool s_db_pool{};
thread_local db_connection s_dbc{s_db_pool};

}

struct Db::Context {
    
};

Db& Db::get()
{
    static Db s_db;
    return s_db;
}

bool Db::init(Db::Param const& param)
{
    constexpr size_t db_pool_capacity = 5;

    auto config = std::make_shared<sqlpp::sqlite3::connection_config>();
    config->debug = false;
    config->path_to_database = param.dbPath;
    config->flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_NOMUTEX;
    s_db_pool.initialize(config, db_pool_capacity);
    return true;
}

