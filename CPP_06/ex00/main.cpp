#include "Converter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2 || (argc == 2 && argv[1][0] == 0))
	{
		std::cout << "ERROR: Expected one argument" << "\n";
		return (0);
	}
	try
	{
		// std::cout << "aasdasdfadf\n";
		Converter converter(argv[1]);
		std::cout << converter << "\n";
	}
	catch (std::string str)
	{
		std::cout << str << "\n";
	}
	return (0);
}

