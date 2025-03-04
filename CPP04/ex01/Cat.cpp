#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()){
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal("Cat"), _brain(new Brain(*other._brain)){
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat(){
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat assignition operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Meow Meow" << std::endl;
}

void Cat::setIdea(size_t i, const std::string &idea){
	_brain->setIdea(i, idea);
}

void Cat::getIdeas() const{
	for (size_t j = 0; j < 100; j++)
		std::cout << "\033[1;37mIdea " << j + 1 << ":\033[0m " << _brain->getIdea(j) << std::endl;
}
