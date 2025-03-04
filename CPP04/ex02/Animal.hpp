#pragma once

#include <iostream>

class AAnimal
{
protected:
	std::string _type;

public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &other);
	virtual ~AAnimal();
	AAnimal &operator=(const AAnimal &other);
	virtual void makeSound() const = 0;
	std::string getType() const;
};
