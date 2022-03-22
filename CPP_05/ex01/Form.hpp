#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				sign;
	int					gradeSigned;
	int					gradeExecute;

public:
	Form();
	~Form();
	Form(std::string name, int gradeSign, int gradeExecute);
	Form &operator=(const Form &klas);
	Form(Form const &klas);

	std::string const	&getName() const;
	bool				getSign() const;
	int					getGradeSigned() const;
	int					getGradeExecute() const;

	void	beSigned(Bureaucrat const &klas);

	class GradeTooHighException : public std::exception
	{
	private:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &klas);

#endif