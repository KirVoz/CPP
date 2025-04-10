#include "MutantStack.hpp"
#include <vector>
#include <list>

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(1);
		mstack.push(2);

		std::cout << "Top is:" << mstack.top() << std::endl;

		std::cout << "Size:" << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "Size:" << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		mstack.push(6);

		MutantStack<int>::it it = mstack.begin();
		MutantStack<int>::it ite = mstack.end();

		std::cout << "INITIAL VALUE: " << *it << '\n';
		++it;
		std::cout << "After ++it: " << *it << '\n';
		--it;
		std::cout << "After --it: " << *it << std::endl;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "------------------" << std::endl;
		std::list<int> l;
		l.push_back(1);
		l.push_back(2);

		std::cout << "Top is:" << l.back() << std::endl;

		std::cout << "Size:" << l.size() << std::endl;
		l.pop_back();
		std::cout << "Size:" << l.size() << std::endl;

		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		l.push_back(6);

		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();

		std::cout << "INITIAL VALUE: " << *it << '\n';
		++it;
		std::cout << "After ++it: " << *it << '\n';
		--it;
		std::cout << "After --it: " << *it << std::endl;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
