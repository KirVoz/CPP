#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain *_brain;

public:
	Dog();
	Dog(const Dog &other);
	virtual ~Dog();
	Dog &operator=(const Dog &other);
	virtual void makeSound() const;
	void setIdea(size_t i, const std::string &idea);
	void getIdeas() const;
};
