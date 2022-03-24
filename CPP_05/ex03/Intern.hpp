#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		virtual ~Intern(void);

		Form*	makeForm(std::string const &nameForm, std::string const &target);

		Intern	&operator=(const Intern &i);

};

# endif
