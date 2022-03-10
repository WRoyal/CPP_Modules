#ifndef FILEREPLACE_HPP
# define FILEREPLACE_HPP

#include <iostream>
#include <fstream>

class FileReplace
{
private:
	std::ifstream inFile;
	std::ofstream outFile;
public:
	FileReplace(const std::string& iName);
	~FileReplace();

	int	openFile(char *argv[], std::string s1, std::string s2);
	std::string strReplace(std::string buf, std::string s1, std::string s2);
};

#endif