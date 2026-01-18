#include "log.hpp"

int main()
{
    log_init_def();

    XLOG_DEBUG("hello");
    return 0;
}