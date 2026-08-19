#ifndef MOCK_FILE_H
#define MOCK_FILE_H

#include <gmock/gmock.h>
#include "IFile.h"

class MockFile : public IFile
{
public:
    MockFile(const std::string &name) : IFile(name) {}
    MOCK_METHOD(std::string, getName, (), (const));
    MOCK_METHOD(std::string, getType, (), (const));
    MOCK_METHOD(std::string, getContent, (), (const));
    MOCK_METHOD(void, setContent, (const std::string), (override));
    MOCK_METHOD(std::shared_ptr<IDirectory>, getParent, (), (override));
};

#endif