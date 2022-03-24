#include "Form.hpp"

Form::Form(const std::string &name, bool _signed, const int gradeSigned, const int gradeExecuted) :
		   name(name), _signed(_signed), gradeSigned(gradeSigned), gradeExecuted(gradeExecuted)
{
	checkGrades();
}

Form::Form(const std::string &name, const int gradeSigned, const int gradeExecuted)
		: name(name), _signed(false), gradeSigned(gradeSigned), gradeExecuted(gradeExecuted)
{
	checkGrades();
}

void Form::checkGrades()
{
	if (gradeExecuted > 150 || gradeExecuted < 1  || gradeSigned > 150 || gradeSigned < 1)
		std::cout << "Form creation failed: ";
	if (gradeExecuted > 150 || gradeSigned > 150)
		throw Bureaucrat::GradeTooLowException("Grade exceeds the valid value");
	else if (gradeExecuted < 1 || gradeSigned < 1)
		throw Bureaucrat::GradeTooHighException("Grade less than the valid value");
	std::cout << "Form " + name + " created" << "\n";
}

const std::string &Form::getName() const
{
	return name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getGradeSigned() const
{
	return gradeSigned;
}

int Form::getGradeExecuted() const
{
	return gradeExecuted;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if ((int)bureaucrat.getGrade() <= gradeSigned)
		_signed = true;
	else
	{
		std::cout << "Try to sign form " << "\033[33m" << name << "\033[0m" << "\033[31m" << " failed!" << "\033[0m" << "\n";
		throw Bureaucrat::GradeTooHighException("\033[34m" + bureaucrat.getName() + "\033[0m" + "'s grade less than the form required");
	}
}

Form::~Form()
{
	std::cout << "<\x1b[32m" << this->name << "\x1b[0m>\t\t\t" << "Destructor called" << "\n";
}

Form::Form(const Form &other) :
	name(other.getName()) , _signed(other.isSigned()), gradeSigned(other.getGradeSigned()),
	gradeExecuted(other.getGradeExecuted())
{}

Form &Form::operator=(const Form &other)
{
	const_cast<std::string &>(name) = other.getName();
	const_cast<int &>(gradeSigned) = other.getGradeSigned();
	const_cast<int &>(gradeExecuted) = other.getGradeExecuted();
	_signed = other.isSigned();
	return *this;
}

void Form::setSigned(bool signed_)
{
	_signed = signed_;
}

Form::Form() : gradeSigned(150), gradeExecuted(150)
{
	std::cout << "<\x1b[32m" << "Form" << "\x1b[0m>\t\t\t" << "Default constructor called" << "\n";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out
			<< "name\t\t: " << form.getName() << "\n"
			<< "signed\t\t: " << form.isSigned() << "\n"
			<< "gradeSigned\t: " << form.getGradeSigned() << "\n"
			<< "gradeExecute\t: " << form.getGradeExecuted() << "\n";

	return out;
}

Form::FormNotSignedException::FormNotSignedException(const std::string &errmsg) : errmsg(errmsg) {}

const char *Form::FormNotSignedException::what() const throw()
{
	return ("FormNotSignedException: " + errmsg).c_str();
}
