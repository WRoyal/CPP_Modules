#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("ShrubberyCreationForm", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: Form("ShrubberyCreationForm", 145, 137), _target(target)
{}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::setTarget(const std::string &target)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: Form("ShrubberyCreationForm", 145, 137), _target(other.getTarget())
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	setSigned(other.isSigned());
	_target = other.getTarget();
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw Form::FormNotSignedException("\033[33m" + getName() + "\033[0m" + " can't be executed because it isn't signed");
	if ((int)executor.getGrade() > getGradeExecuted())
		throw Bureaucrat::GradeTooLowException("\033[34m" + executor.getName() + "\033[0m" + "'s grade less than the form required");
	if (_target.empty())
		std::cout << "WARNING: form target isn't specified!" << "\n";
	std::ofstream out(_target + "_shrubbery");
	out << "    &&&&&&&      &&&&&&&&    &&&&  .   &&&   ;  &&\n";
	out << " &&&  .&  &&&   &&&  .  &&&&   &&   ;%     ;;  &&&&\n";
	out << " &&&&   ,   &&&&&   ,  &&&&&&&&&&    :;%  %;  &&&&\n";
	out << "  &&&&   :    &    ;   &&&&&&     &&   :;%;' &&  ., &\n";
	out << ",.  &&&   %;     %;   &&&&&    ;   &&   %;'    ,;  &&\n";
	out << "  ;   &   ;%;  %%;        ,     %;    ;%;    ,%'  &&&\n";
	out << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'  &&&\n";
	out << " &  ;%;      %;        ;%;        % ;%;  ,%;'  &&&&&\n";
	out << " &&  `%;.     ;%;     %;'         `;%%;.%;'  &&& &&\n";
	out << " &&&  `:;%.    ;%%. %@;        %; ;@%;%'  &&& &&&&\n";
	out << " &&&&&&  `:%;.  :;bd%;          %;@%;'  &&& &&&&\n";
	out << "  &&& &&&  `@%:.  :;%.         ;@@%;'  &&&&&&&\n";
	out << "  &&  && &&  `@%.  `;@%.      ;@@%;  &&&&&&&\n";
	out << "    &&&&  &&&  `@%%. `@%%    ;@@%;  &&&&&&&\n";
	out << "      &&&&&&&&   ;@%. :@%%  %@@%; &&&  &&\n";
	out << "        &&&&&&&&   %@bd%%%bd%%:; &&&&&&\n";
	out << "            &&&&&&   #@%%%%%:;; &&&&&\n";
	out << "                &&&  %@@%%%::; &&&\n";
	out << "                     %@@@%(o);  . '\n";
	out << "                     %@@@o%;:(.,'\n";
	out << "                 `.. %@@@o%::;\n";
	out << "                    `)@@@o%::;\n";
	out << "                     %@@(o)::;\n";
	out << "                    .%@@@@%::;\n";
	out << "                    ;%@@@@%::;.\n";
	out << "                   ;%@@@@%%:;;;.\n";
	out << "               ...;%@@@@@%%:;;;;,..\n";
	out << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	out.close();
}

