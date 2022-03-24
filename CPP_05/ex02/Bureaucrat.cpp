#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Luke"), grade(1)
{
	std::cout << "\033[32m" << "Bureaucrat"<< "\033[0m" << "\t\tDefault constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(){std::cout << "\033[32m" << "Bureaucrat"<< "\033[0m" << "\t\tDefault destructor" << std::endl;}

Bureaucrat::Bureaucrat(Bureaucrat const &klas)
{
	const_cast<std::string&>(this->name) = klas.name;
	grade = klas.grade;
}

Bureaucrat::Bureaucrat(std::string const &nam, int grad) : name(nam)
{
	if (grad > 150 || grad < 1)
		std::cout << "Bureaucrat creation failed: ";
	if (grad > 150)
		throw Bureaucrat::GradeTooLowException("Grade exceeds the valid value");
	else if (grad < 1)
		throw Bureaucrat::GradeTooHighException("Grade less then the valid value");
	grade = grad;
	std::cout << "Creation bureaucrat " + nam << std::endl;
}

std::string const &Bureaucrat::getName() const
{
	return this->name;
}

unsigned int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::higherGrade()
{
	if (--this->grade < 1)
		throw GradeTooHighException("Grade higher exception");
}

void Bureaucrat::belowGrade()
{
	if (++this->grade > 150)
		throw GradeTooLowException("Grade exceeds the valid value");
}

void Bureaucrat::signForm(Form &form)
{
	if (form.isSigned() == true)
		std::cerr << "Bureaucrat " << "\033[34m" << name << "\033[0m" << " cannot sign form " << "\033[33m" << form.getName() << "\033[0m"
		<< " because: it's is signed" << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->name << " signs " << form.getName() << std::endl;
		}
		catch (std::exception &err)
		{
			std::cout << this->name << " not sign " << form.getName() << " because:" << std::endl;
			std::cout << err.what() << std::endl;
		}
	}
}

void	Bureaucrat::executeForm(Form &form) const
{
	try
	{
		form.execute(*this);
		std::cout << "Form " << "\033[33m" << form.getName() << "\033[0m" << " was executed by bureaucrat " << "\033[34m" << getName() << "\033[0m" << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << '\n';
	}
	
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &klas)
{
	if (this == &klas)
		return *this;
	const_cast<std::string&>(name) = klas.getName();
	grade = klas.getGrade();
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const &errmsg) : errmsg(errmsg) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (std::string("GradeTooHighException: " + errmsg)).c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const &errmsg) : errmsg(errmsg) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (std::string("GradeTooLowException: " + errmsg)).c_str();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &klas)
{
	out << klas.getName() << ". Grade: " << klas.getGrade() << "\n";
	return out;
}