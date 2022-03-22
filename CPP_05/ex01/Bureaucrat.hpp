#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "Form.hpp"

class Bureaucrat;
class Form;

class Bureaucrat
{
private:
	std::string	name;
	int grade;
	Bureaucrat() {};

public:
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &klas);
	Bureaucrat(std::string name, int grade);
	Bureaucrat &operator=(const Bureaucrat &klas);

	std::string const &getName() const;
	int	getGrade() const;

	void higherGrade();
	void belowGrade();
	void signForm(Form &form);

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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &klas);

#endif