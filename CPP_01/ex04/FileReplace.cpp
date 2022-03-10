#include "fileReplace.hpp"

FileReplace::FileReplace(const std::string& name): inFile(name), outFile(name + ".replace"){}

FileReplace::~FileReplace()
{
	outFile.close();
	inFile.close();
}

std::string FileReplace::strReplace(std::string buf, std::string s1, std::string s2)
{
	std::string	str = buf;

	std::size_t pointFnd = buf.find(s1);
	if (pointFnd != std::string::npos)
	{
		str = buf.substr(0, pointFnd);
		str += s2;
		str += buf.substr(pointFnd + s1.length(), buf.length());
	}
	return str;
}

int	FileReplace::openFile(char *argv[], std::string s1, std::string s2)
{
	std::string buf;

	if (this->inFile.good())
		while (getline(this->inFile, buf))
			outFile << strReplace(buf, s1, s2) << std::endl;
	else
	{
		this->outFile << "Error: Bad file :(" << std::endl;
		std::cout << "\033[31;1mError:\033[0m Bad file \033[33;1m:(\033[0m" << std::endl;
		return (1);
	}
	return 0;
}