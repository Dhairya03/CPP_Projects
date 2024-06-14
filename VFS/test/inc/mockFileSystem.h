#ifndef MOCK_FILE_SYSTEM_H
#define MOCK_FILE_SYSTEM_H

#include <gmock/gmock.h>
#include <IFileSystem.h>

class MockFileSystem : public IFileSystem
{
public:
    MOCK_METHOD(std::shared_ptr<IDirectory>, getCurrentDirectory, (), (const));
    MOCK_METHOD(void, setCurrentDirectory, (std::shared_ptr<IDirectory>), (override));
    MOCK_METHOD(void, setCommand, (const std::string &, const std::string &, const std::string &), (override));
    MOCK_METHOD(std::string, executeCommand, (), (override));
};

#endif