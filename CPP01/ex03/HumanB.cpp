#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB()
{
	std::cout << this->name << " is dead" << std::endl;
}

void HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attack whith his " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon " << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
