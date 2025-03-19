#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default_form"), _signed(false), _signGrade(150), _execGrade(150), _exe(false)
{
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade), _exe(false)
{
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade), _exe(other._exe)
{
}

AForm::~AForm()
{
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	if (_signed)
		throw AForm::AllreadySignedException();
	_signed = true;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::setExe() const
{
	_exe = true;
}

bool AForm::getExe() const
{
	return _exe;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low\n";
}

const char *AForm::NoSignatureException::what() const throw()
{
	return "Form is not signed\n";
}

const char *AForm::AllreadySignedException::what() const throw()
{
	return "Form has already been signed\n";
}

const char *AForm::AllreadyDoneException::what() const throw()
{
	return "Form has already been executed\n";
}

AForm &AForm::operator=(const AForm &other)
{
	_signed = other._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName() << " form is " << (f.getSigned() ? "signed\n" : "not signed\n") << std::endl;
	return out;
}
