#pragma once
#include <iostream>
#include <exception>

class AForm
{
private:
	std::string _name;
	bool _signed;
	int const _signGrade;
	int const _execGrade;
	mutable bool _exe;
public:
	AForm();
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm &other);
	virtual ~AForm();

	void beSigned(const class Bureaucrat &b);

	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void setExe() const;
	bool getExe() const;

	virtual void execute(const class Bureaucrat &b) const = 0;

	class GradeTooLowException : public std::exception{
	public:
		virtual const char *what() const throw();
	};

	class NoSignatureException : public std::exception{
	public:
		virtual const char *what() const throw();
	};

	class AllreadySignedException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
	
	class AllreadyDoneException : public std::exception{
		public:
			virtual const char *what() const throw();
		};

	AForm &operator=(const AForm &other);
};

std::ostream &operator<<(std::ostream &out, const AForm &f);
