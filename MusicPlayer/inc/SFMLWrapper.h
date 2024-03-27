#ifndef SFML_WRAPPER_H
#define SFML_WRAPPER_H

#include <SFML/Audio.hpp>
#include <string>
#include "ILibraryWrapper.h"

class SFMLWrapper : public ILibraryWrapper
{
private:
    sf::Music music;

public:
    SFMLWrapper();
    bool getStatus();
    bool openFromFile(const std::string &filename);
    void play();
    void pause();
    void stop();
};

#endif // SFML_WRAPPER_H
