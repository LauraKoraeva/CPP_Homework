#include <iostream>
#include "shared_ptr_toy.h"

shared_ptr_toy::shared_ptr_toy()
{
    toy = new Toy("some toy");
    count = new int(1);
    std::cout << "A new toy was created.\n";
}

shared_ptr_toy::shared_ptr_toy(std::string inName)
{
    toy = new Toy(inName);
    count = new int(1);
    std::cout << "A new toy was created.\n";
}

void shared_ptr_toy::checkCount()
{
    --(*count);
    if (*count == 0)
    {
        delete toy;
        delete count;
        std::cout << "The toy was deleted.\n";
    }
}

shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& other)
{
    toy = new Toy(*other.toy);
    count = other.count;
    ++(*count);
}

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& other)
{
    if (this == &other)
        return *this;
    checkCount();
    toy = new Toy(*other.toy);
    count = other.count;
    ++(*count);
    return *this;
}

int shared_ptr_toy::getCount() const { return *count; }

shared_ptr_toy::~shared_ptr_toy()
{
    checkCount();
}