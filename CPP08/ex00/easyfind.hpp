#pragma once
#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class NotFoundException : public std::exception
{
public:
	const char *what() const throw()
	{
		return "Value not found";
	}
};

template <class T>
typename T::iterator easyfind(T &c, int value)
{
	typename T::iterator it = std::find(c.begin(), c.end(), value);
	if (it == c.end())
		throw NotFoundException();
	return it;
}
