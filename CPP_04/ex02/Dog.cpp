#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), dogBrain(new Brain())
{
	std::cout << "\033[36m" << "Dog"<< "\033[0m" << "\t\tDefault constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "\033[36m" << "Dog"<< "\033[0m" << "\t\tDefault destructor" << std::endl;
	delete this->dogBrain;
}

Dog::Dog(Dog const &klas)
{
	*this = klas;
	std::cout << "\033[36m" << "Dog"<< "\033[0m" << "\t\tCopy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &klas)
{
	std::cout << "\033[36m" << "Dog"<< "\033[0m" << "\t\tAssignation constructor" << std::endl;
	this->type = klas.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "\033[33m" << "Sound"<< "\033[0m" << "\t\tWoof" << std::endl;
}