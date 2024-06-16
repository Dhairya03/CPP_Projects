#ifndef MOCK_DIRECTORY_H
#define MOCK_DIRECTORY_H

#include <gmock/gmock.h>
#include "IDirectory.h"

class MockDirectory : public IDirectory
{
public:
    MockDirectory(const std::string &name) : IDirectory(name) {}
    MOCK_METHOD(std::string, getName, (), (const));
    MOCK_METHOD(std::string, getType, (), (const));
    MOCK_METHOD(void, addComponent, (std::shared_ptr<IFileSystemComponent>), (override));
    MOCK_METHOD(void, removeComponent, (std::shared_ptr<IFileSystemComponent>), (override));
    MOCK_METHOD(std::shared_ptr<IFileSystemComponent>, findComponent, (const std::string &), (override));
    MOCK_METHOD(std::vector<std::shared_ptr<IFileSystemComponent>>, listComponents, (), (const));
    MOCK_METHOD(std::shared_ptr<IDirectory>, getParent, (), (override));
};

#endif