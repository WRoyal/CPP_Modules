#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->a = 0;
}

Fixed::Fixed(Fixed const &s)
{
	std::cout << "Copy constuctor called" << std::endl;
	this->a = s.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &s)
{
	std::cout << "Assignation operator called" << std::endl;
	this->a = s.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->a;
}

void	Fixed::setRawBits(const int raw)
{
	this->a = raw;
}