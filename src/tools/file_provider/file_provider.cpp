#include "file_provider.hpp"
#include "log.hpp"

namespace {

namespace fs = std::filesystem;

}

struct FolderFileProvider::Context {
    std::string folderPath;
    std::unique_ptr<fs::recursive_directory_iterator> folderIterator;
};

FolderFileProvider::FolderFileProvider()
{
    _ctx = std::make_unique<Context>();
}

bool FolderFileProvider::setFolderPath(std::string const& folderPath)
{
    _ctx->folderPath = folderPath;
    return true;
}

bool FolderFileProvider::reset()
{
    _ctx->folderPath.clear();
    return true;
}

bool FolderFileProvider::next()
{
    bool haveNextFlag = false;
    do {
        if (!fs::exists(_ctx->folderPath)) {
            XLOG_DEBUG("not exist: {}", _ctx->folderPath);
        }
    } while (false);
    return true;
}

std::string FolderFileProvider::path()
{
    
}