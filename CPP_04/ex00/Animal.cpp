#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "\033[32m" << "Animal"<< "\033[0m" << "\t\tDefault constructor" << std::endl;
	this->type = "Animal";
}

Animal::~Animal(){std::cout << "\033[32m" << "Animal"<< "\033[0m" << "\t\tDefault destructor" << std::endl;}

Animal::Animal(Animal const &klas)
{
	*this = klas;
	std::cout << "\033[32m" << "Animal"<< "\033[0m" << "\t\tCopy constructor" << std::endl;
}

Animal::Animal(std::string const &type)
{
	this->type = type;
	std::cout << "\033[32m" << "Animal"<< "\033[0m" << "\t\tConstructor" << std::endl;
}

Animal &Animal::operator=(const Animal &klas)
{
	std::cout << "\033[32m" << "Animal"<< "\033[0m" << "\t\tAssignation constructor" << std::endl;
	this->type = klas.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "\033[33m" << "Sound"<< "\033[0m" << "\t\tNo sound" << std::endl;
}

std::string const &Animal::getType() const
{
	return this->type;
}