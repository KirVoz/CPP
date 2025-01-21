#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class Phonebook
{
private:
	Contact contacts[MAX_CONTACTS];
	int _index;

public:
	Phonebook();
	~Phonebook();
	void add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string underwear_color);
	void search_contact();
	void print_contact(Contact contact);
};

#endif
