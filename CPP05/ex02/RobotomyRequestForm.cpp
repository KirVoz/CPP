#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default_robotomy", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &b) const
{
	if (b.getGrade() > getExecGrade())
	throw AForm::GradeTooLowException();
	if (!getSigned())
	throw AForm::NoSignatureException();
	if (getExe())
	throw AForm::AllreadyDoneException();
	std::cout << "Robotomizing " << _target << std::endl;
	std::cout << "*drilling noises*\n";
	if (rand() % 2)
		std::cout << _target << " has been robotomized\n";
	else
		std::cout << "Robotomization of " << _target << " has failed\n";
	setExe();
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &f)
{
	out << f.getName() << " is " << (f.getSigned() ? "" : "not ") << "signed";
	return out;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	_target = other._target;
	return *this;
}
