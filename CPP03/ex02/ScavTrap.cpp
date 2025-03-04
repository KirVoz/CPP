#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "Scavy";
	std::cout << "\033[1;34mScavTrap " << this->_name << " ready to serve\033[0m" << std::endl;
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[1;34mScavTrap " << name << " ready to serve\033[0m" << std::endl;
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "\033[1;34mScavTrap has copied " << this->_name << ", assambled and ready for action\033[0m" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

ScavTrap::~ScavTrap()
{
	std::cout << "\033[1;31mScavTrap " << this->_name << " is destroyed\033[0m" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if(this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	if (this->_hitpoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " has " << this->_energyPoints << " energy points left!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead!" << std::endl;
		return ;
	}
	if (amount == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is not damaged!" << std::endl;
		return ;
	}
	if (this->_hitpoints - amount > 0)
	{
		this->_hitpoints -= amount;
		std::cout << "ScavTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		std::cout << "ScavTrap " << this->_name << " has " << this->_hitpoints << " hitpoints left!" << std::endl;
	}
	else
	{
		this->_hitpoints = 0;
		std::cout << "ScavTrap " << this->_name << " is killed!" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	if (this->_hitpoints == 100)
	{
		std::cout << "ScavTrap " << this->_name << " is already fully repaired!" << std::endl;
		return ;
	}
	if (this->_hitpoints + amount < 100)
	{
		this->_hitpoints += amount;
		std::cout << "ScavTrap " << this->_name << " is repaired for " << amount << " hitpoints!" << std::endl;
		std::cout << "ScavTrap " << this->_name << " has " << this->_hitpoints << " hitpoints left!" << std::endl;
	}
	else
	{
		this->_hitpoints = 100;
		std::cout << "ScavTrap " << this->_name << " is fully repaired!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode!" << std::endl;
}
