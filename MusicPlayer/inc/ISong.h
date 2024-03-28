#ifndef I_SONG_H
#define I_SONG_H

#include <string>

class ISong
{
public:
    virtual std::string getTitle() const = 0;
};

#endif
