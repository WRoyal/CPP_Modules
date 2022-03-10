#include "Karen.hpp"

int main (int argc, char *argv[])
{
	Karen karen;

	if (argc == 2)
	{
		karen.complain(argv[1]);
		return 0;
	}
	std::cout << "\033[31;1mError: Number of arguments, needs 2!!!\033[0m" << std::endl;

	return 0;
}