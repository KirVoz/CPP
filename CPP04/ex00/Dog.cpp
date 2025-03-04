#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog"){
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog assignition operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Woof Woof" << std::endl;
}
