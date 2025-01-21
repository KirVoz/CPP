#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
		std::cout << "\033[31mTEST inheritance and constructors\033[0m" << std::endl;
		ClapTrap c;
		ScavTrap s;
		FragTrap f;
		std::cout << "------------------------------------------" << std::endl;
		ClapTrap c1("Clappy");
		ScavTrap s1("Scavy");
		FragTrap f1("Franky");
		std::cout << "------------------------------------------" << std::endl;
		ClapTrap c2(c1);
		ScavTrap s2(s1);
		FragTrap f2(f1);
		std::cout << "------------------------------------------" << std::endl;
	}
	{
		std::cout << "\033[31mTEST in battle\033[0m" << std::endl;
		ClapTrap c("Clappy");
		ScavTrap s("Scavy");
		FragTrap f("Franky");
		std::cout << "------------------------------------------" << std::endl;
		c.attack("Scavy");
		s.takeDamage(10);
		s.attack("Franky");
		f.takeDamage(20);
		f.attack("Clappy");
		c.takeDamage(30);
		std::cout << "------------------------------------------" << std::endl;
		c.beRepaired(10);
		s.beRepaired(10);
		f.beRepaired(10);
		std::cout << "------------------------------------------" << std::endl;
	}
	{
		std::cout << "\033[31mTEST of endurance\033[0m" << std::endl;
		ClapTrap c("Clappy");
		ScavTrap s("Scavy");
		FragTrap f("Franky");
		std::cout << "------------------------------------------" << std::endl;
		for(int i = 0; i < 101; i++)
		{
			std::cout << "Round: " << i + 1 << std::endl;
			c.attack("Target dummy");
			s.attack("Target dummy");
			f.attack("Target dummy");
			std::cout << "------------------------------------------" << std::endl;
		}
	}
	{
		std::cout << "\033[31mTEST of DEATH\033[0m" << std::endl;
		ClapTrap c("Clappy");
		ScavTrap s("Scavy");
		FragTrap f("Franky");
		std::cout << "------------------------------------------" << std::endl;
		c.takeDamage(9);
		c.beRepaired(8);
		c.takeDamage(9);
		std::cout << "------------------------------------------" << std::endl;
		s.takeDamage(49);
		s.beRepaired(48);
		s.takeDamage(49);
		std::cout << "------------------------------------------" << std::endl;
		f.takeDamage(99);
		f.beRepaired(98);
		f.takeDamage(99);
		std::cout << "------------------------------------------" << std::endl;
	}
	{
		std::cout << "\033[31mTEST of uniq skills\033[0m" << std::endl;
		ClapTrap c("Clappy");
		ScavTrap s("Scavy");
		FragTrap f("Franky");
		std::cout << "------------------------------------------" << std::endl;
		s.guardGate();
		f.highFivesGuys();
		std::cout << "------------------------------------------" << std::endl;
	}
	return 0;
}
