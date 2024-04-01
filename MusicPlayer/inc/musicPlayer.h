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
    std::vector<Playlist> playlists;
    ILibraryWrapper &music;
    Playlist *currentPlaylist = nullptr;
    int currentSongIndex;
    bool isPlaying = false;

    bool getIsPlaying();
    void savePlaylistsToFile(const std::vector<Playlist> &playlists);
    void loadPlaylistsFromFile(std::vector<Playlist> &playlists);
    void loadSongsFromFile(std::vector<Song> &allSongs);
    bool playSong(const Song &songFile);

public:
    std::vector<Song> allSongs;

    MusicPlayer(ILibraryWrapper &);
    bool togglePause();
    bool stop();
    bool replay();
    bool playNextSong();
    bool playPreviousSong();
    void showPlaylist();
    bool playPlaylist(int);
    bool createPlaylist(std::string name, std::vector<Song> &);
    bool deletePlaylist(int);
    bool updatePlaylist(int, int);
};

#endif
