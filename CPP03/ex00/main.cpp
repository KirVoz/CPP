#include "ClapTrap.hpp"

int main()
{
	std::cout << "------------------------------------------" << std::endl;

	ClapTrap first;
	ClapTrap second("Franky");

	std::cout << "------------------------------------------" << std::endl;

	std::cout << "Next battle is going to begin!" << std::endl;

	first.attack("Franky");
	second.takeDamage(0);

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	std::cout << "Franky slipped " << std::endl;
	second.takeDamage(4);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Franky is going to repair himself!" << std::endl;

	second.beRepaired(3);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	std::cout << "This is just a beginning!" << std::endl;
	std::cout << "There is a heated exchange of blows!" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	for(int i = 10; i > 0; i--)
	{
		first.attack("111Franky");
		second.takeDamage(0);
		second.attack("222Billy");
		first.takeDamage(0);
		std::cout << "------------------------------------------" << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "The battle is over!\n THIS iS A DRAW" << std::endl;
	return 0;
}
