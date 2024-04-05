#ifndef MOCK_LIBRARY_WRAPPER_H
#define MOCK_LIBRARY_WRAPPER_H

#include "ILibraryWrapper.h"
#include <gmock/gmock.h>

class MockLibraryWrapper : public ILibraryWrapper
{
public:
    MOCK_METHOD(bool, openFromFile, (const std::string &), (override));
    MOCK_METHOD(bool, play, (), (override));
    MOCK_METHOD(bool, pause, (), (override));
    MOCK_METHOD(bool, stop, (), (override));
};

#endif