#include "dog.h"

Dog::Dog(std::string inName, shared_ptr_toy inToy) : name(inName), toy(inToy) { }
Dog::Dog() : name("Some dog") { }
Dog::Dog(std::string inName) : name(inName) { }
Dog::Dog(shared_ptr_toy inToy) : Dog("Some dog", inToy) { }

Dog::~Dog() { }