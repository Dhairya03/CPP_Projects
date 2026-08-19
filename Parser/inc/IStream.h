#ifndef I_STREAM_H
#define I_STREAM_H

#include <fstream>

class IStream : public std::ifstream
{
public:
    IStream();

    virtual void open(const char *) = 0;

    virtual bool is_open() = 0;

    virtual void close()=0;

    ~IStream();
};

#endif