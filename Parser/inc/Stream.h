#ifndef STREAM_H
#define STREAM_H

#include "IStream.h"
#include "fstream"

class Stream : public IStream
{
protected:
    std::ifstream &file;

public:
    Stream(std::ifstream &);

    void open(const char *);

    bool is_open();

    void close();

    ~Stream();
};

#endif