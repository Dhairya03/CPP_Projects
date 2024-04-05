#include "song.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class SongTest : public ::testing::Test
{

public:
    std::string title = "/home/dhairyagupta/songs/guitar.wav";
    Song *song;
    void SetUp()
    {
        song = new Song(title);
    }
    void TearDown()
    {
        delete song;
    }
};

TEST_F(SongTest, WhenGetTitleisCalled_ThenItIsSameAsTitle)
{
    EXPECT_EQ(song->getTitle(), title);
}
