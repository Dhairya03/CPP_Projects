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
    bool openFromFile(const std::string &filename);
    bool play();
    bool pause();
    bool stop();
};

#endif 
