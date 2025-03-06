#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	virtual ~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &other);

	void attack(const std::string &target);
	void whoAmI();
	void getStat();
};
