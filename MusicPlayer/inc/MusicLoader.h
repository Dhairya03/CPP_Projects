#ifndef MUSIC_LOADER_H
#define MUSIC_LOADER_H

#include "IPlaylist.h"
#include "ISong.h"

class MusicLoader
{
public:
    std::vector<IPlaylist *> &loadPlaylistsFromFile(std::vector<IPlaylist *> &playlists);
    std::vector<ISong *> &loadSongsFromFile(std::vector<ISong *> &allSongs);
};

#endif