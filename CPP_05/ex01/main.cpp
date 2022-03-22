#include "Bureaucrat.hpp"
#include "Form.hpp"

void prints(std::string name, int grade, int flag);

void prints(std::string name, int grade, int flag)
{
	Bureaucrat chel(name, grade);
	try
	{
		if (flag == 1)
		{
			std::cout << chel;
			chel.belowGrade();
			std::cout << chel;
			chel.belowGrade();
			std::cout << chel;
			chel.belowGrade();
			std::cout << chel;
		}
		else if (flag == -1)
		{
			std::cout << chel;
			chel.higherGrade();
			std::cout << chel;
			chel.higherGrade();
			std::cout << chel;
			chel.higherGrade();
			std::cout << chel;
		}
		else
			std::cout << chel;
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void test_form(std::string name, int grade, std::string nameForm, int gradeSigned, int count)
{
	int gradeDop = 123;
	try
	{
		Bureaucrat chel(name, grade);
		std::cout << chel << std::endl;
		Form form(nameForm, gradeSigned, gradeDop);
		for (int a = count; a > 0; a--)
			chel.getGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int main(void)
{
	prints("Bob", 2, -1);
	prints("Kent", 148, 1);
	prints("Roby", 140, 0);
	test_form("Lip", 5, "Form1", 5, 1);
}
