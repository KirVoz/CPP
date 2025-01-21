#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::get_first_name()
{
	return this->_first_name;
}

std::string Contact::get_last_name()
{
	return this->_last_name;
}

std::string Contact::get_nickname()
{
	return this->_nickname;
}

std::string Contact::get_phone_number()
{
	return this->_phone_number;
}

std::string Contact::get_underwear_color()
{
	return this->_underwear_color;
}

void Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

void Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

void Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void Contact::set_underwear_color(std::string underwear_color)
{
	this->_underwear_color = underwear_color;
}
