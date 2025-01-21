#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;

	std::cout << "\033[4;34mWELCOME TO CRAPPY PHONEBOOK\033[0m" << std::endl;
	while (1)
	{
		std::string command;

		std::cout << "\033[31;43mCommands: ADD, SEARCH, EXIT\033[0m" << std::endl;
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			std::string first_name, last_name, nickname, phone_number, underwear_color;
			std::cout << "Enter first name: ";
			std::getline(std::cin, first_name);
			std::cout << "Enter last name: ";
			std::getline(std::cin, last_name);
			std::cout << "Enter nickname: ";
			std::getline(std::cin, nickname);
			std::cout << "Enter phone number: ";
			std::getline(std::cin, phone_number);
			std::cout << "Enter underwear color: ";
			std::getline(std::cin, underwear_color);
			phonebook.add_contact(first_name, last_name, nickname, phone_number, underwear_color);
		}
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "\033[1;31mInvalid command\033[0m" << std::endl;
	}

	return 0;
}
