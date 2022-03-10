#include "fileReplace.hpp"

int main (int argc, char *argv[])
{
	if (argc == 4)
	{
		FileReplace files(argv[1]);

		std::string s1(argv[2]);
		std::string s2(argv[3]);
		if (!files.openFile(argv, s1, s2))
			std::cout << "\033[32;1mFinished!\033[0m" << std::endl;
		return (0);
	}
	std::cout << "\033[31;1mError:\033[0m Number of arguments, needs 3!!!" << std::endl;
	return 0;
}