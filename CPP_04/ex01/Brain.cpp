#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[33;1m" << "Brain"<< "\033[0m" << "\t\tDefault constructor" << std::endl;
}

Brain::~Brain(){std::cout << "\033[33;1m" << "Brain"<< "\033[0m" << "\t\tDefault destructor" << std::endl;}

Brain::Brain(Brain const &klas)
{
	*this = klas;
	std::cout << "\033[33;1m" << "Brain"<< "\033[0m" << "\t\tCopy constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &klas)
{
	std::cout << "\033[33;1m" << "Brain"<< "\033[0m" << "\t\tAssignation constructor" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = klas.ideas[i];
	}
	return (*this);
}