#include "Bureaucrat.hpp"

// Bureaucrat::Bureaucrat()
// {
// 	std::cout << "\033[32m" << "Bureaucrat"<< "\033[0m" << "\t\tDefault constructor" << std::endl;
// 	this->type = "Bureaucrat";
// }

Bureaucrat::~Bureaucrat(){std::cout << "\033[32m" << "Bureaucrat"<< "\033[0m" << "\t\tDefault destructor" << std::endl;}

Bureaucrat::Bureaucrat(Bureaucrat const &klas)
{
	*this = klas;
	std::cout << "\033[32m" << "Bureaucrat"<< "\033[0m" << "\t\tCopy constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "\033[32m" << "Bureaucrat"<< "\033[0m" << "\t\tConstructor" << std::endl;
	this->name = name;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

std::string const &Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::higherGrade()
{
	if (--this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::belowGrade()
{
	if (++this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[31mConstructor error\033[0m");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[31mConstructor error\033[0m");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &klas)
{
	out << klas.getName() << ". Grade: " << klas.getGrade() << "\n";
	return out;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &klas)
{
	std::cout << "\033[32m" << "Bureaucrat"<< "\033[0m" << "\t\tAssignation constructor" << std::endl;
	this->name = klas.name;
	return (*this);
}