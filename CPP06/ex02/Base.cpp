#include "Base.hpp"

Base *generate(void)
{
	int random = rand() % 3;
	switch (random)
	{
	case 0:
		std::cout << "A - created" << std::endl;
		return new A();
	case 1:
		std::cout << "B - created" << std::endl;
		return new B();
	case 2:
		std::cout << "C - created" << std::endl;
		return new C();
	default:
		return NULL;
		break;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A ptr" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B ptr" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C ptr" << std::endl;
	else
		std::cerr << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A ref" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B ref" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C ref" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}
