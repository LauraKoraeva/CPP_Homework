#pragma once

class Player
{
private:
    struct Track
    {
        std::string title = { "" };
        std::tm releaseDate = {};
        int length = 0;
    };

    std::map<int, Track> trackList;

    enum Status
    {
        PLAYING = 1,
        PAUSED,
        STOPPED,
    };

    int status = STOPPED;
    int chosenSong;

public:
    enum Operation
    {
        PLAY = 1,
        PAUSE,
        STOP,
        NEXT,
        ADD_NEW_TRACK,
        SHOW_MENU,
        EXIT,
    };

    void showMenu();

    void addNewTrack();

    void addPlaylist();

    void printTrackList();

    void printDetails();

    void play(Player& session);

    void pause();

    void next();

    void stop();
};