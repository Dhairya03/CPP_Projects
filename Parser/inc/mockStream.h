#ifndef MOCK_STREAM_H
#define MOCK_STREAM_H

#include "IStream.h"
#include <gmock/gmock.h>

class MockStream:public IStream{
    public:
    MOCK_METHOD(void, open,(const char *),(override));
    MOCK_METHOD(bool, is_open,(),(override));
    MOCK_METHOD(void, close,(),(override));
};

#endif