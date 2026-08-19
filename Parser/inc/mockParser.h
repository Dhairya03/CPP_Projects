#ifndef MOCK_PARSER_H
#define MOCK_PARSER_H

#include "IParser.h"
#include <gmock/gmock.h>

class MockParser:public IParser{
    public:
        MOCK_METHOD(bool,openFile,(),(override));
        MOCK_METHOD(bool,parseFile,(),(override));
        MOCK_METHOD(void,printFileData,(),(override));
        MOCK_METHOD(bool,closeFile,(),(override));
};

#endif