#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void print_revers(std::string str);

int main (void)
{
	std::cout << "__________________________________" << std::endl;
	std::cout << "______________Create______________" << std::endl;
	std::cout << "__________________________________" << std::endl;

	Intern a;

	Form &a1 = *a.makeForm("shrubbery creation", "tree.txt");
	Form &a2 = *a.makeForm("robotomy request", "Bender");
	Form &a3 = *a.makeForm("presidential pardon", "Navalniy");
	Form &a4 = *a.makeForm("noooooooo", "yes");

	Bureaucrat 				b1("Albert De Salvo", 150);
	Bureaucrat 				b2("James Olmos Cunningham", 140);
	Bureaucrat 				b3("Evan Redgrave", 100);
	Bureaucrat 				b4("Pete Fergusson", 60);
	Bureaucrat 				b5("Peter Dong", 30);
	Bureaucrat 				b6("Rose Everdeen", 10);
	Bureaucrat 				b7("Leader", 1);

	std::cout << "__________________________________" << std::endl;
	std::cout << "______________Print_______________" << std::endl;
	std::cout << "__________________________________" << std::endl;
	std::cout << a1 << std::endl << a2 << std::endl << a3 << &a4 << std::endl;
	std::cout << b1 << std::endl << b2 << std::endl << b3 << std::endl
	<< b4 << std::endl << b5 << std::endl << b6 << std::endl << b7 << std::endl;
	std::cout << "__________________________________" << std::endl;
	std::cout << "________ShrubberyCreationForm_____" << std::endl;
	std::cout << "__________________________________" << std::endl;
	print_revers("Test1");
	b1.signForm(a1);
	b1.executeForm(a1);
	print_revers("Test2");
	b2.signForm(a1);
	b2.executeForm(a1);
	print_revers("Test3"); // file
	b3.signForm(a1);
	b3.executeForm(a1);
	std::cout << "__________________________________" << std::endl;
	std::cout << "______RobotomyRequestForm_________" << std::endl;
	std::cout << "__________________________________" << std::endl;
	print_revers("Test4");
	b3.signForm(a2);
	b3.executeForm(a2);
	print_revers("Test5");
	b4.signForm(a2);
	b4.executeForm(a2);
	print_revers("Test6"); //random
	b5.signForm(a2);
	b5.executeForm(a2);
	std::cout << "__________________________________" << std::endl;
	std::cout << "______PresidentialPardonForm______" << std::endl;
	std::cout << "__________________________________" << std::endl;
	print_revers("Test7");
	b5.signForm(a3);
	b5.executeForm(a3);
	print_revers("Test8");
	b6.signForm(a3);
	b6.executeForm(a3);
	print_revers("Test9"); // good
	b7.signForm(a3);
	b7.executeForm(a3);
	std::cout << "__________________________________" << std::endl;
	std::cout << "______________del_________________" << std::endl;
	std::cout << "__________________________________" << std::endl;
	delete &a1;
	delete &a2;
	delete &a3;
	delete &a4;

	// std::string str;
	// std::getline(std::cin, str);

	return (0);
}

void print_revers(std::string str)
{
	std::cout << "\033[31m" << str << "\033[0m" << std::endl;
}
