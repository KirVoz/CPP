#pragma once

#include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	unsigned int _hitpoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clapTrap);
	virtual ~ClapTrap();
	
	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap &operator=(const ClapTrap &other);
};
