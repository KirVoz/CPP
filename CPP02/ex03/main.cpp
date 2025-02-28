#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	{
		const Point a;
		const Point b(10, 0);
		const Point c(0, 10);
		const Point point(3, 3);

		if (bsp(a, b, c, point))
			std::cout << "Point is inside the triangle" << std::endl;
		else
			std::cout << "Point is outside the triangle" << std::endl;
	}
}
