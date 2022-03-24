#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form()	
{
	std::cout << "<\x1b[32m" << "RobotomyRequestForm" << "\x1b[0m>\t\t\t" << "constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): Form("RobotomyRequestForm", 72, 45, target)	
{
	std::cout << "<\x1b[32m" << "RobotomyRequestForm" << "\x1b[0m>\t\t\t" << "constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): Form(copy)
{
	std::cout << "<\x1b[32m" << "RobotomyRequestForm" << "\x1b[0m>\t\t\t" << "copy" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "<\x1b[32m" << "RobotomyRequestForm" << "\x1b[0m>\t\t\t" << "destructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &f)
{
	if (this == &f)
		return (*this); 
	Form::operator=(f);
	return (*this);
}

void	RobotomyRequestForm::executedAll(void) const
{
	srand(time(NULL));
	if((rand() % 2) == 0)
		std::cout << this->getTarget() << ": successfully" << std::endl;
	else
		std::cout << this->getTarget() << ": no successfully" << std::endl;
}
