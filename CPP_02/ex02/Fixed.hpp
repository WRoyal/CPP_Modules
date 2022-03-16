#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int a;
	static const int bit = 8;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &s);
	Fixed(int const a);
	Fixed(float const a);

	Fixed &operator=(Fixed const &s);

	bool operator==(const Fixed &s) const;
	bool operator!=(Fixed const &s) const;
	bool operator<(Fixed const &s) const;
	bool operator>(Fixed const &s) const;
	bool operator<=(Fixed const &s) const;
	bool operator>=(Fixed const &s) const;

	Fixed operator*(Fixed const &s);
	Fixed operator/(Fixed const &s);
	Fixed operator+(Fixed const &s);
	Fixed operator-(Fixed const &s);

	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	static Fixed &max(Fixed &x, Fixed &y);
	static Fixed const &max(Fixed const &x, Fixed const &y);
	static Fixed &min(Fixed &x, Fixed &y);
	static Fixed const &min(Fixed const &x, Fixed const &y);

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &cout, Fixed const &klass);

#endif