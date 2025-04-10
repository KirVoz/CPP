#include "easyfind.hpp"
// #include <deque>

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(6);
	v.push_back(7);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// int main()
// {

// 	std::deque<int> d;
// 	d.push_back(1);
// 	d.push_back(2);
// 	d.push_back(3);

// 	try
// 	{
// 		std::deque<int>::iterator it = easyfind(d, 3);
// 		std::cout << "Found: " << *it << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
	
// }
