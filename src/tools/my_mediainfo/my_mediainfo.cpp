#include "my_mediainfo.hpp"

#include "MediaInfo/MediaInfo.h"
#include "log.hpp"

struct MyMediaInfo::Context {
    MediaInfoLib::String file;
    std::shared_ptr<MyMediaInfoAttr> attr;
};

MyMediaInfo::MyMediaInfo(std::string const& file)
{
    ctx_ = std::make_shared<Context>();
    ctx_->file = file;
}

bool MyMediaInfo::parse()
{
    bool okFlag = false;
    do {
        MediaInfoLib::MediaInfo mi{};
        if (0 == mi.Open(ctx_->file)) {
            xlog_err("open failed");
            break;
        }
        
        // mi.
        auto inform = mi.Inform();
        xlog_debug("info: {}", inform);

        okFlag = true;
    } while (false);
    return true;
}

MyMediaInfoAttr const& MyMediaInfo::attr() const
{
    return *ctx_->attr;
}

