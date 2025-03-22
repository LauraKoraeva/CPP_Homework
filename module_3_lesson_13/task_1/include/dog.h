#pragma once
#include <string>
#include <memory>
#include "toy.h"

class Dog
{
	std::string name;
	std::shared_ptr<Toy> toy;
public:
	Dog(std::string inName, std::shared_ptr<Toy> inToy);
	Dog();
	Dog(std::string inName);
	Dog(std::shared_ptr<Toy> inToy);

	void getToy(std::shared_ptr<Toy> inToy);

	void dropToy();

	~Dog();
};

