#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce()
{
	std::cout << "\033[1;31m" << this->name << " BrainnnzzzZ...\033[0m" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
