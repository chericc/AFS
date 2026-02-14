#include "my_mediainfo.hpp"
#include "log.hpp"

void printUsage(int argc, char *argv[])
{
    xlog_debug("Usage: {} [file]", argv[0]);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printUsage(argc, argv);
        exit(EXIT_FAILURE);
        return 0;
    }

    std::string filename = argv[1];

    MyMediaInfo info{filename};
    info.parse();
    return 0;
}
