#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <sstream>
#include <map>
#include <limits>
#include <numeric>

bool correctInputInt(int input)
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

bool correctInputChar(char input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input != 'd')
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

std::vector<char> station;
std::map<int, char> queue;
std::mutex station_access;

void travelling(char name, int time)
{
    std::this_thread::sleep_for(std::chrono::seconds(time));
    if (!station.empty())
    {
        std::cout << (std::stringstream() << "\nTrain " << name << " is waiting\n").str();
        queue.emplace(queue.size() + 1, name);                                               // ADD MUTEX
    }
    while (true)
        if (queue.empty() || queue.begin()->second == name)
        {
            if (station_access.try_lock())
            {
                std::cout << (std::stringstream() << "\nTrain " << name << " has arrived at the station.\n").str();
                station.push_back(name);
                std::cout << "Press <d> to depart. \n";
                char command;
                do
                {
                    std::cin >> command;
                } while (!correctInputChar(command));
                if (command == 'd')
                {
                    station.pop_back();
                    std::cout << (std::stringstream() << "\nTrain " << name << " has left the station\n").str();
                }
                if (queue.begin()->second == name)
                {
                    queue.erase(queue.begin());
                }
                station_access.unlock();
                break;
            }
        }       
}
    
int main()
{
    char train_1('A'), train_2('B'), train_3('C');
    double time_A, time_B, time_C;
    std::cout << "Enter travelling time for Train " << train_1 << ": ";
    do
    {
        std::cin >> time_A; 
    } while (!correctInputInt(time_A));
    std::cout << "Enter travelling time for Train " << train_2 << ": ";
    do
    {
        std::cin >> time_B; 
    } while (!correctInputInt(time_B));
    std::cout << "Enter travelling time for Train " << train_3 << ": ";
    do
    {
        std::cin >> time_C; 
    } while (!correctInputInt(time_C));

    std::thread departure_1(travelling, train_1, time_A);
    std::thread departure_2(travelling, train_2, time_B);
    std::thread departure_3(travelling, train_3, time_C);
    departure_1.join();
    departure_2.join();
    departure_3.join();

    return 0;
}