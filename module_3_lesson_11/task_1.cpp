#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <numeric>

enum Operation
{
    CHOOSE_TALENT = 1,
    SHOW_TALENTS,
    EXIT,
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

class Talent
{
public:
    virtual void showTalent() = 0;  
};

class Swimming : public Talent
{
public:
    virtual void showTalent()
    {
        std::cout << "Swim";
    }
};

class Dancing : public Talent
{
public:
    virtual void showTalent()
    {
        std::cout << "Dance";
    }
};

class Counting : public Talent
{
public:
    virtual void showTalent()
    {
        std::cout << "Count";
    }
};

class Animal 
{
protected:
    std::string name;
    std::vector<Talent*> talents;

public:
    virtual void voice() = 0;
};

class Dog : public Animal 
{
    enum dogTalents
    {
        SWIMMING = 1,
        DANCING,
        COUNTING,
    };

public:
    Dog() { };

    Dog(std::string inName)
    {
        name = inName;
    }

    virtual void voice()
    {
        std::cout << "Bark!\n";
    }

    virtual void add_talent()
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

    virtual void show_talents()
    {
        std::cout << "\n**************************************\n";
        std::cout << "This is " << name << " and it has some talents:\n";
        for (int i = 0; i < talents.size(); ++i)
        {
            std::cout << "It can \"";
            talents[i]->showTalent();
            std::cout << "\"\n";
        }
        std::cout << "**************************************\n";
    }
};

/*
class Cat : public Animal 
{
public:
    Cat() { };

    Cat(std::string inName)
    {
        name = inName;
    }

    virtual void voice()
    {
        std::cout << "Meow!\n";
    }
};
*/

int main()
{
    std::cout << "Enter the name of your pet: ";
    std::string name;
    std::getline(std::cin, name);
    Dog dog(name);
    
    int choice;

    while (true)
    {
        std::cout << "------------------------------\n";
        std::cout << "Choose the next operation:\n";
        std::cout << "1 - choose talent\n";
        std::cout << "2 - show talents\n";
        std::cout << "3 - exit\n";
        std::cout << "------------------------------\n";
        do
        {
            std::cin >> choice;
        } while (!correctInput(choice));
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case CHOOSE_TALENT:
            dog.add_talent();
            break;
        case SHOW_TALENTS:
            dog.show_talents();
            return 0;
        case EXIT:
            return 0;
        default:
            std::cout << "No such operation.\n";
        }
    }
}