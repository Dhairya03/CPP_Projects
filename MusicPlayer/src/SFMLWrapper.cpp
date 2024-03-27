#include "SFMLWrapper.h"

SFMLWrapper::SFMLWrapper() {}

bool SFMLWrapper::getStatus(){
    return music.getStatus();
}

bool SFMLWrapper::openFromFile(const std::string &filename)
{
    return music.openFromFile(filename);
}

void SFMLWrapper::play()
{
    music.play();
}

void SFMLWrapper::pause()
{
    music.pause();
}

void SFMLWrapper::stop()
{
    music.stop();
}
