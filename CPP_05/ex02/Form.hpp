#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool _signed;
	const int gradeSigned;
	const int gradeExecuted;
	void checkGrades();

protected:
	void setSigned(bool _signed);

public:
	Form();
	Form(const std::string &name, int gradeSigned, int gradeExecuted);
	Form(const std::string &name, bool _signed, int gradeSigned, int gradeExecuted);
	const std::string &getName() const;
	virtual ~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	bool isSigned() const;
	int getGradeSigned() const;
	int getGradeExecuted() const;
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	class FormNotSignedException : public std::exception
	{
		private:
			std::string errmsg;
		public:
			FormNotSignedException(const std::string &errmsg);
			const char *what() const throw();
			virtual ~FormNotSignedException() throw() {};
	};
};

std::ostream &operator<<(std::ostream &out, Form const &klas);

#endif