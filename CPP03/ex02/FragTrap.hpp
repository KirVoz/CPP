#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	~FragTrap();

	void attack(const std::string &target);
	
	void highFivesGuys(void);
	FragTrap &operator=(const FragTrap &other);
};
