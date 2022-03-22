#include "Form.hpp"

Form::Form() : name("no")
{
	std::cout << "\033[32m" << "Form"<< "\033[0m" << "\t\t\tDefault constructor" << std::endl;
	int gradeSigned = 0;
	int gradeExecute = 0;

	if (gradeSigned)
		throw Form::GradeTooHighException();
	else if (gradeSigned > 150)
		throw Form::GradeTooLowException();
	if (gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeExecute > 150)
		throw Form::GradeTooLowException();

	this->sign = 0;
	this->gradeSigned = gradeSigned;
	this->gradeExecute = gradeExecute;
}

Form::~Form(){std::cout << "\033[32m" << name << "\033[0m" << "\t\t\tDefault destructor" << std::endl;}

Form::Form(Form const &klas)
{
	*this = klas;
	std::cout << "\033[32m" << "Form"<< "\033[0m" << "\t\t\tCopy constructor" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExecute) : name(name)
{
	std::cout << "\033[32m" << "Form"<< "\033[0m" << "\t\t\tConstructor" << std::endl;
	if (gradeSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150)
		throw Form::GradeTooHighException();
	if (gradeExecute < 1)
		throw Form::GradeTooLowException();
	else if (gradeExecute > 150)
		throw Form::GradeTooLowException();
	this->sign = 0;
	this->gradeSigned = gradeSign;
	this->gradeExecute = gradeExecute;
}

void	Form::beSigned(Bureaucrat const &klas)
{
	if (klas.getGrade() <= this->gradeSigned)
		this->sign = true;
	else
		throw Form::GradeTooLowException();
}

std::string const &Form::getName() const
{
	return this->name;
}

bool Form::getSign() const
{
	return this->sign;
}

int	Form::getGradeSigned() const
{
	return this->gradeSigned;
}

int	Form::getGradeExecute() const
{
	return this->gradeExecute;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("\033[31mhigh grade\033[0m");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("\033[31mClow grade\033[0m");
}

std::ostream &operator<<(std::ostream &out, Form const &klas)
{
	out
	<< "name\t\t: " << klas.getName() << "\n"
	<< "signed\t\t: " << klas.getSign() << "\n"
	<< "gradeSigned\t: " << klas.getGradeSigned() << "\n"
	<< "gradeExecute\t: " << klas.getGradeExecute() << "\n";
	return out;
}

Form &Form::operator=(const Form &klas)
{
	std::cout << "\033[32m" << "Form"<< "\033[0m" << "\t\t\tAssignation constructor" << std::endl;
	this->sign = klas.getSign();
	this->sign = klas.getGradeSigned();
	this->sign = klas.getGradeExecute();
	return (*this);
}