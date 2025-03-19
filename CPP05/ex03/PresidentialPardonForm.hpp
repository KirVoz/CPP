#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	void execute(const Bureaucrat &b) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &f);
