#include <iostream>
#include "dog.h"
#include "shared_ptr_toy.h"

shared_ptr_toy make_shared_toy(std::string inName)
{
	shared_ptr_toy newToy(inName);
	return newToy;
}


int main()
{
    shared_ptr_toy ball("Ball");
    
    std::cout << "Number of references: " << ball.getCount() << '\n';
	Dog* dog1 = new Dog("Archie", ball);
	std::cout << "Number of references: " << ball.getCount() << '\n';
	Dog* dog2 = new Dog("Cooper", ball);
	std::cout << "Number of references: " << ball.getCount() << '\n';
	delete dog1;
	std::cout << "Number of references: " << ball.getCount() << '\n';
	delete dog2;
	std::cout << "Number of references: " << ball.getCount() << '\n';

	return 0;
}