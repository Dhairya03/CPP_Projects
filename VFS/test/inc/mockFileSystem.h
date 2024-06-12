#ifndef MOCK_FILE_SYSTEM_H
#define MOCK_FILE_SYSTEM_H

#include <gmock/gmock.h>
#include <IFileSystem.h>

class MockFileSystem : public IFileSystem
{
public:
    MOCK_METHOD(std::shared_ptr<Directory>, getCurrentDIrectory, (), (const));
    MOCK_METHOD(void, setCurrentDirectory, (std::shared_ptr<Directory>), (override));
    MOCK_METHOD(void, setCommand, (const std::string &), (override));
    MOCK_METHOD(void, executeCommand, (), (override));
}
#endif