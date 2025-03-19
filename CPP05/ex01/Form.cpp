#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default_form"), _signed(false), _signGrade(150), _execGrade(150){
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade){
}

Form::~Form(){
}

void Form::beSigned(const Bureaucrat &b){
	if (b.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::string Form::getName() const{
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

const char *Form::GradeTooLowException::what() const throw(){
	return "Grade for Form signing is too low\n";
}

Form &Form::operator=(const Form &other){
	_signed = other._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &f){
	out << f.getName() << " form is " << (f.getSigned() ? "signed" : "not signed") << std::endl;
	return out;
}
