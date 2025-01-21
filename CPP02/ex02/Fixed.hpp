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
	Fixed(int const value);
	Fixed(float const value);
	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;
	int getRawbits(void) const;
	void setRawBits(int const raw);
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	Fixed operator+(const Fixed &value) const;
	Fixed operator-(const Fixed &value) const;
	Fixed operator*(const Fixed &value) const;
	Fixed operator/(const Fixed &value) const;
	bool operator>(const Fixed &value) const;
	bool operator<(const Fixed &value) const;
	bool operator>=(const Fixed &value) const;
	bool operator<=(const Fixed &value) const;
	bool operator==(const Fixed &value) const;
	bool operator!=(const Fixed &value) const;
	Fixed &operator=(const Fixed &copy);

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
