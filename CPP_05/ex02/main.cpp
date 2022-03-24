#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void print_revers(const std::string& str)
{
	std::cout << "\x1b[31m" << str << "\x1b[0m" << std::endl;
}

int main()
{
	std::cout << "__________________________________" << std::endl;
	std::cout << "______________Create______________" << std::endl;
	std::cout << "__________________________________" << std::endl;
	ShrubberyCreationForm	a1("tree.txt");
	RobotomyRequestForm		a2("Bender");
	PresidentialPardonForm	a3("Navalniy");

	Bureaucrat 				b1("Albert", 150);
	Bureaucrat 				b2("James", 140);
	Bureaucrat 				b3("Evan", 100);
	Bureaucrat 				b4("Karl", 60);
	Bureaucrat 				b5("Peter", 30);
	Bureaucrat 				b6("Mark", 10);
	Bureaucrat 				b7("Leader", 1);


	std::cout << "__________________________________" << std::endl;
	std::cout << "______________Print_______________" << std::endl;
	std::cout << "__________________________________" << std::endl << std::endl;

	std::cout << "_______________Form_______________" << std::endl;
	std::cout << a1 << std::endl;
	std::cout << a2 << std::endl;
	std::cout << a3 << std::endl << std::endl;

	std::cout << "___________Bureaucrat_____________" << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;
	std::cout << b5 << std::endl;
	std::cout << b6 << std::endl;
	std::cout << b7 << std::endl;


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
	b7.signForm(a1);
	b7.executeForm(a1);

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
	return 0;
}

