#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixedPointValue = copy.getRawbits();
	return *this;
}

int Fixed::getRawbits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value){
	out << value.toFloat();
	return out;
}

Fixed::Fixed(int const value){
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << Fixed::_fractionalBits;
}

Fixed::Fixed(float const value){
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << Fixed::_fractionalBits));
}

float Fixed::toFloat(void) const{
	return (float)this->_fixedPointValue / (1 << Fixed::_fractionalBits);
}

int Fixed::toInt(void) const{
	return this->_fixedPointValue >> Fixed::_fractionalBits;
}
