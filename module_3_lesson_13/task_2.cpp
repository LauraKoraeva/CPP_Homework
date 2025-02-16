#include <iostream>
#include <string>

class Toy
{
	std::string name;
public:
	Toy(std::string inName) : name(inName) { }
	Toy() : Toy("some toy") { }
	std::string getName() { return name; }
	
	~Toy() { }
};


class shared_ptr_toy
{
	Toy* toy;
	int* count;

public:
	shared_ptr_toy()
	{
		toy = new Toy("some toy");
		count = new int(1);
	}

	shared_ptr_toy(std::string inName)
	{
		toy = new Toy(inName);
		count = new int(1);
	}

	void checkCount()
	{
		--(*count);
		if (*count == 0)
		{
			delete toy;
			delete count;
		}
	}

	shared_ptr_toy(const shared_ptr_toy& other)
	{
		toy = new Toy(*other.toy);
		count = other.count;
		++(*count);
	}

	shared_ptr_toy& operator=(const shared_ptr_toy& other)
	{
		if (this == &other)
			return *this;
		checkCount();
		toy = new Toy(*other.toy);
		count = other.count;
		++(*count);
		return *this;
	}

	~shared_ptr_toy()
	{
		checkCount();
	}
};



class Dog
{
	std::string name;
	shared_ptr_toy toy;

public:
	Dog(std::string inName, shared_ptr_toy inToy) : name(inName), toy(inToy) { }
	Dog() : name("Some dog") { }
	Dog(std::string inName) : name(inName) { }
	Dog(shared_ptr_toy inToy) : Dog("Some dog", inToy) { }

	~Dog() { }
};


shared_ptr_toy make_shared_toy(std::string inName)
{
	shared_ptr_toy newToy(inName);
	return newToy;
}


int main()
{
	Dog dog("Archie", make_shared_toy("Ball"));

	return 0;
}