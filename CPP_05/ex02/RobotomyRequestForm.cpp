#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", 72, 45)
{}

const std::string &RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::setTarget(const std::string &target)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: Form("RobotomyRequestForm", 72, 45), _target(other.getTarget())
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	setSigned(other.isSigned());
	_target = other.getTarget();
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw Form::FormNotSignedException("\033[33m" + getName() + "\033[0m" + " can't be executed because it isn't signed");
	if ((int)executor.getGrade() > getGradeExecuted())
		throw Bureaucrat::GradeTooLowException("\033[34m" + executor.getName() + "\033[0m" + "'s grade less than the form required");
	if (_target.empty())
		std::cout << "WARNING: form target isn't specified!" << "\n";
	std::cout << '\a' << std::flush;
	std::srand(std::time(nullptr));
	if (std::rand() % 2)
		std::cout << "\033[35m" << _target << "\033[0m" << " has been robotomized successfully." << "\n";
	else
		std::cout << "\033[35m" << _target << "\033[0m" << " has been NOT robotic successfully" << "\n";
}

