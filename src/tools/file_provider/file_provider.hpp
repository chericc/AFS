#pragma once

/*

file source interface.

*/

class FileProviderInterface {
public:
    virtual ~FileProviderInterface() = default;
    virtual bool reset() = 0;
    virtual bool next() = 0;
    virtual std::string path() = 0;
};

class FolderFileProvider : public FileProviderInterface {
public:
    FolderFileProvider();
    ~FolderFileProvider() override;

    bool setFolderPath(std::string const& folderPath);
    bool reset() override;
    bool next() override;
    std::string path() override;
private:
    struct Context;
    std::unique_ptr<Context> _ctx = nullptr;
};