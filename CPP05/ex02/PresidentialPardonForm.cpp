#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default_presidential", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat &b) const
{
	if (b.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	if (!getSigned())
		throw AForm::NoSignatureException();
	if (getExe())
		throw AForm::AllreadyDoneException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox\n";
	setExe();
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &f)
{
	out << f.getName() << " is " << (f.getSigned() ? "" : "not ") << "signed";
	return out;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	_target = other._target;
	return *this;
}
