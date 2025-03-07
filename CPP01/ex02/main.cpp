#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the \033[1;31mSTRING VARIBLE\033[0m: " << &str << std::endl;
	std::cout << "The memory address held by \033[1;31mstringPTR\033[0m: " << &stringPTR << std::endl;
	std::cout << "The memory address held by \033[1;31mstringREF\033[0m: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the \033[1;31mSTRING VARIBLE\033[0m: " << str << std::endl;
	std::cout << "The value pointed to by \033[1;31mstringPTR\033[0m: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by \033[1;31mstringREF\033[0m: " << stringREF << std::endl;

	return 0;
}
