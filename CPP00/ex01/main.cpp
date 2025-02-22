#include "Phonebook.hpp"

bool isValidName(const std::string &name)
{
	if (name.empty())
	{
		std::cout << "\033[1;31mYOU CANT LEAVE THIS FIELD EMPTY\033[0m" << std::endl;
		return false;
	}
	return true;
}

std::string getValidInput(const std::string &message)
{
	std::string input;
	do 
	{
		std::cout << message;
		std::getline(std::cin, input);
	} while (!isValidName(input));
	return input;
}

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
			std::string first_name = getValidInput("Enter first name: ");
			std::string last_name = getValidInput("Enter last name: ");
			std::string nickname = getValidInput("Enter nickname: ");
			std::string phone_number = getValidInput("Enter phone number: ");
			std::string underwear_color = getValidInput("Enter underwear color: ");
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
