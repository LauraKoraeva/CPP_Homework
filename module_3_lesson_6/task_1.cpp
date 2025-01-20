// Продвинутые темы и техники C++
// Урок 6. Работа с датами

// Задание 1. Реализация программы учёта времени

#include <iostream>
#include <ctime>
#include <map>
#include <string>
#include <limits>
#include <numeric>

enum Operations
{
    BEGIN_TASK = 1,
    END_TASK,
    SHOW_PROGRESS,
    EXIT,
};

struct Duration
{
    int hours;
    int minutes;
};

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

void end(int& startTime, int& finishTime, int& timeSpent, std::string& currentTask, std::map<std::string, Duration>& progress)
{
	if (currentTask != "break")
	{
		finishTime = std::time(nullptr);
        timeSpent = (finishTime - startTime) / 60;
        Duration duration;
        duration.minutes = timeSpent % 60;
        duration.hours = (timeSpent - duration.minutes) / 60;
		progress.insert(std::pair<std::string, Duration>(currentTask, duration));
	}
	currentTask = "break";
}

void begin(int& startTime, int& finishTime, int& timeSpent, std::string& currentTask, std::map<std::string, Duration>& progress)
{
	if (currentTask != "break")
        end(startTime, finishTime, timeSpent, currentTask, progress);
	
	std::cout << "Enter task: ";
	std::string task;
	std::getline(std::cin, task);
	currentTask = task;
	startTime = std::time(nullptr);
}

void status(std::string& currentTask, std::map<std::string, Duration>& progress)
{
	std::cout << "**************************\n";
	std::cout << "Completed tasks:\n";
	for (std::map<std::string, Duration>::iterator it = progress.begin();
		it != progress.end(); ++it)
    {
        std::cout << it->first << " (" << it->second.hours << "h " << it->second.minutes << "m)" << std::endl;
    }
	if (currentTask != "break")
		std::cout << "\nStill in progress: " << currentTask << '\n';
	std::cout << "**************************\n";
}

int main() 
{
	int startTime = 0;
	int finishTime = 0;
	int timeSpent = 0;
    std::string currentTask = "break";
	std::map<std::string, Duration> progress;
	
	int operation;
    do
    {
        std::cout << "Choose the operation:\n";
        std::cout << "1 - begin a new task\n";
        std::cout << "2 - end the current task\n";
        std::cout << "3 - show progress\n";
        std::cout << "4 - exit\n";
        do
        {
            std::cin >> operation;
        } while (!correctInput(operation));
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (operation == BEGIN_TASK)
            begin(startTime, finishTime, timeSpent, currentTask, progress);
        else if (operation == END_TASK)
            end(startTime, finishTime, timeSpent, currentTask, progress);
        else if (operation == SHOW_PROGRESS)
            status(currentTask, progress);
    } while (operation != EXIT);

    return 0;
}
