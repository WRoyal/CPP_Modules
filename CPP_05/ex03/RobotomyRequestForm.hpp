#ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm: public Form
{
	private:
		virtual	void	executedAll(void) const;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm(void);

	RobotomyRequestForm &operator=(const RobotomyRequestForm &f);
};

# endif
