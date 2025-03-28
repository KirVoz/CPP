#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {};

	MutantStack(const MutantStack &other) : std::stack<T>(other) {};

	MutantStack &operator=(const MutantStack &other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	};

	~MutantStack() {};

	typedef typename std::stack<T>::container_type::iterator it;

	it begin() {
		return this->c.begin(); // а тут мы просто ссылаемся на контейнер, который уже есть в std::stack и в самом классе MutantStack так как он наследован
		// return std::stack<T>::c.begin(); // если бы мы имели поле "с" в классе MutantStack
	};

	it end() {
		return std::stack<T>::c.end();
	};
};
