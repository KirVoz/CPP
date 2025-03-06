#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name")
{
	this->_name = "default";
	this->_hitpoints = FragTrap::getHP();
	this->_energyPoints = ScavTrap::getEP();
	this->_attackDamage = FragTrap::getAD();
	std::cout << "DiamondTrap" << this->_name << " default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hitpoints = FragTrap::getHP();
	this->_energyPoints = ScavTrap::getEP();
	this->_attackDamage = FragTrap::getAD();
	std::cout << "DiamondTrap " << this->_name << " name constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap copy constructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap assignation operator" << std::endl;
	this->_name = other._name;
	this->_hitpoints = other._hitpoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destructor" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "_________________________" << std::endl;
	std::cout << "You ask WHOAMI? I am " << this->_name << " great son of Sir \033[1;31m" << ClapTrap::_name << "\033[0m!!!"<< std::endl;
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
