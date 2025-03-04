#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *_brain;

public:
	Cat();
	Cat(const Cat &other);
	virtual ~Cat();
	Cat &operator=(const Cat &other);
	virtual void makeSound() const;
	void setIdea(size_t i, const std::string &idea);
	void getIdeas() const;
};
