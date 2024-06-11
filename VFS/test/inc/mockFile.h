#ifndef MOCK_FILE_H
#define MOCK_FILE_H

#include <gmock/gmock.h>
#include <IFile.h>

class MockFile : public IFile
{
public:
    MOCK_METHOD(std::string, getContent, (), (const));
    MOCK_METHOD(void, setContent, (const std::string), (override));
};

#endif