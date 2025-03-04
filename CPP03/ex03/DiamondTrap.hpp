#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	virtual ~DiamondTrap();

	void attack(const std::string &target);
	void whoAmI();
	void getStat();
	DiamondTrap &operator=(const DiamondTrap &other);
};
