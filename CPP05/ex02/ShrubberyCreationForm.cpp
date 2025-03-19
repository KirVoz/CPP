#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default_shrubbery", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const
{
	if (b.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	if (!getSigned())
		throw AForm::NoSignatureException();
	if (getExe())
		throw AForm::AllreadyDoneException();
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file\n";
		return;
	}
	file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
	file.close();
	std::cout << "Thank you dear Mr/Mrs " << b.getName() << " for your work\n";
	std::cout << "Tree is planted!!!" << std::endl;
	setExe();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	_target = other._target;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &f)
{
	out << f.getName() << " is " << (f.getSigned() ? "" : "not ") << "signed";
	return out;
}
