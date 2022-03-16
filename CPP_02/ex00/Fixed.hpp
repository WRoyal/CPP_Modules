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
	Fixed(int const c);
	Fixed(float const c);
	Fixed(Fixed const &s);
	Fixed &operator=(Fixed const &s);

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

#endif