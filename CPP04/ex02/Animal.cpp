#include "Animal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AAnimal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal assignition operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return _type;
}
