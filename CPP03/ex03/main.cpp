#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	{
		std::cout << "\033[1;31m------------------------\033[0m" << std::endl;
		DiamondTrap d("name");
		d.getStat();
		d.whoAmI();
		d.attack("target");
		d.highFivesGuys();
		d.ScavTrap::takeDamage(20);
		d.FragTrap::beRepaired(10);
		d.guardGate();
		d.getStat();
	}
	{
		std::cout << "\033[1;35m------------------------\033[0m" << std::endl;
		DiamondTrap *d = new DiamondTrap();
		d->getStat();
		d->whoAmI();
		d->attack("target");
		d->highFivesGuys();
		d->ScavTrap::takeDamage(20);
		d->FragTrap::beRepaired(10);
		d->guardGate();
		d->getStat();
	}
}
