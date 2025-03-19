#pragma once
#include <iostream>
#include <exception>

class Form
{
private:
	std::string _name;
	bool _signed;
	int const _signGrade;
	int const _execGrade;
public:
	Form();
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &other);
	virtual ~Form();

	void beSigned(const class Bureaucrat &b);

	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	class GradeTooLowException : public std::exception{
	public:
		virtual const char *what() const throw();
	};

	Form &operator=(const Form &other);
};

std::ostream &operator<<(std::ostream &out, const Form &f);
