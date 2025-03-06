#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	virtual ~FragTrap();

	virtual void attack(const std::string &target);

	void highFivesGuys(void);
	FragTrap &operator=(const FragTrap &other);

	int getHP() const;
	int getAD() const;
};
