#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Vladiput")
{
	std::cout << "<\x1b[32m" << "Bureaucrat" << "\x1b[0m>\t\t\t" << "Default constructor called " << "\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	std::cout << "Created bureaucrat " + _name << "\n";

	if (grade > 150)
		throw Bureaucrat::GradeTooLowException(this->_name + " constructor error");
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException(this->_name + " constructor error");

	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bur)
{
	*this = bur;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "<\x1b[32mBureaucrat\x1b[0m>\t\t\t\t" + _name + " destructed" << "\n";
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::higherGrade(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException("Grade higher exception");
	else
		this->_grade = this->_grade - 1;
	return ;
}

void	Bureaucrat::belowGrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException("Grade exceeds the valid value");
	else
		this->_grade = this->_grade + 1;
	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bur)
{
	if (this == &bur)
		return (*this);
	const_cast<std::string&>(this->_name) = bur.getName();
	this->_grade = bur.getGrade();
	return (*this);
}

void	Bureaucrat::signForm(Form &f)
{
	if (f.getSigned() == true)
		std::cerr << "Bureaucrat " << "\033[34m" << _name << "\033[0m" << " cannot sign form " << "\033[33m" << f.getName() << "\033[0m"
		<< " because: it's is signed" << "\n";
	else
	{
		try
		{
			f.beSigned(*this);
			std::cout << "\033[34m" << _name << "\033[0m" << " signs " << "\033[33m" << f.getName() << "\033[0m" << "\n";
		}
		catch (std::exception &e)
		{
			std::cout << "\033[34m" << _name << "\033[0m" << " can not sign form " << "\033[33m" << f.getName() << "\033[0m" << " because: ";
			std::cout << e.what() << std::endl;
		}
	}
	return ;
}

void	Bureaucrat::executeForm(Form const &f)
{
	try
	{
		f.execute(*this);
		std::cout << "Form " << "\033[33m" << f.getName() << "\033[0m" << " was executed by bureaucrat " << "\033[34m" << getName() << "\033[0m" << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[31m" << "Execution error: " << "\033[0m" << e.what() << "\n";
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

//exception
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &e)
{
	std::cout << "<\x1b[32m" << "GradeTooHighException" << "\x1b[0m>\t\t\t" << "constructor" << std::endl;
	this->_err = e;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "<\x1b[32m" << "GradeTooHighException" << "\x1b[0m>\t\t\t" << "destructor" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ((std::string("GradeTooHighException " + this->_err)).c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &e)
{
	std::cout << "<\x1b[32m" << "GradeTooLowException" << "\x1b[0m>\t\t\t" << "constructor" << std::endl;
	this->_err = e;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "<\x1b[32m" << "GradeTooLowException" << "\x1b[0m>\t\t\t" << "destructor" << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ((std::string("GradeTooLowException " + this->_err)).c_str());
}
