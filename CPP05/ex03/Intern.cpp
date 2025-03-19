#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

Intern::Intern(){
}

Intern::Intern(const Intern &other){
	(void)other;
	return;
}

Intern::~Intern(){
}

AForm *Intern::makeForm(std::string name, std::string target){
	int i = 0;
	std::string forms[3] = {"pp", "rr", "tree"};
	while (i < 3 && name != forms[i])
		i++;
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	case 1:
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	case 2:
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	default:
		std::cout << "Intern cannot create " << name << "\nHe just an Intern! Don't blame this pure creature!" << std::endl;
		return NULL;
	}
}
