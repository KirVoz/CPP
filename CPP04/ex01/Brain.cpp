#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &copy){
	std::cout << "Brain copy constructor" << std::endl;
	*this = copy;
}

Brain::~Brain(){
	std::cout << "Brain destructor" << std::endl;
}

Brain &Brain::operator=(const Brain &other){
	std::cout << "Brain assignation operator" << std::endl;
	if (this == &other)
		return *this;
	for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	return *this;
}

const std::string &Brain::getIdea(size_t index) const{
	return _ideas[index];
}

const std::string *Brain::getIdeasAddres(size_t index) const{
	return &_ideas[index];
}

void Brain::setIdea(size_t index, const std::string &idea){
	if (index >= 100)
		std::cout << "    __\n" << "\033[1;31mBrain is full\033[0m\n" << "    ***" << std::endl;
	else
		_ideas[index] = idea;
	}
