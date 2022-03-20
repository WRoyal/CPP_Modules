#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "\033[31m" << "WrongCat"<< "\033[0m" << "\tDefault constructor" << std::endl;
}

WrongCat::~WrongCat(){std::cout << "\033[31m" << "WrongCat"<< "\033[0m" << "\tDefault destructor" << std::endl;}

WrongCat::WrongCat(WrongCat const &klas)
{
	*this = klas;
	std::cout << "\033[31m" << "WrongCat"<< "\033[0m" << "\tCopy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &klas)
{
	std::cout << "\033[31m" << "WrongCat"<< "\033[0m" << "\tAssignation constructor" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "\033[33m" << "Sound"<< "\033[0m" << "\t\tMe^eo**oo@@ww" << std::endl;
}