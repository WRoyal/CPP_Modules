#include "Form.hpp"

Form::Form():_name("(no)")
{
	int	gradeSigned = 0;
	int	gradeDo = 0;

	if (gradeSigned > 150)
		throw Form::GradeTooLowException(this->_name + " Constructor error");
	else if (gradeSigned < 1)
		throw Form::GradeTooHighException(this->_name + " Constructor error");
	if (gradeDo > 150)
		throw Form::GradeTooLowException(this->_name + " Constructor error");
	else if (gradeDo < 1)
		throw Form::GradeTooHighException(this->_name + " Constructor error");

	this->_signed = 0;
	this->_gradeSigned = gradeSigned;
	this->_gradeDo = gradeDo;
}

Form::Form(std::string name, int gradeSigned, int gradeDo, std::string target):_name(name)
{
	std::cout << "<\x1b[32m" << this->_name << " (Form)" << "\x1b[0m>\t\t" << "constructor" << std::endl;

	if (gradeSigned > 150)
		throw Form::GradeTooLowException(this->_name + " Constructor error");
	else if (gradeSigned < 1)
		throw Form::GradeTooHighException(this->_name + " Constructor error");
	if (gradeDo > 150)
		throw Form::GradeTooLowException(this->_name + " Constructor error");
	else if (gradeDo < 1)
		throw Form::GradeTooHighException(this->_name + " Constructor error");

	this->_signed = 0;
	this->_gradeSigned = gradeSigned;
	this->_gradeDo = gradeDo;
	this->_target = target;
}

Form::Form(Form const &f)
{
	std::cout << "(Form) copy" << std::endl;
	*this = f;
}

Form::~Form(void)
{
	std::cout << "<\x1b[32m" << this->_name << " (Form)" << "\x1b[0m>\t\t" << "destructor" << std::endl;
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getGradeSigned(void) const
{
	return (this->_gradeSigned);
}

int	Form::getGradeDo(void) const
{
	return (this->_gradeDo);
}

const std::string	&Form::getTarget(void) const
{
	return (this->_target);
}

void	Form::beSigned(const Bureaucrat &bur)
{
	if (this->_gradeSigned >= bur.getGrade())
		this->_signed = true;
	else
		throw Form::GradeTooLowException("below grade");
}

void	Form::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
		std::cout << "Form no execute because: no signed" << std::endl;
	else
	{
		if (executor.getGrade() > this->_gradeDo)
			throw Form::GradeTooLowException("below grade");
		else
		{
			std::cout << executor.getName() << " execute " << _name << std::endl;
			this->executedAll();
		}
	}
}

Form	&Form::operator=(const Form &f)
{
	if (this == &f)
		return (*this);
	const_cast<std::string&>(this->_name) = f.getName();
	this->_signed = f.getSigned();
	this->_gradeSigned = f.getGradeSigned();
	this->_gradeDo = f.getGradeDo();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out
	<< "name       : " << f.getName() << std::endl
	<< "signed     : " << f.getSigned() << std::endl
	<< "gradeSigned: " << f.getGradeSigned() << std::endl
	<< "gradeDo    : " << f.getGradeDo() << std::endl
	<< "target     : " << f.getTarget() << std::endl;

	return (out);
}

//exception
Form::GradeTooHighException::GradeTooHighException(const std::string &e)
{
	std::cout << "<\x1b[32m" << "GradeTooHighException" << "\x1b[0m>\t\t\t" << "constructor" << std::endl;
	this->_err = e;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "<\x1b[32m" << "GradeTooHighException" << "\x1b[0m>\t\t\t" << "destructor" << std::endl;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ((std::string("GradeTooHighException " + this->_err)).c_str());
}

Form::GradeTooLowException::GradeTooLowException(const std::string &e)
{
	std::cout << "<\x1b[32m" << "GradeTooLowException" << "\x1b[0m>\t\t\t" << "constructor" << std::endl;
	this->_err = e;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "<\x1b[32m" << "GradeTooLowException" << "\x1b[0m>\t\t\t" << "destructor" << std::endl;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ((std::string("GradeTooLowException " + this->_err)).c_str());
}
