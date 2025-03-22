#pragma once
#include "toy.h"

class shared_ptr_toy
{
	Toy* toy;
	int* count;

public:
	shared_ptr_toy();

	shared_ptr_toy(std::string inName);

	void checkCount();

	shared_ptr_toy(const shared_ptr_toy& other);

	shared_ptr_toy& operator=(const shared_ptr_toy& other);
	
	int getCount() const;

	~shared_ptr_toy();
};
