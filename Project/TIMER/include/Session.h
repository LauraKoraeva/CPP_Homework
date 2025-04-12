#pragma once
#include <chrono>
#include <string>

class Session
{
public: // /////////////////
    std::string taskDescription;
    std::chrono::system_clock::time_point sessionStartTime;
    std::chrono::system_clock::time_point sessionFinishTime;
    int durationMinutes;

public:
    Session() { }
    Session(std::string inTaskDescription, int inDurationMinutes);

    Session(std::string inTaskDescription, int inDurationMinutes, std::chrono::system_clock::time_point inStartTime, std::chrono::system_clock::time_point inFinishTime);

    Session& operator=(const Session& other);

    
};