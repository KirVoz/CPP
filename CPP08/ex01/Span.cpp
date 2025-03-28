#include "Span.hpp"

Span::Span() : _N(0), _lst() {}

Span::Span(unsigned int N) : _N(N), _lst() {}

Span::Span(unsigned int N, std::list<int> lst) : _N(N), _lst(lst) {}

Span::Span(const Span &other) : _N(other._N), _lst(other._lst) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	this->_N = other._N;
	this->_lst = other._lst;
	return *this;
}

void Span::addNumber(int n)
{
	if (_lst.size() >= _N)
		throw SpanFullException();
	_lst.push_back(n);
}

int Span::shortestSpan() 
{
	if (_lst.size() < 2)
		throw NoSpanException();
	std::list<int> sortedList = _lst;
	sortedList.sort();

	std::list<int>::iterator it = sortedList.begin();
	std::list<int>::iterator prevIt = it;
	++it;
	int shortest = std::numeric_limits<int>::max();
	for (; it != sortedList.end(); ++it, ++prevIt)
		shortest = std::min(shortest, *it - *prevIt);
	return shortest;
}

int Span::longestSpan()
{
	if (_lst.size() < 2)
		throw NoSpanException();
	int min = *std::min_element(_lst.begin(), _lst.end());
	int max = *std::max_element(_lst.begin(), _lst.end());
	return max - min;
}

void Span::printList() const
{
	std::cout << "List: ";
	for(std::list<int>::const_iterator it = _lst.begin(); it != _lst.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void Span::addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	if (std::distance(begin, end) + _lst.size() > _N)
		throw SpanFullException();
	_lst.insert(_lst.end(), begin, end);
}

std::list<int>::iterator Span::begin()
{
	return _lst.begin();
}

std::list<int>::iterator Span::end()
{
	return _lst.end();
}
