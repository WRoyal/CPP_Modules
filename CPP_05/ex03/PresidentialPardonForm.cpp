#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form()	
{
	std::cout << "<\x1b[32m" << "PresidentialPardonForm" << "\x1b[0m>\t\t\t" << "constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form("PresidentialPardonForm", 25, 5, target)	
{
	std::cout << "<\x1b[32m" << "PresidentialPardonForm" << "\x1b[0m>\t\t" << "constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):Form(copy)
{
	std::cout << "<\x1b[32m" << "PresidentialPardonForm" << "\x1b[0m>\t\t\t" << "copy" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "<\x1b[32m" << "PresidentialPardonForm" << "\x1b[0m>\t\t" << "destructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &f)
{
	if (this == &f)
		return (*this); 
	Form::operator=(f);
	return (*this);
}

void	PresidentialPardonForm::executedAll(void) const
{
	std::cout << this->getTarget() << ": has been pardoned by Zafod Beeblebrox." << std::endl;
}
