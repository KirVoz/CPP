#include "Span.hpp"

int main()
{
	Span sp = Span(1);
	sp.addNumber(1);
	// sp.addNumber(2);
	// sp.addNumber(3);
	// sp.addNumber(4);
	// sp.addNumber(5);
	// sp.addNumber(6);
	// sp.addNumber(7);
	try
	{
		sp.addNumbers(sp.begin(), sp.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	sp.printList();

	try
	{
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		sp.addNumber(12);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
