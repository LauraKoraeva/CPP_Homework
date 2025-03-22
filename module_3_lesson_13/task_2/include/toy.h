#pragma once
#include <string>

class Toy
{
	std::string name;
public:
	Toy(std::string inName);
	Toy();
	std::string getName() const;
	
	~Toy();
};