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


	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &cout, Fixed const &klass);

#endif