#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	this->_name = ClapTrap::_name + "_clap_name";
	std::cout << "DiamondTrap" << this->_name << " default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name)
{
	this->_name = ClapTrap::_name + "_clap_name";
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : FragTrap(other), ScavTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap copy constructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	FragTrap::operator=(other);
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destructor" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "_________________________" << std::endl;
	std::cout << "DiamondTrap " << this->_name << " whoAmI, " << "great son of Sir \033[1;31m" << ClapTrap::_name << "\033[0m!!!"<< std::endl;
	std::cout << "_________________________" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::getStat()
{
	std::cout << "_________________________" << std::endl;
	std::cout << "DiamondTrap " << this->_name << " stats:" << std::endl;
	std::cout << "Hitpoints: " << this->_hitpoints << std::endl;
	std::cout << "Energy points: " << this->_energyPoints << std::endl;
	std::cout << "Attack damage: " << this->_attackDamage << std::endl;
	std::cout << "_________________________" << std::endl;
}
