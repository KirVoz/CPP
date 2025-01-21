#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

int Fixed::getRawbits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

// Prefix increment operator

Fixed &Fixed::operator++()
{
	_fixedPointValue++;
	return *this;
}

// Postfix increment operator

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

// Prefix decrement operator
Fixed &Fixed::operator--()
{
	_fixedPointValue--;
	return *this;
}

// Postfix decrement operator
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed Fixed::operator+(const Fixed &value) const
{
	return Fixed(toFloat() + value.toFloat());
}

Fixed Fixed::operator-(const Fixed &value) const
{
	return Fixed(toFloat() - value.toFloat());
}

Fixed Fixed::operator*(const Fixed &value) const
{
	return Fixed(toFloat() * value.toFloat());
}

Fixed Fixed::operator/(const Fixed &value) const
{
	return Fixed(toFloat() / value.toFloat());
}

bool Fixed::operator>(const Fixed &value) const
{
	return _fixedPointValue > value._fixedPointValue;
}

bool Fixed::operator<(const Fixed &value) const
{
	return _fixedPointValue < value._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &value) const
{
	return _fixedPointValue >= value._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &value) const
{
	return _fixedPointValue <= value._fixedPointValue;
}

bool Fixed::operator==(const Fixed &value) const
{
	return _fixedPointValue == value._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &value) const
{
	return _fixedPointValue != value._fixedPointValue;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	_fixedPointValue = copy._fixedPointValue;
	return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}
