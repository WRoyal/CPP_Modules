#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include <exception>

# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat(void);
		Bureaucrat(std::string, int num);
		Bureaucrat(Bureaucrat const &bur);
		~Bureaucrat(void);

		const std::string	&getName(void) const;
		int					getGrade(void) const;

		void				higherGrade(void);
		void				belowGrade(void);

		void				signForm(Form &f);
		void				executeForm(Form const &f);

		Bureaucrat			&operator=(Bureaucrat const &bur);

		class GradeTooHighException: public std::exception
		{
			private:
					std::string _err;
			public:
					GradeTooHighException(const std::string &e);
					~GradeTooHighException() throw();

					const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			private:
					std::string _err;
			public:
					GradeTooLowException(const std::string &e);
					~GradeTooLowException() throw();

					const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur);

# endif
