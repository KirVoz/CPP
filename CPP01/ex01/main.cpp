#include "Zombie.hpp"
#include <sstream>

int StringToInt(std::string str)
{
	std::stringstream ss(str);
	int num;
	ss >> num;
	return num;
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Usage: ./zombieHorde [num] [name]" << std::endl;
		return 1;
	}
	int N = StringToInt(av[1]);
	Zombie *zombies = zombieHorde(N, av[2]);
	for (int i = 0; i < N; i++)
	{
		std::cout << "\033[1;34mZombie " << i + 1 << ":\033[0m ";
		zombies[i].announce();
	}
	delete[] zombies;
}
