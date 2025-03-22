#include <iostream>
#include "dog.h"


Dog::Dog(std::string inName, std::shared_ptr<Toy> inToy) : name(inName), toy(inToy) { }
Dog::Dog() : Dog("Some dog", nullptr) { }
Dog::Dog(std::string inName) : Dog(inName, nullptr) { }
Dog::Dog(std::shared_ptr<Toy> inToy) : Dog("Some dog", inToy) { }

void Dog::getToy(std::shared_ptr<Toy> inToy)
{
    if (this->toy == inToy)
        std::cout << name << " already has the " << inToy->getName() << ".\n";
    else if (inToy.use_count() > 2)
        std::cout << "Another dog is playing with the " << inToy->getName() << ".\n";
    else
    {
        this->toy = inToy;
        std::cout << name << " got the " << inToy->getName() << ".\n";
    }
}

void Dog::dropToy()
{
    if (this->toy == nullptr)
        std::cout << name << " has nothing to drop.\n";
    else
    {
        this->toy = nullptr;
        std::cout << name << " dropped the toy.\n";
    }
}

Dog::~Dog() { }