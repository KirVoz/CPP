#include "Span.hpp"

int main()
{
	Span sp = Span(10000);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(4);
	sp.addNumber(5);
	sp.addNumber(6);
	sp.addNumber(7);
	sp.addNumber(10);

	try
	{
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
		sp.addNumbers(sp.begin(), sp.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// sp.printList();
	std::cout << "Length: " << sp.printLength() << std::endl;

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
