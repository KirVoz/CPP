#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "Fraggy";
	std::cout << "FragTrap " << this->_name << " is ready to fight!" << std::endl;
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " is ready to fight!" << std::endl;
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap has copied " << this->_name << " assambled and ready for action!" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitpoints = other._hitpoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "\033[1;38mFragTrap " << this->_name << " is despaired for high fives!\033[0m" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	if (this->_hitpoints <= 0)
	{
		std::cout << "Dead FragTrap " << this->_name << " can't attack!" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	std::cout << this->_name << " has " << this->_energyPoints << " energy points left!" << std::endl;
}
