#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Clappy"), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " assembled and ready for action!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap with name " << _name << " assembled and ready for action!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap has copied " << this->_name << " assembled and ready for action!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " was disassembled to pieces! RIP" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitpoints = other._hitpoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	if (this->_hitpoints <= 0)
	{
		std::cout << "Dead ClapTrap " << this->_name << " can't attack!" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	std::cout << this->_name << " has " << this->_energyPoints << " energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << this->_name << "is allready dead!" << std::endl;
		return ;
	}
	if (this->_hitpoints <= amount)
	{
		this->_hitpoints = 0;
		std::cout << this->_name << " id dead!" << std::endl;
		return ;
	}
	else
		this->_hitpoints -= amount;
	std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
	std::cout << this->_name << " has " << this->_hitpoints << " hitpoints left!" << std::endl;
	if (this->_hitpoints == 0)
		std::cout << this->_name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " is tired and exhausted!" << std::endl;
		return ;
	}
	if (this->_hitpoints == 0)
	{
		std::cout << "It's SAD, but " << this->_name << " is dead and can't be repaired!" << std::endl;
		return ;
	}
	else if (this->_hitpoints + amount >= 10)
		this->_hitpoints = 10;
	else
		this->_hitpoints += amount;
	std::cout << this->_name << " is repaired for " << amount << " points!" << std::endl;
}
