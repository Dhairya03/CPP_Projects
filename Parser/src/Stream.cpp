#include "Stream.h"
#include <iostream>

Stream::Stream(std::ifstream &file) : file(file) {}

void Stream::open(const char *fileName)
{
    std::cout<<"open"<<std::endl;
    file.open(fileName);
}

bool Stream::is_open()
{
    std::cout<<"isopen"<<std::endl;
    return file.is_open();
}

void Stream::close(){
    std::cout<<"close"<<std::endl;
    file.close();
}

Stream::~Stream(){}