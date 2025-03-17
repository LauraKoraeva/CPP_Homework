// Продвинутые темы и техники C++
// Урок 10. Введение в многопоточность

// Задание 2. Симуляция работы вокзала

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <numeric>

std::mutex stationAccess;
std::condition_variable stationCV;
std::queue<std::string> stationQueue;
bool stationOccupied = false;

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input <= 0)
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

void trainArrival(const std::string& trainName, const int& travelTime) 
{
    std::this_thread::sleep_for(std::chrono::seconds(travelTime));

    {
        std::unique_lock<std::mutex> lock(stationAccess);
        stationQueue.push(trainName);

        if (stationOccupied) 
        {
            std::cout << "\nTrain " << trainName << " is waiting.\n";
            stationCV.wait(lock, [&] { return stationQueue.front() == trainName && !stationOccupied; });
        }

        stationOccupied = true;
        std::cout << "\nTrain " << trainName << " arrived at the station.\n";
    } 

    std::string command;
    while (true) 
    {
        std::cout << "Enter 'depart' to leave the station.\n";
        std::cin >> command;
        if (command == "depart") 
        {
            break;
        }
        else 
        {
            std::cout << trainName << "Incorrect input.\n";
        }
    }

    {
        std::unique_lock<std::mutex> lock(stationAccess);
        std::cout << "\nTrain " << trainName << " left the station.\n";
        stationOccupied = false;
        stationQueue.pop(); 
        stationCV.notify_one(); 
    }
}

int main() 
{
    std::vector<std::string> trainNames = { "A", "B", "C" };
    std::vector<int> travelTimes(3);

    for (size_t i = 0; i < trainNames.size(); ++i) 
    {
        do
        {
            std::cout << "Enter travelling time for Train " << trainNames[i] << " (in seconds): ";
            std::cin >> travelTimes[i];
        } while (!correctInput(travelTimes[i]));  
    }

    std::vector<std::thread> trains;
    for (size_t i = 0; i < trainNames.size(); ++i) 
    {
        trains.emplace_back(trainArrival, trainNames[i], travelTimes[i]);
    }

    for (auto& train : trains) 
    {
        train.join();
    }

    std::cout << "\nAll the trains left the station.\n";

    return 0;
}