#include "Animal.hpp"

Animal::Animal() : _type("Animal"){
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type){
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &other){
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "Animal assignition operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Animal::makeSound() const{
	std::cout <<"Animal sound" << std::endl;
}

std::string Animal::getType() const{
	return _type;
}
