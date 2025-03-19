#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>


int main()
{
	// {
	// 	std::cout << "Test 1: Default constructors" << std::endl;
	// 	ShrubberyCreationForm form;
	// 	std::cout << form << std::endl;
	// 	RobotomyRequestForm form2;
	// 	std::cout << form2 << std::endl;
	//  PresidentialPardonForm form3;
	// 	std::cout << form3 << std::endl;
	// }
	// {
	// 	std::cout << "\033[31mTest 2: Shrubbery\033[0m" << std::endl;
	// 	ShrubberyCreationForm f("berry");
	// 	Bureaucrat a("aoao", 146);
	// 	Bureaucrat b("bobo", 145);
	// 	Bureaucrat c("coco", 137);

	// 	a.signForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// 	b.signForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// 	c.signForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// 	std::cout << f << std::endl;
	// 	std::cout << "-------------------" << std::endl;

	// 	b.executeForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// 	c.executeForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// }
	// {
	// 	std::cout << "\033[31mTest 3: Robotomy\033[0m" << std::endl;
	// 	std::srand(std::time(0));
	// 	RobotomyRequestForm f("robot");
	// 	Bureaucrat a("aoao", 146);
	// 	Bureaucrat b("bobo", 45);
	// 	Bureaucrat c("coco", 37);

	// 	a.signForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// 	b.signForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// 	c.signForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// 	std::cout << f << std::endl;
	// 	std::cout << "-------------------" << std::endl;

	// 	a.executeForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// 	b.executeForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// 	c.executeForm(f);
	// 	std::cout << "-------------------" << std::endl;
	// }
	{
		std::cout << "\033[31mTest 4: Presidential\033[0m" << std::endl;
		PresidentialPardonForm f("president");
		Bureaucrat a("aoao", 146);
		Bureaucrat b("bobo", 5);
		Bureaucrat c("coco", 1);

		a.signForm(f);
		std::cout << "-------------------" << std::endl;
		b.signForm(f);
		std::cout << "-------------------" << std::endl;
		c.signForm(f);
		std::cout << "-------------------" << std::endl;
		std::cout << f << std::endl;
		std::cout << "-------------------" << std::endl;

		a.executeForm(f);
		std::cout << "-------------------" << std::endl;
		b.executeForm(f);
		std::cout << "-------------------" << std::endl;
		c.executeForm(f);
		std::cout << "-------------------" << std::endl;

	}
	return 0;
}
