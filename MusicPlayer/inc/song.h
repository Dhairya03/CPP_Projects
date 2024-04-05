#ifndef SONG_H
#define SONG_H

#include <string>
#include "ISong.h"

class Song : public ISong
{
private:
    std::string title;

public:
    Song();
    Song(std::string _title);
    std::string getTitle() const;
};

#endif
