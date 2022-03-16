#include "Fixed.hpp"

Fixed::Fixed()
{
	this->a = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed(Fixed const &s)
{
	this->a = s.getRawBits();
}

Fixed::Fixed(int const c)
{
	this->a = (c << Fixed::bit);
}

Fixed::Fixed(float const c)
{
	this->a = roundf(c * (1 << Fixed::bit));
}

std::ostream &operator<<(std::ostream &cout, Fixed const &klass)
{
	cout << klass.toFloat();
	return cout;
}

Fixed &Fixed::operator=(Fixed const &s)
{
	this->a = s.getRawBits();
	return *this;
}

bool Fixed::operator==(const Fixed &s) const
{
	return (this->getRawBits() == s.getRawBits());
}

bool Fixed::operator!=(Fixed const &s) const
{
	return (this->getRawBits() != s.getRawBits());
}

bool Fixed::operator<(Fixed const &s) const
{
	return (this->getRawBits() < s.getRawBits());
}

bool Fixed::operator>(Fixed const &s) const
{
	return (this->getRawBits() > s.getRawBits());
}

bool Fixed::operator<=(Fixed const &s) const
{
	return (this->getRawBits() <= s.getRawBits());
}

bool Fixed::operator>=(Fixed const &s) const
{
	return (this->getRawBits() >= s.getRawBits());
}

Fixed Fixed::operator*(Fixed const &s)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->getRawBits() * s.getRawBits() / (1 << Fixed::bit));
	return tmp;
}

Fixed Fixed::operator/(Fixed const &s)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->getRawBits() / s.getRawBits() / (1 << Fixed::bit));
	return tmp;
}

Fixed Fixed::operator+(Fixed const &s)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->getRawBits() + s.getRawBits());
	return tmp;
}

Fixed Fixed::operator-(Fixed const &s)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->getRawBits() - s.getRawBits());
	return tmp;
}

Fixed Fixed::operator++()
{
	this->a++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	operator++();
	return tmp;
}

Fixed Fixed::operator--()
{
	this->a--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	operator--();
	return tmp;
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
	return (x > y ? x : y);
}

Fixed const &Fixed::max(Fixed const &x, Fixed const &y)
{
	return (x > y ? x : y);
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
	return (x < y ? x : y);
}

Fixed const &Fixed::min(Fixed const &x, Fixed const &y)
{
	return (x < y ? x : y);
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
	return this->a;
}

void	Fixed::setRawBits(const int raw)
{
	this->a = raw;
}