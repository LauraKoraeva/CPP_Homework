// Продвинутые темы и техники C++
// Урок 8. Введение в ООП. Часть 1

// Задание 1. Реализация имитации аудиоплеера

#include <iostream> 
#include <ctime> 
#include <iomanip> 
#include <map> 
#include <sstream>
#include <limits>
#include <numeric>
#include <string>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

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

    void showMenu()
    {
        std::cout << "\n-------MENU--------\n";
        std::cout << "1 - Play\n";
        std::cout << "2 - Pause\n";
        std::cout << "3 - Stop\n";
        std::cout << "4 - Next\n";
        std::cout << "5 - Add a new track\n";
        std::cout << "6 - Show menu\n";
        std::cout << "7 - Exit\n";
        std::cout << "-------------------\n\n";
    }

    void addNewTrack()
    {
        Track song;
        std::cout << "Title: ";
        std::getline(std::cin, song.title);
        std::istringstream ss("");
        do
        {
            std::cout << "Release date [YYYY/MM/DD]: ";
            std::string inputDate;
            std::cin >> inputDate;
            std::istringstream ss(inputDate);
            ss >> std::get_time(&song.releaseDate, "%Y/%m/%d");
            if (ss.fail() || song.releaseDate.tm_year < 0 || song.releaseDate.tm_mday == 0)
            {
                std::cerr << "Incorrect input" << std::endl;
            }
        } while (ss.fail() || song.releaseDate.tm_year < 0 || song.releaseDate.tm_mday == 0);
        do
        {
            std::cout << "Length: ";
            std::cin >> song.length;
        } while (!correctInput(song.length));
        int number = trackList.size() + 1;
        trackList[number] = song;
    }

    void addPlaylist()
    {
        Track song_1;
        song_1.title = "Set Fire to the Rain";
        std::string d = "2011/07/04";
        std::istringstream ss_1(d);
        ss_1 >> std::get_time(&song_1.releaseDate, "%Y/%m/%d");
        song_1.length = 242;
        trackList[1] = song_1;

        Track song_2;
        song_2.title = "Chandelier";
        d = "2014/03/17";
        std::istringstream ss_2(d);
        ss_2 >> std::get_time(&song_2.releaseDate, "%Y/%m/%d");
        song_2.length = 216;
        trackList[2] = song_2;

        Track song_3;
        song_3.title = "Only Love Can Hurt Like This";
        d = "2014/05/11";
        std::istringstream ss_3(d);
        ss_3 >> std::get_time(&song_3.releaseDate, "%Y/%m/%d");
        song_3.length = 232;
        trackList[3] = song_3;

        Track song_4;
        song_4.title = "Just Like Fire";
        d = "2016/04/15";
        std::istringstream ss_4(d);
        ss_4 >> std::get_time(&song_4.releaseDate, "%Y/%m/%d");
        song_4.length = 215;
        trackList[4] = song_4;

        Track song_5;
        song_5.title = "Flowers";
        d = "2023/01/12";
        std::istringstream ss_5(d);
        ss_5 >> std::get_time(&song_5.releaseDate, "%Y/%m/%d");
        song_5.length = 200;
        trackList[5] = song_5;
    }

    void printTrackList()
    {
        std::cout << "\n------------PLAYLIST-------------\n";
        for (std::map<int, Track>::iterator it = trackList.begin(); it != trackList.end(); ++it)
        {
            std::cout << std::setw(2) << std::setfill('0') << it->first << " - " << it->second.title << '\n';
        }
        std::cout << "---------------------------------\n\n";
    }

    void printDetails()
    {
        std::cout << "\n***********************************\n";
        std::cout << "**************PLAYING**************\n";
        std::cout << "***********************************\n";
        std::map<int, Track>::iterator it = trackList.find(chosenSong);
        std::cout << "Title: " << it->second.title << '\n';
        std::cout << "Released: " << it->second.releaseDate.tm_year + 1900 << "/" << std::setw(2)
            << std::setfill('0') << it->second.releaseDate.tm_mon + 1 << "/" << it->second.releaseDate.tm_mday << '\n';
        std::cout << "Length: " << it->second.length << '\n';
        std::cout << "***********************************\n";
        std::cout << "***********************************\n\n";
    }

    void play(Player& session)
    {
        if (status != PLAYING)
        {
            session.printTrackList();
            do
            {
                std::cout << "Choose a song: ";
                std::cin >> chosenSong;
            } while (!correctInput(chosenSong));
            status = PLAYING;
            printDetails();
        }
    }

    void pause()
    {
        if (status != PAUSED && status != STOPPED)
        {
            std::cout << "\n***********************************\n";
            std::cout << "**************PAUSED***************\n";
            std::cout << "***********************************\n\n";
            status = PAUSED;
        }
    }

    void next()
    {
        int nextSong;
        do
        {
            std::srand(std::time(nullptr));
            nextSong = rand() % trackList.size() + 1;
        } while (nextSong == chosenSong);
        chosenSong = nextSong;
        status = PLAYING;
        printDetails();
    }

    void stop()
    {
        if (status != STOPPED)
        {
            std::cout << "\n***********************************\n";
            std::cout << "**************STOPPED**************\n";
            std::cout << "***********************************\n\n";
            status = STOPPED;
        }
    }
};

int main()
{
    Player session;
    session.addPlaylist();
    session.showMenu();

    int operation;
    while (true)
    {
        do
        {
            std::cout << "Choose the operation: ";
            std::cin >> operation;
        } while (!correctInput(operation));
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (operation)
        {
        case session.PLAY:
            session.play(session);
            break;
        case session.PAUSE:
            session.pause();
            break;
        case session.STOP:
            session.stop();
            break;
        case session.NEXT:
            session.next();
            break;
        case session.ADD_NEW_TRACK:
            session.addNewTrack();
            break;
        case session.SHOW_MENU:
            session.showMenu();
            break;
        case session.EXIT:
            return 0;
        default:
            std::cout << "No such operation.\n";
        }
    }
}