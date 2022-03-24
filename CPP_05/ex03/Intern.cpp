#include "Intern.hpp"

static Form	*createShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static Form	*createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*createRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

Intern::Intern(void)
{
	std::cout << "<\x1b[32m" << "Intern" << "\x1b[0m>\t\t\t\t" << "constructor" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "<\x1b[32m" << "Intern" << "\x1b[0m>\t\t\t" << "copy" << std::endl;
	*this = copy;
}

Intern::~Intern(void)
{
	std::cout << "<\x1b[32m" << "Intern" << "\x1b[0m>\t\t\t\t" << "destructor" << std::endl;
}

Intern &Intern::operator=(const Intern &i)
{
	if (this == &i)
		return (*this); 
	return (*this);
}

Form	*Intern::makeForm(std::string const &nameForm, std::string const &target)
{
	Form* (*f[])(std::string const &target) = {&createShrubberyCreationForm,
											   &createPresidentialPardonForm,
											   &createRobotomyRequestForm};

	std::string	str[] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	int	i = 0;
	for (; i < 4 && nameForm != str[i]; ++i){}
	for (int j = i; j < 4; j++)
	{
		std::cout << nameForm << " create" << std::endl;
		return (f[i](target));
	}
	std::cout << nameForm << " no valid" << std::endl;
	return (NULL);
}
