#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>

class Converter
{
private:
	int _int;
	float _float;
	double _double;
	char _char;
	std::string _str;
	bool _isNan;
	void convert();
	Converter(){};

public:
	explicit Converter(std::string const &input);
	Converter(Converter const &other);
	Converter &operator=(const Converter &other);
    ~Converter(){};
	int toInt() const;
	float toFloat() const;
	double toDouble() const;
	char toChar() const;
	std::string const &getStr() const;
	bool getIsNan() const;
};

std::ostream &operator<<(std::ostream &out, Converter const &klas);

#endif