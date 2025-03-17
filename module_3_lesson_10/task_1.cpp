// Продвинутые темы и техники C++
// Урок 10. Введение в многопоточность

// Задание 1. Заплыв на 100 метров

#include <iostream>    
#include <thread>        
#include <chrono>  
#include <mutex>
#include <sstream>
#include <map>
#include <iomanip>
#include <limits>
#include <numeric>
#include <vector>

std::multimap<int, std::string> results;
std::mutex results_access;

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

void printResults(std::multimap<int, std::string> results)
{
    results_access.lock();
    std::cout << "\n**********RESULTS**********\n";
    std::cout << "Time\t" << std::setw(15) << "Name" << '\n';
    for (std::multimap<int, std::string>::iterator it = results.begin(); it != results.end(); ++it)
    {
        std::cout << std::setw(2) << std::setfill('0') << it->first << " s\t" << std::setw(15) << std::setfill(' ') << it->second << '\n';
    }
    std::cout << "\n***************************\n";
    results_access.unlock();
}

void recordResults(int& time, std::string& name)
{
    results_access.lock();
    results.emplace(std::pair<int, std::string>(time, name));
    results_access.unlock();
}

void race(std::string name, double speed)
{
    double distance = 0;
    int time = 0;
    double distanceLeft = 100;
    while (distanceLeft > 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        time += 1;
        if (distanceLeft < speed)
        {
            distance += distanceLeft;
            distanceLeft -= distanceLeft;
        }
        else
        {
            distance += speed;
            distanceLeft -= speed;
        }
        std::cout << (std::stringstream() << "Timer: " << std::setw(2) << std::setfill('0') << time << " s\tAthlete: "
            << std::setw(15) << std::setfill(' ') << name << "\tDistance: " << std::fixed << std::setprecision(1) << distance << '\n').str();
    }

    recordResults(time, name);
}

void getInfo(std::string& name, double& speed)
{
    std::cout << "Enter athlete's name: ";
    std::getline(std::cin, name);
    do
    {
        std::cout << "Enter athlete's speed: ";
        std::cin >> speed;
    } while (!correctInput(speed));
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    std::multimap<std::string, double> athletes;
    std::string name;
    double speed;
    for (int i = 0; i < 6; ++i)
    {
        getInfo(name, speed);
        athletes.emplace(name, speed);
    }
    std::cout << std::endl;

    std::vector<std::thread> lanes;
    std::multimap<std::string, double>::iterator it = athletes.begin();
    for (int i = 0; i < 6; ++i)
    {
        lanes.emplace_back(race, it->first, it->second);
        ++it;
    }

    for (auto& l : lanes)
    {
        l.join();
    }

    printResults(results);

    return 0;
}





