#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::_debug()
{
	std::cout << DEBUG << std::endl;
}

void Harl::_info()
{
	std::cout << INFO << std::endl;
}

void Harl::_warning()
{
	std::cout << WARNING << std::endl;
}

void Harl::_error()
{
	std::cout << ERROR << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4)
	{
		if (level == levels[i])
		{
			break;
		}
		i++;
	}
	switch (i)
	{
	case 0:
		std::cout << "\033[34m>>>> DEBUG <<<<\033[0m" << std::endl;
		Harl::_debug();
		std::cout << "\033[33m>>>> INFO <<<<\033[0m" << std::endl;
		Harl::_info();
		std::cout << "\033[32m>>>> WARNING <<<<\033[0m" << std::endl;
		Harl::_warning();
		std::cout << "\033[31m>>>> ERROR <<<<\033[0m" << std::endl;
		Harl::_error();
		break;
	case 1:
		std::cout << "\033[33m>>>> INFO <<<<" << std::endl;
		Harl::_info();
		std::cout << "\033[32m>>>> WARNING <<<<\033[0m" << std::endl;
		Harl::_warning();
		std::cout << "\033[31m>>>> ERROR <<<<\033[0m" << std::endl;
		Harl::_error();
		break;
	case 2:
		std::cout << "\033[32m>>>> WARNING <<<<\033[0m" << std::endl;
		Harl::_warning();
		std::cout << "\033[31m>>>> ERROR <<<<\033[0m" << std::endl;
		Harl::_error();
		break;
	case 3:
		std::cout << "\033[31m>>>> ERROR <<<<\033[0m" << std::endl;
		Harl::_error();
		break;
	default:
		std::cerr << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		break;
	}
}
