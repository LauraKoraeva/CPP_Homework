#include <memory>
#include "toy.h"

Toy::Toy(std::string inName) : name(inName) { }

Toy::Toy() : Toy("some toy") { }

std::string Toy::getName() const { return name; }