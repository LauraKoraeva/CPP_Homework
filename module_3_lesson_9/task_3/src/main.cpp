#include <iostream>
#include <string>
#include <limits>
#include <numeric>
#include "ChiefExecutive.h"
#include "Utility.h"

int main()
{
    std::cout << "-----------------------------------------------\n";
    std::cout << "         Enter the company information         \n";
    std::cout << "-----------------------------------------------\n";
    std::cout << "Name of the Chief Executive Officer: ";
    std::string chiefName;
    std::getline(std::cin, chiefName);

    int teamsCount;
    do
    {
        std::cout << "Number of teams in the company: ";
        std::cin >> teamsCount;
    } while (!correctInput(teamsCount));
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    ChiefExecutive* chief = new ChiefExecutive(chiefName, teamsCount);

    std::cout << "\n============================================\n";
    std::cout << "                  WORKFLOW                 \n";
    std::cout << "============================================\n";
    chief->workflow();
    
    delete chief;

    return 0;
}




