#include "log.hpp"

int main()
{
    log_init_def();

    xlog_debug("hello");
    return 0;
}