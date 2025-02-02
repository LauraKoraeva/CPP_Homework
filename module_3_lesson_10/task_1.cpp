#include <iostream>    
#include <thread>        
#include <chrono>  
#include <mutex>
#include <sstream>
#include <map>
#include <iomanip>
#include <limits>
#include <numeric>

std::map<int, std::string> results;
std::mutex results_access;

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

void printResults(std::map<int, std::string> results)
{
    results_access.lock();
    std::cout << "\n**********RESULTS**********\n";
    std::cout << "Time\t" << std::setw(15) << "Name" << '\n';
    for (std::map<int, std::string>::iterator it = results.begin(); it != results.end(); ++it)
    {
        std::cout << std::setw(2) << std::setfill('0') << it->first << " s\t" << std::setw(15) << std::setfill(' ') << it->second << '\n';
    }
    std::cout << "\n***************************\n";
    results_access.unlock();
}

void race(std::string name, double speed)
{
    double distance = 0;
    int timer = 0;
    double distanceLeft = 100;
    while (distanceLeft > 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        timer += 1;
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
        std::cout << (std::stringstream() << "Timer: " << std::setw(2) << std::setfill('0') << timer << " s\tAthlete: "
            << std::setw(15) << std::setfill(' ') << name << "\tDistance: " << std::fixed << std::setprecision(1) << distance << '\n').str();
    }

    results_access.lock();
    results.emplace(std::pair<int, std::string>(timer, name));
    results_access.unlock();
}

void getInfo(std::string& name, double& speed)
{
    std::cout << "Enter athlete's name: ";
    std::getline(std::cin, name);
    std::cout << "Enter athlete's speed: ";
    do
    {
        std::cin >> speed;
    } while (!correctInput(speed));
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    std::map<std::string, double> athletes;
    std::string name;
    double speed;
    for (int i = 0; i < 6; ++i)
    {
        getInfo(name, speed);
        athletes.emplace(name, speed);
    }
    std::cout << std::endl;

    std::map<std::string, double>::iterator it = athletes.begin();
    std::thread lane_1(race, it->first, it->second);
    ++it;
    std::thread lane_2(race, it->first, it->second);
    ++it;
    std::thread lane_3(race, it->first, it->second);
    ++it;
    std::thread lane_4(race, it->first, it->second);
    ++it;
    std::thread lane_5(race, it->first, it->second);
    ++it;
    std::thread lane_6(race, it->first, it->second);

    lane_1.join();
    lane_2.join();
    lane_3.join();
    lane_4.join();
    lane_5.join();
    lane_6.join();

    printResults(results);

    return 0;
}


