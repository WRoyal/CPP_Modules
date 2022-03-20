#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "\033[32;1m" << "WrongAnimal"<< "\033[0m" << "\tDefault constructor" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal(){std::cout << "\033[32;1m" << "WrongAnimal"<< "\033[0m" << "\tDefault destructor" << std::endl;}

WrongAnimal::WrongAnimal(WrongAnimal const &klas)
{
	*this = klas;
	std::cout << "\033[32;1m" << "WrongAnimal"<< "\033[0m" << "\t\tCopy constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type)
{
	this->type = type;
	std::cout << "\033[32;1m" << "WrongAnimal"<< "\033[0m" << "\tConstructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &klas)
{
	std::cout << "\033[32;1m" << "WrongAnimal"<< "\033[0m" << "\tAssignation constructor" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "\033[33m" << "Sound"<< "\033[0m" << "\t\t@$!@%*_#)$+" << std::endl;
}

std::string const &WrongAnimal::getType() const
{
	return this->type;
}