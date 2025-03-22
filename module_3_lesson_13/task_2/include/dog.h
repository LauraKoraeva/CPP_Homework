#pragma once
#include <string>
#include "shared_ptr_toy.h"

class Dog
{
	std::string name;
	shared_ptr_toy toy;

public:
	Dog(std::string inName, shared_ptr_toy inToy);
	Dog();
	Dog(std::string inName);
	Dog(shared_ptr_toy inToy);

	~Dog();
};