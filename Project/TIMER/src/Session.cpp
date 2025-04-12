#include "Session.h"

Session::Session(std::string inTaskDescription, int inDurationMinutes) : 
    taskDescription(inTaskDescription), durationMinutes(inDurationMinutes) { }

Session::Session(std::string inTaskDescription, int inDurationMinutes, std::chrono::system_clock::time_point inStartTime, std::chrono::system_clock::time_point inFinishTime) : 
    taskDescription(inTaskDescription), durationMinutes(inDurationMinutes),
    sessionStartTime(inStartTime), sessionFinishTime(inFinishTime) { }



Session& Session::operator=(const Session& other) 
{
        
        if (this == &other) 
        {
            return *this;
        }

        taskDescription = other.taskDescription;
        durationMinutes = other.durationMinutes;
        sessionStartTime = other.sessionStartTime;
        sessionFinishTime = other.sessionFinishTime;

        return *this;
    }





