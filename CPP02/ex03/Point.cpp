#include "Point.hpp"

Point::Point() : _x(0), _y(0){}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y){}

Point::Point(const float x, const float y) : _x(x), _y(y){}

Point::~Point(){}

const Fixed &Point::getX() const
{
	return this->_x;
}

const Fixed &Point::getY() const
{
	return this->_y;
}

Point &Point::operator=(const Point &copy)
{
	if (this == &copy)
		return *this;
	return *this;
}

Fixed triangleArea(Point const &p1, Point const &p2, Point const &p3) {
    Fixed area = p1.getX() * (p2.getY() - p3.getY()) +
                 p2.getX() * (p3.getY() - p1.getY()) +
                 p3.getX() * (p1.getY() - p2.getY());
    if (area < Fixed(0))
        return (area * -1);
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = triangleArea(a, b, c);
	std::cout << "Area ABC: " << areaABC << std::endl;
    Fixed areaPAB = triangleArea(point, a, b);
	std::cout << "Area PAB: " << areaPAB << std::endl;
    Fixed areaPBC = triangleArea(point, b, c);
	std::cout << "Area PBC: " << areaPBC << std::endl;
    Fixed areaPCA = triangleArea(point, c, a);
	std::cout << "Area PCA: " << areaPCA << std::endl;
    if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
        return false;
    return (areaPAB + areaPBC + areaPCA == areaABC);
}
