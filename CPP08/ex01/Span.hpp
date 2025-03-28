#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <exception>
#include <iterator>
#include <limits>

class Span
{
private:
	unsigned int _N;
	std::list<int> _lst;
public:
	Span();
	Span(unsigned int N);
	Span(unsigned int N, std::list<int> lst);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &other);

	void addNumber(int n);

	int shortestSpan();

	int longestSpan();

	void printList() const;

	void addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end);

	std::list<int>::iterator begin();

	std::list<int>::iterator end();
	
	class SpanFullException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Span is full";
		}
	};

	class NoSpanException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "No span found, not enough numbers";
		}
	};
};
