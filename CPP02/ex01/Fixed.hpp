#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	Fixed(int const value);
	Fixed(float const value);
	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;
	int getRawbits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
