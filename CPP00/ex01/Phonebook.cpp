#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->_index = 0;
}

Phonebook::~Phonebook()
{
	std::cout << "\033[4;34mPhonebook destroyed" << std::endl;
	std::cout << "SEE YOU LATER COWBOY!!!\033[0m" << std::endl;
}

void Phonebook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string underwear_color)
{
	if (this->_index < MAX_CONTACTS)
	{
		this->contacts[this->_index].set_first_name(first_name);
		this->contacts[this->_index].set_last_name(last_name);
		this->contacts[this->_index].set_nickname(nickname);
		this->contacts[this->_index].set_phone_number(phone_number);
		this->contacts[this->_index].set_underwear_color(underwear_color);
		this->_index++;
	}
	else
	{
		std::cout << "Phonebook is full" << std::endl;
		std::cout << "Oldest contact will be replaced" << std::endl;
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
		{
			this->contacts[i] = this->contacts[i + 1];
		}
		this->contacts[MAX_CONTACTS - 1].set_first_name(first_name);
		this->contacts[MAX_CONTACTS - 1].set_last_name(last_name);
		this->contacts[MAX_CONTACTS - 1].set_nickname(nickname);
		this->contacts[MAX_CONTACTS - 1].set_phone_number(phone_number);
		this->contacts[MAX_CONTACTS - 1].set_underwear_color(underwear_color);
	}
}

void Phonebook::search_contact()
{
	if (this->_index == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	std::cout << "\033[1;32m     index|first name| last name|  nickname\033[0m" << std::endl;
	for (int i = 0; i < this->_index; i++)
	{
		std::cout << "\033[1;32m" << std::setw(10) << i + 1 << "|";
		std::string first_name = this->contacts[i].get_first_name();
		if (first_name.length() > 10)
			first_name = first_name.substr(0, 9) + ".";
		std::cout << std::setw(10) << first_name << "|";
		std::string last_name = this->contacts[i].get_last_name();
		if (last_name.length() > 10)
			last_name = last_name.substr(0, 9) + ".";
		std::cout << std::setw(10) << last_name << "|";
		std::string nickname = this->contacts[i].get_nickname();
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << "\033[0m" << std::endl;
	}
	std::string index;
	std::cout << "Enter an index: ";
	std::getline(std::cin, index);
	if (index.length() == 1 && index[0] >= '1' && index[0] <= '8')
	{
		int i = index[0] - '1';
		this->print_contact(this->contacts[i]);
	}
	else
	{
		std::cout << "\033[1;31mInvalid index\033[0m" << std::endl;
	}
}

void Phonebook::print_contact(Contact contact)
{
	std::cout << "First name: " << contact.get_first_name() << std::endl;
	std::cout << "Last name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
	std::cout << "Underwear color: " << contact.get_underwear_color() << std::endl;
}
