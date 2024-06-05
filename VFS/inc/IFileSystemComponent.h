#ifndef I_FILE_SYSTEM_COMPONENT_H
#define I_FILE_SYSTEM_COMPONENT_H

#include <iostream>

class IFileSystemComponent
{
public:
    virtual std::string getName() const = 0;
    virtual std::string getPath() const = 0;
};
#endif