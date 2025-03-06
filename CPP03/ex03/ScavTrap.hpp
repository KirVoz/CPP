#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
protected:
	unsigned int _ep;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	virtual ~ScavTrap();
	
	virtual void attack(const std::string &target);

	void guardGate();
	ScavTrap &operator=(const ScavTrap &other);

	int getEP() const;
};
