#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "\033[34m" << "Cat"<< "\033[0m" << "\t\tDefault constructor" << std::endl;
}

Cat::~Cat(){std::cout << "\033[34m" << "Cat"<< "\033[0m" << "\t\tDefault destructor" << std::endl;}

Cat::Cat(Cat const &klas)
{
	*this = klas;
	std::cout << "\033[34m" << "Cat"<< "\033[0m" << "\t\tCopy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &klas)
{
	std::cout << "\033[34m" << "Cat"<< "\033[0m" << "\t\tAssignation constructor" << std::endl;
	this->type = klas.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "\033[33m" << "Sound"<< "\033[0m" << "\t\tMeow" << std::endl;
}