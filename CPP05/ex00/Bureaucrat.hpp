#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	virtual ~Bureaucrat();
	
	void incrementGrade();
	void decrementGrade();
	
	std::string getName() const;
	int getGrade() const;
	
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	
	Bureaucrat &operator=(const Bureaucrat &other);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
