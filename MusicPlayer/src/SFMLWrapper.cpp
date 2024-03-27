#include "SFMLWrapper.h"

SFMLWrapper::SFMLWrapper() {}

bool SFMLWrapper::openFromFile(const std::string &filename)
{
    bool isOpen = music.openFromFile(filename);
    return isOpen;
}

bool SFMLWrapper::play()
{
    bool isPlayed=false;
    music.play();
    isPlayed=true;
    return isPlayed;
}

bool SFMLWrapper::pause()
{
    bool isPaused=false;
    music.pause();
    isPaused=true;
    return isPaused;
}

bool SFMLWrapper::stop()
{
    bool isStopped=false;
    music.stop();
    isStopped=true;
    return isStopped;
}
