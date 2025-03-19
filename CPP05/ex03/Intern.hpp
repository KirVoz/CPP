#pragma once
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	virtual ~Intern();

	AForm *makeForm(std::string name, std::string target);
	Intern &operator=(const Intern &other);
};
