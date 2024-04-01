#ifndef I_MUSICPLAYER_H
#define I_MUSICPLAYER_H

#include <vector>
#include "playlist.h"
#include "song.h"
#include <SFML/Audio.hpp>
#include "ILibraryWrapper.h"
#include "constants.h"

class IMusicPlayer
{
public:
    virtual bool getIsPlaying() = 0;
    virtual bool togglePause() = 0;
    virtual bool stop() = 0;
    virtual bool replay() = 0;
    virtual bool playNextSong() = 0;
    virtual bool playPreviousSong() = 0;
    virtual bool playPlaylist(int) = 0;
    virtual bool createPlaylist(std::string name, std::vector<Song> &) = 0;
    virtual bool deletePlaylist(int) = 0;
    virtual bool updatePlaylist(int, int) = 0;
};

#endif
