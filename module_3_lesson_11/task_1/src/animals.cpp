#include <iostream>
#include <string>
#include <vector> 
#include "animals.h"
#include "talents.h"
#include "utility.h"

Dog::Dog(std::string inName)
{
   name = inName; 
}

Dog::Dog() : Dog::Dog("Unknown") { }

void Dog::voice()
{
    std::cout << "Bark!\n";
}

void Dog::add_talent()
{
    Talent* talent;

    std::cout << "\nChoose talent:\n";
    std::cout << "1 - swimming\n";
    std::cout << "2 - dancing\n";
    std::cout << "3 - counting\n";
    int choice;
    do
    {
        std::cin >> choice;
    } while (!correctInput(choice));
    switch (choice)
    {
    case SWIMMING:
        talent = new Swimming;
        talents.push_back(talent);
        break;
    case DANCING:
        talent = new Dancing;
        talents.push_back(talent);
        break;
    case COUNTING:
        talent = new Counting;
        talents.push_back(talent);
        break;
    }
}

void Dog::show_talents()
{
    std::cout << "\n**************************************\n";
    if (!talents.empty())
    {
        std::cout << "This is " << name << " and it has some talents:\n";
        for (int i = 0; i < talents.size(); ++i)
        {
            std::cout << "It can \"";
            talents[i]->showTalent();
            std::cout << "\"\n";
        }
    }
    else
        std::cout << "This is " << name << " and it has no talents.\n";
    std::cout << "**************************************\n";
}

Dog::~Dog()
{
    for (auto t : talents)
    {
        delete t;
    }

    talents.clear();
}