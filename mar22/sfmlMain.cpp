#include <SFML/Audio.hpp>
#include <filesystem>
#include <iostream>

void pause(){
    while(true){}
}
int play(){
    sf::Music music;
    if (!music.openFromFile("/home/dhairyagupta/Downloads/song.wav"))
    {
        return -1; // error
    }
    std::cout << "Music is about to play" << std::endl;
    music.play();
    pause();
}

int main()
{
    play();
    // music.play();

    while(true){}

    std::cout << "music is plyed" << std::endl;

    // music.play();

    // advance to 2 seconds
    // music.setPlayingOffset(sf::seconds(2.f));

    // pause playback
    // music.pause();

    // resume playback
    // music.play();

    // stop playback and rewind
    // music.stop();
    return 0;
}