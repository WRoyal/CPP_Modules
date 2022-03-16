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

Fixed::Fixed(int const c)
{
	std::cout << "Int constructor called" << "\n";
	this->a = (c << Fixed::bit);
}

Fixed::Fixed(float const c)
{
	std::cout << "Float constructor called" << "\n";
	this->a = roundf(c * (1 << Fixed::bit));
}

std::ostream &operator<<(std::ostream &cout, Fixed const &klass)
{
	cout << klass.toFloat();
	return cout;
}

Fixed &Fixed::operator=(Fixed const &s)
{
	std::cout << "Assignation operator called" << std::endl;
	this->a = s.getRawBits();
	return *this;
}

int Fixed::toInt() const
{
	return (this->a >> Fixed::bit);
}

float Fixed::toFloat() const
{
	return ((float)this->a / (float)(1 << Fixed::bit));
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