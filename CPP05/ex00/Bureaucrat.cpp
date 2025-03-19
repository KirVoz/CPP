#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default_bozo"), _grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){
}

Bureaucrat::~Bureaucrat(){
}

void Bureaucrat::incrementGrade(){
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(){
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	_grade = other._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b){
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
