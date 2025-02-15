#pragma once
#include <vector>
#include "talents.h" 

class Animal 
{
protected:
    std::string name;
    std::vector<Talent*> talents;

public:
    virtual void voice() = 0;
    virtual void add_talent() = 0;
    virtual void show_talents() = 0;
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
    Dog(std::string inName);

    Dog();

    virtual void voice();

    virtual void add_talent();

    virtual void show_talents();

    ~Dog();
};

