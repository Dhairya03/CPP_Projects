#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <vector>
#include "playlist.h"
#include "song.h"
#include <SFML/Audio.hpp>
#include "ILibraryWrapper.h"
#include "IMusicPlayer.h"
#include "constants.h"

class MusicPlayer : public IMusicPlayer
{
private:
    std::vector<IPlaylist *> playlists;
    ILibraryWrapper &music;
    // IPlaylist *playlist;
    // ISong *song;
    IPlaylist *currentPlaylist = nullptr;
    int currentSongIndex=-1;
    bool isPlaying = false;

    void savePlaylistsToFile(const std::vector<IPlaylist *> &playlists);
    // void loadPlaylistsFromFile(std::vector<IPlaylist *> &playlists);
    // void loadSongsFromFile(std::vector<ISong *> &allSongs);

public:
    std::vector<ISong *> allSongs;

    MusicPlayer(ILibraryWrapper &, std::vector<IPlaylist *> &, std::vector<ISong *> &);
    bool playSong(const ISong *songFile);
    bool togglePause();
    bool stop();
    bool replay();
    bool playNextSong();
    bool playPreviousSong();
    void showPlaylist();
    bool playPlaylist(int);
    bool createPlaylist(std::string name, std::vector<ISong *> &);
    bool deletePlaylist(int);
    bool updatePlaylist(int, int);
};

#endif
