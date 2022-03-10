#include "Karen.hpp"

void Karen::debug(void)
{
	std::cout << "\033[34;1mDebug:\033[0m";
	std::cout << " I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Karen::info(void)
{
	std::cout << "\033[32;1mInfo:\033[0m";
	std::cout << " I cannot believe adding extra bacon costs more money." << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "\033[33;1mWarning:\033[0m";
	std::cout << " I think I deserve to have some extra bacon for free." << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Karen::error(void)
{
	std::cout << "\033[31;1mError:\033[0m";
	std::cout << " This is unacceptable! I want to speak to the manager now." << std::endl;
}

typedef void (Karen::*ptrLvl)(void);

void	Karen::complain(std::string level)
{
	int a = 0;
	ptrLvl mas[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string cases[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (a < 4)
	{
		if (cases[a] == level)
			break;
		a++;
	}

	switch (a)
	{
		case 0:
			(this->*(mas[0]))();
			break;
		case 1:
			(this->*(mas[1]))();
			break;
		case 2:
			(this->*(mas[2]))();
			break;
		case 3:
			(this->*(mas[3]))();
			break;
		
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}