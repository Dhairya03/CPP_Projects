#ifndef MOCK_FILE_SYSTEM_COMPONENT_H
#define MOCK_FILE_SYSTEM_COMPONENT_H

#include <gmock/gmock.h>
#include "IFileSystemComponent.h"

class MockFileSystemComponent : public IFileSystemComponent
{
public:
    MOCK_METHOD(std::string, getName, (), (const));
    MOCK_METHOD(std::string, getType, (), (const));
};

#endif