#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << "Test 1: Bureaucrat grade too high" << std::endl;
		try
		{
			Bureaucrat b("Bureaucrat", 0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test 2: Bureaucrat grade too low" << std::endl;
		try
		{
			Bureaucrat b("Bureaucrat", 151);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test 3: Create Form" << std::endl;
		Form f("Paper 0", 10, 10);
		std::cout << f << std::endl;
	}
	{
		std::cout << "Test 4: Bureaucrat signs Form" << std::endl;
		Bureaucrat b("mr BEE", 10);
		Form f("Paper 1", 10, 10);
		b.signForm(f);
		std::cout << f << std::endl;
	}
	{
		std::cout << "Test 5: Bureaucrat grade too low to sign Form" << std::endl;
		Bureaucrat b("sir Bozo", 11);
		Form f("Paper 2", 10, 10);
		b.signForm(f);
		std::cout << f << std::endl;
	}
	{
		std::cout << "Test 6: Bureaucrat grade higher than Form requirement" << std::endl;
		Bureaucrat b("Bureaucrat", 9);
		Form f("Paper 3", 10, 10);
		b.signForm(f);
		std::cout << f << std::endl;
	}
}
