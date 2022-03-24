#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string	name;
	unsigned grade;
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &klas);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat &operator=(const Bureaucrat &klas);
	std::string const &getName() const;
	unsigned int getGrade() const;
	void higherGrade();
	void belowGrade();
	void signForm(Form &form);
	void executeForm(Form &form) const;
	~Bureaucrat();

	class GradeTooHighException : public std::exception
	{
	private:
		std::string errmsg;
	public:
		explicit GradeTooHighException(std::string const &err);
		~GradeTooHighException() throw();
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		std::string errmsg;
	public:
		explicit GradeTooLowException(std::string const &err);
		~GradeTooLowException() throw();
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &klas);

#endif