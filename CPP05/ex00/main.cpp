#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "Test 0: Create a Bureaucrat with a grade out of range" << std::endl;
		try
		{
			Bureaucrat b("bozo", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat b("bozo", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
	{
		std::cout << "Test 1: Create a Bureaucrat with a grade of 150" << std::endl;
		try
		{
			Bureaucrat b("bozo", 150);
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test 2: Create a Bureaucrat with a grade of 0" << std::endl;
		try
		{
			Bureaucrat b("bozo", 0);
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test 3: Create a Bureaucrat with a grade of 1" << std::endl;
		try
		{
			Bureaucrat b("bozo", 1);
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test 4: Create a Bureaucrat with a grade of 150 and increment the grade" << std::endl;
		try
		{
			Bureaucrat b("bozo", 150);
			std::cout << b << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test 5: Create a Bureaucrat with a grade of 1 and decrement the grade" << std::endl;
		try
		{
			Bureaucrat b("bozo", 1);
			std::cout << b << std::endl;
			b.decrementGrade();
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test 6: Create a Bureaucrat with a grade of 150 and decrement the grade" << std::endl;
		try
		{
			Bureaucrat b("bozo", 150);
			std::cout << b << std::endl;
			b.decrementGrade();
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test 7: Create a Bureaucrat with a grade of 1 and increment the grade" << std::endl;
		try
		{
			Bureaucrat b("bozo", 1);
			std::cout << b << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
