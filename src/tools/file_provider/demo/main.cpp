#include "file_provider.hpp"
#include "log.hpp"

int main(int argc, char *argv[])
{
    log_init_def();

    if (argc < 2) {
        xlog_err("Usage: {} [path]", argv[0]);
        return -1;
    }

    auto fileProvider = std::make_shared<FolderFileProvider>();
    fileProvider->setFolderPath(argv[1]);

    while (fileProvider->next()) {
        auto path = fileProvider->path();
        xlog_debug("path: {}", path);
    }

    return 0;
}