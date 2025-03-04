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

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << "Dead FragTrap " << this->_name << " can't be repaired!" << std::endl;
		return ;
	}
	if (this->_hitpoints + amount >= 100)
	{
		this->_hitpoints = 100;
		std::cout << "FragTrap " << this->_name << " is fully repaired!" << std::endl;
		return ;
	}
	this->_hitpoints += amount;
	std::cout << "FragTrap " << this->_name << " is repaired for " << amount << " hitpoints!" << std::endl;
	std::cout << this->_name << " has " << this->_hitpoints << " hitpoints left!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << this->_name << " is allready dead!" << std::endl;
		return ;
	}
	if (this->_hitpoints <= amount)
	{
		this->_hitpoints = 0;
		std::cout << "FragTrap " << this->_name << " make KABOOOM!" << std::endl;
		return ;
	}
	else
		this->_hitpoints -= amount;
	std::cout << "FragTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	std::cout << this->_name << " has " << this->_hitpoints << " hitpoints left!" << std::endl;
}
