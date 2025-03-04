#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal("Dog"), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignition operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		*_brain = *other._brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

void Dog::setIdea(size_t i, const std::string &idea)
{
	_brain->setIdea(i, idea);
}

void Dog::getIdeas() const
{
	for (size_t j = 0; j < 100; j++)
		std::cout << "\033[1;37mIdea " << j + 1 << ":\033[0m " << _brain->getIdea(j) << std::endl;
}
