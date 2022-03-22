#include "Bureaucrat.hpp"

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


int main(void)
{
	prints("Bob", 2, -1);
	prints("Bob", 148, 1);
	prints("Bob", 140, 0);
}
