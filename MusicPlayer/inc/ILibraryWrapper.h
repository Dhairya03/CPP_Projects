#ifndef I_LIBRARY_WRAPPER_H
#define I_LIBRARY_WRAPPER_H

#include <SFML/Audio.hpp>
#include <string>

class ILibraryWrapper
{
public:
    // ILibraryWrapper();
    virtual bool getStatus()=0;
    virtual bool openFromFile(const std::string& filename)=0;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    // virtual ~ILibraryWrapper();
};

#endif
