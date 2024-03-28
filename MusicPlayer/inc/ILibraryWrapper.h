#ifndef I_LIBRARY_WRAPPER_H
#define I_LIBRARY_WRAPPER_H

#include <SFML/Audio.hpp>
#include <string>

class ILibraryWrapper
{
public:
    virtual bool openFromFile(const std::string& filename)=0;
    virtual bool play() = 0;
    virtual bool pause() = 0;
    virtual bool stop() = 0;
};

#endif
