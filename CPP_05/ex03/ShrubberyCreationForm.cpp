#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form()	
{
	std::cout << "<\x1b[32m" << "ShrubberyCreationForm" << "\x1b[0m>\t\t\t" << "constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form("ShrubberyCreationForm", 145, 137, target)	
{
	std::cout << "<\x1b[32m" << "ShrubberyCreationForm" << "\x1b[0m>\t\t\t" << "constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):Form(copy)
{
	std::cout << "<\x1b[32m" << "ShrubberyCreationForm" << "\x1b[0m>\t\t\t" << "copy" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "<\x1b[32m" << "ShrubberyCreationForm" << "\x1b[0m>\t\t\t" << "destructor" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &f)
{
	if (this == &f)
		return (*this); 
	Form::operator=(f);
	return (*this);
}

void	ShrubberyCreationForm::executedAll(void) const
{
	std::string file(getTarget() + "_shrubbery");
	std::ofstream outf(file);
	std::cout << "Completed form " << "\x1b[33m" << this->getName() << "\x1b[0m" << "\n";
	std::cout << this->getTarget() << "..." << "\n";
	if (!outf)
	{
		std::cout << "File not be opened for writing!" << "\n";
		std::exit(1);
	}
	outf << "    &&&&&&&      &&&&&&&&    &&&&  .   &&&   ;  &&\n";
	outf << " &&&  .&  &&&   &&&  .  &&&&   &&   ;%     ;;  &&&&\n";
	outf << " &&&&   ,   &&&&&   ,  &&&&&&&&&&    :;%  %;  &&&&\n";
	outf << "  &&&&   :    &    ;   &&&&&&     &&   :;%;' &&  ., &\n";
	outf << ",.  &&&   %;     %;   &&&&&    ;   &&   %;'    ,;  &&\n";
	outf << "  ;   &   ;%;  %%;        ,     %;    ;%;    ,%'  &&&\n";
	outf << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'  &&&\n";
	outf << " &  ;%;      %;        ;%;        % ;%;  ,%;'  &&&\n";
	outf << " &&  `%;.     ;%;     %;'         `;%%;.%;'  &&&\n";
	outf << " &&&  `:;%.    ;%%. %@;        %; ;@%;%'  &&&\n";
	outf << " &&&&&&  `:%;.  :;bd%;          %;@%;'  &&&\n";
	outf << "  &&& &&&  `@%:.  :;%.         ;@@%;'  &&\n";
	outf << "  &&  && &&  `@%.  `;@%.      ;@@%;  &&&\n";
	outf << "    &&&&  &&&  `@%%. `@%%    ;@@%;  &&\n";
	outf << "      &&&&&&&&   ;@%. :@%%  %@@%; &&\n";
	outf << "        &&&&&&&&   %@bd%%%bd%%:;\n";
	outf << "            &&&&&&   #@%%%%%:;;\n";
	outf << "                &&&  %@@%%%::;\n";
	outf << "                     %@@@%(o);  . '\n";
	outf << "                     %@@@o%;:(.,'\n";
	outf << "                 `.. %@@@o%::;\n";
	outf << "                    `)@@@o%::;\n";
	outf << "                     %@@(o)::;\n";
	outf << "                    .%@@@@%::;\n";
	outf << "                    ;%@@@@%::;.\n";
	outf << "                   ;%@@@@%%:;;;.\n";
	outf << "               ...;%@@@@@%%:;;;;,..\n";
	outf << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	outf.close();
}
