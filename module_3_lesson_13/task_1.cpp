// Продвинутые темы и техники C++
// Урок 13. Дополнительные возможности классов и умные указатели

// 1. Использование умного указателя

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

class Dog
{
	std::string name;
	std::shared_ptr<Toy> toy;
public:
	Dog(std::string inName, std::shared_ptr<Toy> inToy) : name(inName), toy(inToy) { }
	Dog() : Dog("Some dog", nullptr) { } 
	Dog(std::string inName) : Dog(inName, nullptr) { }
	Dog(std::shared_ptr<Toy> inToy) : Dog("Some dog", inToy) { }

	void getToy(std::shared_ptr<Toy> inToy)
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

	void dropToy()
	{
		if (this->toy == nullptr)
			std::cout << name << " has nothing to drop.\n";
		else
		{
			this->toy = nullptr;
			std::cout << name << " dropped the toy.\n";
		}
	}

	~Dog() { }
};

int main()
{
	std::shared_ptr<Toy> ball = std::make_shared<Toy>("ball");

	Dog a("Chase");
	Dog b("Cooper");

	a.getToy(ball);
	a.getToy(ball);
	b.getToy(ball);
	b.dropToy();
	a.dropToy();

	ball.reset();
	
	return 0;
}