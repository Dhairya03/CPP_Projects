#include "song.h"

Song::Song(std::string _title) : title(_title) {}

std::string Song::getTitle() const {
    return title;
}
