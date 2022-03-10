#include <iostream>

int main ()
{
	std::string	brain = "HI, THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "Name        |      MemAddr     |         Value" << std::endl;
	std::cout << "------------|------------------|----------------------" << std::endl;
	std::cout << "\x1b[36;1mString\x1b[0m      |  \033[33m" << &brain << "\033[0m  |   \033[32m" << brain << "\033[0m" << std::endl;
	std::cout << "\x1b[36;1mPointer\x1b[0m     |  \033[33m" << &stringPTR << "\033[0m  |   \033[32m" << *stringPTR << "\033[0m" << std::endl;
	std::cout << "\x1b[36;1mReference\x1b[0m   |  \033[33m" << &stringREF << "\033[0m  |   \033[32m" << stringREF << "\033[0m" << std::endl;
}