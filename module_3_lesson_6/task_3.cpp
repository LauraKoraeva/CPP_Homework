#include <iostream>
#include <ctime>
#include <iomanip>

int main()
{
    std::cout << "Set the timer [MM:SS]: ";
    std::tm timer;
    std::cin >> std::get_time(&timer, "%M:%S");
    std::time_t currentTime = std::time(nullptr);
    std::time_t targetTime = currentTime + timer.tm_min * 60 + timer.tm_sec;

    while (currentTime != targetTime)                          
    {
        std::time_t diff = targetTime - currentTime;
        currentTime = std::time(nullptr);             
        if (currentTime + diff != targetTime)      
        {
            diff = targetTime - currentTime;
            int minutes = diff / 60;
            int seconds = diff % 60;
            std::cout << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << '\n';
        }
    }
    std::cout << "DING! DING! DING!\n";

    return 0;
}