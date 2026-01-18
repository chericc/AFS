#pragma once

/*

file source interface.

*/

class FileProviderInterface {
public:
    virtual bool reset() = 0;
    virtual bool next() = 0;
    virtual std::string path() = 0;
};

class FileProvider : public FileProviderInterface {
public:
    bool reset() override;
    bool next() override;
    std::string path() override;
};