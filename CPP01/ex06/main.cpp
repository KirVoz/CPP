#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cout << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]" << std::endl;
	return 0;
}
