#ifndef SONG_H
#define SONG_H

#include <string>

class Song
{
private:
    std::string title;

public:
    Song(std::string _title);
    std::string getTitle() const;
};

#endif 
