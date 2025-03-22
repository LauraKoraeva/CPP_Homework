#include "toy.h"
#include "dog.h"

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