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

FolderFileProvider::~FolderFileProvider()
{
}

bool FolderFileProvider::setFolderPath(std::string const& folderPath)
{
    _ctx->folderPath = folderPath;
    return true;
}

bool FolderFileProvider::reset()
{
    _ctx->folderIterator = nullptr;
    return true;
}

bool FolderFileProvider::next()
{
    bool haveNextFlag = false;
    do {
        if (!fs::exists(_ctx->folderPath)) {
            xlog_err("not exist: {}", _ctx->folderPath);
            break;
        }

        if (!fs::is_directory(_ctx->folderPath)) {
            xlog_err("not directory: {}", _ctx->folderPath);
            break;
        }

        std::error_code err{};
        fs::directory_options options = fs::directory_options::skip_permission_denied;
        
        if (!_ctx->folderIterator) {
            _ctx->folderIterator = std::make_unique<fs::recursive_directory_iterator>(
                _ctx->folderPath,
                options, 
                err
            );
            if (err) {
                xlog_err("folder iterate failed: {}", err.message());
                break;
            }

            haveNextFlag = true;
            break;
        }

        _ctx->folderIterator->increment(err);

        if (err) {
            xlog_err("increment failed: {}", err.message());
            break;
        }
        if (*_ctx->folderIterator == fs::end(*_ctx->folderIterator)) {
            xlog_debug("end");
            break;
        }

        haveNextFlag = true;
    } while (false);

    if (!haveNextFlag) {
        _ctx->folderIterator = nullptr;
    }

    return haveNextFlag;
}

std::string FolderFileProvider::path()
{
    if (_ctx->folderIterator) {
        return (**(_ctx->folderIterator)).path();
    }
    return {};
}