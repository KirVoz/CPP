#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	{
		ScavTrap s;
		ClapTrap c1("Clappy");
		ScavTrap s2("Davy");
		ScavTrap s3 = s2;

		std::cout << "------------------------------------------" << std::endl;
		s.attack("Scavy");
		std::cout << "------------------------------------------" << std::endl;
		c1.takeDamage(20);
		std::cout << "------------------------------------------" << std::endl;
		c1.attack("Davy");
		std::cout << "------------------------------------------" << std::endl;
		s2.takeDamage(0);
		std::cout << "------------------------------------------" << std::endl;
		s2.attack("Clappy");
		std::cout << "------------------------------------------" << std::endl;
		s.takeDamage(20);
		std::cout << "------------------------------------------" << std::endl;
		s3.guardGate();
		std::cout << "------------------------------------------" << std::endl;
		s3.beRepaired(20);
		std::cout << "------------------------------------------" << std::endl;
		s2.beRepaired(19);
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "------------------------------------------" << std::endl;
		ClapTrap *c = new ScavTrap ("bill");
		delete c;
		std::cout << "------------------------------------------" << std::endl;
	}
	return 0;
}
