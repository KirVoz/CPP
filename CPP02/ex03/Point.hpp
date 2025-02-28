#pragma once

#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(const Point &copy);
	Point(const float x, const float y);
	~Point();
	const Fixed &getX() const;
	const Fixed &getY() const;
	Point &operator=(const Point &copy);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
