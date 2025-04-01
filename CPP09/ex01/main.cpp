#include "RPN.hpp"

int main(int ac, char** av)
{
	try
	{
		if (ac != 2)
		{
			std::cout << "Usage: ./RPN [string]" << std::endl;
			return 1;
		}
		std::cout << RPN(av[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
