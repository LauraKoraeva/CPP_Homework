#include <iostream>
#include <exception>
#include <vector>
#include <random>
#include <limits>
#include <numeric>

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



class NoCatchException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "No catch";
    }
};

class CaughtAFishException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Caught a fish";
    }
};

class CaughtABootException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Caught a boot";
    }
};

class missedThePondException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "The rod missed the pond";
    }
};




int getRandomNumber(int min, int max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> range(min, max);
    int number = range(mt);
    return number;
}


class Fishing
{
    enum Content
    {
        FISH,
        BOOT,
        EMPTY,
    };

    std::vector<Content> pond;

public:
    Fishing() : pond(9, Content::EMPTY)
    {
        fillInThePond();
    }


    int getEmptySector()
    {
        int sector = pond[getRandomNumber(0, 8)];
        while (pond[sector] != EMPTY)
        {
            ++sector;
            if (sector >= 9)
            {
                sector %= 9;
            }
        }
        return sector;
    }

    void fillInThePond()
    {
        pond[getEmptySector()] = FISH;

        for (int i = 0; i < 3; ++i)
        {

            pond[getEmptySector()] = BOOT;
        }
    }

    void scanThePond()
    {
        for (int i = 0; i < 9; ++i)
        {
            switch (pond[i])
            {
            case FISH: std::cout << "fish   "; break;
            case BOOT: std::cout << "boot   "; break;
            case EMPTY: std::cout << "empty   "; break;
            }
            if ((i + 1) % 3 == 0)
                std::cout << '\n';
        }
    }

    void checkTheCatch(int sector)
    {
        if (sector < 0 || sector >= 9)
        {
            throw missedThePondException();
        }
        if (pond[sector] == FISH)
        {
            throw CaughtAFishException();
        }
        if (pond[sector] == BOOT)
        {
            throw CaughtABootException();
        }
        if (pond[sector] == EMPTY)
        {
            throw NoCatchException();
        }
    }

    void castTheRod()
    {
        int sector;
        bool successfullCatch = false;

        while(!successfullCatch)
        {
            do
            {
                std::cout << "Cast the rod to: ";
                std::cin >> sector;
            } while (!correctInput(sector));

            try
            {
                checkTheCatch(sector);
            }
            catch(const NoCatchException& x)
            {
                std::cerr << "Caught exception: " << x.what() << '\n';
            }
            catch(const CaughtAFishException& x)
            {
                std::cerr << "Caught exception: " << x.what() << '\n';
                successfullCatch = true;
            }
            catch(const CaughtABootException& x)
            {
                std::cerr << "Caught exception: " << x.what() << '\n';
                successfullCatch = true;
            }
            catch(const missedThePondException& x)
            {
                std::cerr << "Caught exception: " << x.what() << '\n';
            }

        }


    }

    ~Fishing() { }


};

int main()
{
    Fishing* fishing = new Fishing;
    fishing->castTheRod();
    delete fishing;
}


